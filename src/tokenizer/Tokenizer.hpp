#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>

class Tokenizer {
  public:
    explicit Tokenizer(const Tokenizer& t) = delete;
    Tokenizer& operator=(const Tokenizer& t) = delete;
    ~Tokenizer() = default;
    static Tokenizer& get();
    static std::vector<std::string> tokenize(const std::string& s);
  private:
    Tokenizer() = default;
    bool verify(const std::string& s);
};

#endif // TOKENIZER_HPP
