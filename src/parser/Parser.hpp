#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

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
};

#endif // PARSER_HPP
