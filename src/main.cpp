#include <iostream>
#include <string>
#include <vector>

#include "tokenizer/Tokenizer.hpp"
#include "parser/Parser.hpp"
#include "analyzer/Analyzer.hpp"

int main()
{
  std::string input;
  std::getline(std::cin, input);
  std::vector<std::string> tokens;
  tokens = Tokenizer::tokenize(input);
  for (const auto& t : tokens) {
    std::cout << t << std::endl;
  }
  tokens = Parser::parse(tokens);
  for (const auto& t : tokens) {
    std::cout << t;
  }
  std::cout << std::endl;
}
