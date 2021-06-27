#include <string>
#include <tuple>
#include <vector>

#include "Analyzer.hpp"

Analyzer& Analyzer::get()
{
  static Analyzer a;
  return a;
}

std::tuple<bool, int, double> Analyzer::analyze(const std::vector<std::string>& v)
{
  return Analyzer::get().traverse(v.begin(), v.end() - 1);
}

std::tuple<bool, int, double> Analyzer::traverse(std::vector<std::string>::const_iterator first,
                                                 std::vector<std::string>::const_iterator last)
{
  if ("+" == *last) {
    if (floatMode) {
      return std::tuple(floatMode, 0, std::get<2>(traverse(first, last - 2)) + std::get<2>(traverse(first, last - 1)));
    }
    return std::tuple(floatMode, std::get<1>(traverse(first, last - 2)) + std::get<1>(traverse(first, last - 1)), 0);
  }
  if ("-" == *last) {
    if (floatMode) {
      return std::tuple(floatMode, 0, std::get<2>(traverse(first, last - 2)) - std::get<2>(traverse(first, last - 1)));
    }
    return std::tuple(floatMode, std::get<1>(traverse(first, last - 2)) - std::get<1>(traverse(first, last - 1)), 0);
  }
  if ("*" == *last) {
    if (floatMode) {
      return std::tuple(floatMode, 0, std::get<2>(traverse(first, last - 2)) * std::get<2>(traverse(first, last - 1)));
    }
    return std::tuple(floatMode, std::get<1>(traverse(first, last - 2)) * std::get<1>(traverse(first, last - 1)), 0);
  }
  if ("/" == *last) {
    if (!floatMode) {
      floatMode = true;
    }
    return std::tuple(floatMode, 0, std::get<2>(traverse(first, last - 2)) / std::get<2>(traverse(first, last - 1)));
  }
  return create(*last);
}

std::tuple<bool, int, double> Analyzer::create(const std::string& s)
{
  std::size_t i{0};
  int sign{1};
  if ('-' == s.at(0)) {
    sign = -1;
    ++i;
  }
  int order{10};
  int whole{0};
  bool isFloat{false};
  for (; i < s.size(); ++i) {
    char c = s.at(i);
    if ('.' == c || ',' == c) {
      isFloat = true;
      break;
    }
    whole = order*whole + (c - '0');
  }
  double frac{0};
  if (isFloat) {
    order = 10;
    ++i;
    for (; i < s.size(); ++i) {
      char c = s.at(i);
      frac += (static_cast<double>(c - '0') / order);
      order *= 10;
    }
    if (!floatMode) {
      floatMode = true;
    }
  }
  return std::tuple(floatMode, sign * whole, static_cast<double>(sign * whole) + frac);
}
