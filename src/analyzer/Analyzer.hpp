#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <string>
#include <vector>

class Analyzer {
  public:
    explicit Analyzer(const Analyzer& a) = delete;
    Analyzer& operator=(const Analyzer& a) = delete;
    ~Analyzer() = default;
    static Analyzer& get();
    static double analyze(const std::vector<std::string>& v);
  private:
    Analyzer() = default;
    double create(const std::string& s);
};

#endif // ANALYZER_HPP
