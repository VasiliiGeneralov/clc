#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <string>
#include <tuple>
#include <vector>

class Analyzer {
  public:
    explicit Analyzer(const Analyzer& a) = delete;
    Analyzer& operator=(const Analyzer& a) = delete;
    ~Analyzer() = default;
    static Analyzer& get();
    static std::tuple<bool, int, double> analyze(const std::vector<std::string>& v);
  private:
    Analyzer() = default;
    std::tuple<bool, int, double> traverse(std::vector<std::string>::const_iterator first,
                                           std::vector<std::string>::const_iterator last);
    std::tuple<bool, int, double> create(const std::string& s);
    bool floatMode;
};

#endif // ANALYZER_HPP
