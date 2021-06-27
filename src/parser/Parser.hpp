#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <string>
#include <vector>

class Parser {
  public:
    explicit Parser(const Parser& p) = delete;
    Parser& operator=(const Parser& p) = delete;
    ~Parser() = default;
    static Parser& get();
    static std::vector<std::string> parse(const std::vector<std::string>& v);
  private:
    Parser() = default;
    bool checkout(const std::vector<std::string>& v);
    std::map<std::string, int> precedence{
      {"(", 0},
      {"+", 1},
      {"-", 1},
      {"*", 2},
      {"/", 2}
    };
};

#endif // PARSER_HPP
