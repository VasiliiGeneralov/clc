#include <vector>
#include <iostream>
#include <string>

#include "Tokenizer.hpp"

namespace tokenizer {

  TokenInt::TokenInt(int newValue) : value(newValue)
  {
    std::cout << "created TokenInt with " << value << std::endl;
  }

  TokenFloat::TokenFloat(double newValue) : value(newValue)
  {
    std::cout << "created TokenFloat with " << value << std::endl;
  }

  TokenAdd::TokenAdd()
  {
    std::cout << "created TokenAdd" << std::endl;
  }

  TokenSub::TokenSub()
  {
    std::cout << "created TokenSub" << std::endl;
  }

  TokenMul::TokenMul()
  {
    std::cout << "created TokenMul" << std::endl;
  }

  TokenDiv::TokenDiv()
  {
    std::cout << "created TokenDiv" << std::endl;
  }

  TokenOpenParen::TokenOpenParen()
  {
    std::cout << "created TokenOpenParen" << std::endl;
  }

  TokenCloseParen::TokenCloseParen()
  {
    std::cout << "created TokenCloseParen" << std::endl;
  }

  Token* createIntOrFloat(const std::string& s)
  {
    if (s.empty()) {
      return new TokenInt{};
    }
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
    if (isFloat) {
      double frac{0};
      order = 10;
      ++i;
      for (; i < s.size(); ++i) {
        char c = s.at(i);
        frac = frac + (static_cast<double>(c - '0') / order);
        order *= 10;
      }
      return new TokenFloat(sign * (static_cast<double>(whole) + frac));
    }
    else {
      return new TokenInt(sign * whole);
    }
  }

  std::vector<Token*> tokenize(const std::string& input)
  {
    std::vector<Token*> result{};
    bool isToken{false};
    std::string tmp;
    for (std::size_t i = 0; i < input.size(); ++i) {
      char c;
      c = input.at(i);
      if (' ' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
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
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
        }
        result.push_back(new TokenAdd{});
      }
      if ('-' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
          result.push_back(new TokenSub{});
        }
        else {
          isToken = true;
          tmp.push_back(c);
        }
      }
      if ('*' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
        }
        result.push_back(new TokenMul{});
      }
      if ('/' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
        }
        result.push_back(new TokenDiv{});
      }
      if ('(' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
        }
        result.push_back(new TokenOpenParen{});
      }
      if (')' == c) {
        if (isToken) {
          isToken = false;
          std::cout << tmp << std::endl;
          result.push_back(createIntOrFloat(tmp));
          tmp.erase();
        }
        result.push_back(new TokenCloseParen{});
      }
    }
    std::cout << tmp << std::endl;
    result.push_back(createIntOrFloat(tmp));
    return result;
  }

  void cleanup(const std::vector<Token*> v)
  {
    for (const auto p : v) {
      delete p;
    }
  }

} // namespace tokenizer
