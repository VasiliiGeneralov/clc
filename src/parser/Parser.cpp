#include <map>
#include <stack>
#include <string>
#include <vector>

#include "Parser.hpp"

Parser& Parser::get()
{
  static Parser p;
  return p;
}

bool Parser::checkout(const std::vector<std::string>& v)
{
  bool result{true};
  for (const auto& s : v) {
    if ("(" == s ||
        ")" == s) {
      result = false;
      break;
    }
  }
  return result;
}

std::vector<std::string> Parser::parse(const std::vector<std::string>& v)
{
  std::stack<std::string> s;
  std::vector<std::string> result;
  for (std::size_t i = 0; i < v.size(); ++i) {
    std::string token = v.at(i);
    if ("(" == token) {
      s.push(token);
      continue;
    }
    if (")" == token) {
      while (s.top() != "(") {
        result.push_back(s.top());
        s.pop();
      }
      s.pop();
      continue;
    }
    if ("+" == token ||
        "-" == token ||
        "*" == token ||
        "/" == token){
      if (s.empty() ||
          Parser::get().precedence[token] > Parser::get().precedence[s.top()]) {
        s.push(token);
        continue;
      } else {
        while (!s.empty() && Parser::get().precedence[token] <= Parser::get().precedence[s.top()]) {
          result.push_back(s.top());
          s.pop();
        }
        s.push(token);
        continue;
      }
    }
    result.push_back(token);
  }
  while (!s.empty()) {
    result.push_back(s.top());
    s.pop();
  }
  return Parser::get().checkout(result) ? result : std::vector<std::string>{};
}
