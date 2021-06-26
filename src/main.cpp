#include <iostream>
#include <string>
#include <stdexcept>

#include "tokenizer/Tokenizer.hpp"
#include "parser/Parser.hpp"
#include "analyzer/Analyzer.hpp"

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::size_t pos{0};
	try {
		char c;
		for (std::size_t i = 0; i < input.size(); ++i) {
			c = input.at(i);
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
		for (std::size_t i = 0; i < pos; ++i) {
			std::cout << ' ';
		}
		std::cout << "^ invalid character!" << std::endl;
		return 1;
	}
}
