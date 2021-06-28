#include <cassert>
#include <iostream>
#include <string>

#include "Analyzer.hpp"
#include "Parser.hpp"
#include "Tokenizer.hpp"

int main() {
  std::string test1{"1"};
  std::cout << test1 << std::endl;
  std::cout << "expect: 1" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test1)))
            << std::endl;
  std::cout << std::endl;
  std::string test2{"1+3"};
  std::cout << test2 << std::endl;
  std::cout << "expect: 4" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test2)))
            << std::endl;
  std::cout << std::endl;
  std::string test3{"1 + 2 - (3 * 4)"};
  std::cout << test3 << std::endl;
  std::cout << "expect: -9" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test3)))
            << std::endl;
  std::cout << std::endl;
  std::string test4{"1 * 2 / 3 * 4 / 5"};
  std::cout << test4 << std::endl;
  std::cout << "expect: 0.53" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test4)))
            << std::endl;
  std::cout << std::endl;
  std::string test5{"((1,5 + 1.5)/3)"};
  std::cout << test5 << std::endl;
  std::cout << "expect: 1" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test5)))
            << std::endl;
  std::cout << std::endl;
  std::string test6{"1 - 10 + 100 - 1000"};
  std::cout << test6 << std::endl;
  std::cout << "expect: -909" << std::endl;
  std::cout << "got: "
            << Analyzer::analyze(Parser::parse(Tokenizer::tokenize(test6)))
            << std::endl;
  std::cout << std::endl;
}
