#include <stdexcept>
#include <vector>
#include <string>

#include "Tokenizer.hpp"

Tokenizer& Tokenizer::get()
{
  static Tokenizer t;
  return t;
}

bool Tokenizer::verify(const std::string& s)
{
  return checkSymbols(s) && checkParenthesis(s);
}

bool Tokenizer::checkSymbols(const std::string& s)
{
  bool result{true};
  std::size_t pos{0};
  try {
    char c;
    for (std::size_t i = 0; i < s.size(); ++i) {
      c = s.at(i);
      if ((c < '0' || c > '9') &&
          c != '+' &&
          c != '-' &&
          c != '*' &&
          c != '/' &&
          c != '.' &&
          c != ',' &&
          c != ' ' &&
          c != '(' &&
          c != ')') {
        throw std::exception{};
      }
      else {
        ++pos;
      }
    }
  }
  catch (const std::exception& exc) {
    result = false;
    for (std::size_t i = 0; i < pos; ++i) {
      std::cout << ' ';
    }
    std::cout << "^ invalid character!" << std::endl;
  }
  return result;
}

bool Tokenizer::checkParenthesis(const std::string& s)
{
  bool result{true};
  std::size_t paren_pos{0};
  try {
    int openParCount{0};
    int closeParCount{0};
    for (std::size_t i = 0; i < s.size(); ++i) {
      char c = s.at(i);
      if ('(' == c) {
        if (0 == openParCount) {
          paren_pos = i;
        }
        ++openParCount;
      }
      if (')' == c) {
        ++closeParCount;
      }
    }
    if (openParCount != closeParCount) {
      throw std::exception{};
    }
  }
  catch (const std::exception& exc) {
    result = false;
    for (std::size_t i = 0; i < paren_pos; ++i) {
      std::cout << ' ';
    }
    std::cout << "^ unmatched parethesis!" << std::endl;
  }
  return result;
}

std::vector<std::string> Tokenizer::tokenize(const std::string& s)
{
  bool valid{false};
  valid = Tokenizer::get().verify(s);
  if (!valid) {
    return std::vector<std::string>{};
  }
  std::vector<std::string> result;
  bool isToken{false};
  std::string tmp;
  for (std::size_t i = 0; i < s.size(); ++i) {
    char c;
    c = s.at(i);
    if (' ' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
    }
    if ((c >= '0' && c <= '9') || '.' == c || ',' == c) {
      if (isToken) {
        tmp.push_back(c);
      }
      else {
        isToken = true;
        tmp.push_back(c);
      }
    }
    if ('+' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
      result.push_back("+");
    }
    if ('-' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
        result.push_back("-");
      }
      else {
        isToken = true;
        tmp.push_back(c);
      }
    }
    if ('*' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
      result.push_back("*");
    }
    if ('/' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
      result.push_back("/");
    }
    if ('(' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
      result.push_back("(");
    }
    if (')' == c) {
      if (isToken) {
        isToken = false;
        result.push_back(tmp);
        tmp.erase();
      }
      result.push_back(")");
    }
  }
  result.push_back(tmp);
  return result;
}
