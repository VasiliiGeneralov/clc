#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>

namespace tokenizer {

  class Token {
    public:
      Token() = default;
      virtual ~Token() = default;
  };

  class TokenInt : public Token {
    public:
      TokenInt() = default;
      explicit TokenInt(int newValue);
      ~TokenInt() override = default;
    private:
      int value;
  };

  class TokenFloat : public Token {
    public:
      TokenFloat() = default;
      explicit TokenFloat(double newValue);
      ~TokenFloat() override = default;
    private:
      double value;
  };

  class TokenAdd : public Token {
    public:
      TokenAdd();
      ~TokenAdd() override = default;
  };

  class TokenSub : public Token {
    public:
      TokenSub();
      ~TokenSub() override = default;
  };

  class TokenMul : public Token {
    public:
      TokenMul();
      ~TokenMul() override = default;
  };

  class TokenDiv : public Token {
    public:
      TokenDiv();
      ~TokenDiv() override = default;
  };

  class TokenOpenParen : public Token {
    public:
      TokenOpenParen();
      ~TokenOpenParen() override = default;
  };

  class TokenCloseParen : public Token {
    public:
      TokenCloseParen();
      ~TokenCloseParen() override = default;
  };

  Token* createIntOrFloat(const std::string& s);

  std::vector<Token*> tokenize(const std::string& input);

  void cleanup(const std::vector<Token*> v);

} // namespace tokenizer

#endif // TOKENIZER_HPP
