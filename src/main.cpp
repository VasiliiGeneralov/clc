#include <iostream>
#include <string>
#include <vector>

#include "Tokenizer.hpp"
#include "Parser.hpp"
#include "Analyzer.hpp"

int main()
{
  std::string input;
  std::getline(std::cin, input);
  std::vector<std::string> tokens;
  tokens = Tokenizer::tokenize(input);
  if (tokens.empty()) {
    return 1;
  }
  tokens = Parser::parse(tokens);
  if (tokens.empty()) {
    return 2;
  }
  std::cout << Analyzer::analyze(tokens) << std::endl;
  return 0;
}
