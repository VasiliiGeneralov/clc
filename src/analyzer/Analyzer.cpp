#include <stack>
#include <string>
#include <vector>

#include "Analyzer.hpp"

Analyzer& Analyzer::get()
{
  static Analyzer a;
  return a;
}

double Analyzer::analyze(const std::vector<std::string>& v)
{
  std::stack<double> s;
  for (std::size_t i = 0; i < v.size(); ++i) {
    std::string token = v.at(i);
    if ("+" == token) {
      double right = s.top();
      s.pop();
      double left = s.top();
      s.pop();
      s.push(left + right);
      continue;
    }
    if ("-" == token) {
      double right = s.top();
      s.pop();
      double left = s.top();
      s.pop();
      s.push(left - right);
      continue;
    }
    if ("*" == token) {
      double right = s.top();
      s.pop();
      double left = s.top();
      s.pop();
      s.push(left * right);
      continue;
    }
    if ("/" == token) {
      double right = s.top();
      s.pop();
      double left = s.top();
      s.pop();
      s.push(left / right);
      continue;
    }
    if (!token.empty()) {
      s.push(Analyzer::get().create(token));
    }
  }
  return s.top();
}

double Analyzer::create(const std::string& s)
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
  }
  return sign * (static_cast<double>(whole) + frac);
}
