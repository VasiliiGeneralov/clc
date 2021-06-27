#include <vector>
#include <string>

#include "Parser.hpp"

Parser& Parser::get()
{
  static Parser p;
  return p;
}

std::vector<std::string> Parser::parse(const std::vector<std::string>& v)
{
}
