#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> resplit(const std::string &s,
                                 const std::regex &sep_regex = std::regex{
                                     "\\s+"}) {
  std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
  std::sregex_token_iterator end;
  return {iter, end};
}

long long getW(long long n) {
  long long res(0);
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

class WeightSort {
 public:
  static std::string orderWeight(const std::string &strng) {
    if (strng.size() == 0) return "";
    std::vector<std::string> vs = resplit(strng);
    std::vector<long long> vi;
    for (auto &i : vs) {
      vi.push_back(std::stoll(i));
    }
    std::sort(vi.begin(), vi.end(), [](long long a, long long b) {
      if (getW(a) == getW(b))
        return std::to_string(a) < std::to_string(b);
      else
        return getW(a) < getW(b);
    });

    std::string res;
    for (auto &i : vi) {
      res += std::to_string(i);
      res += ' ';
    }
    res.pop_back();
    return res;
  }
};

int main() {
  WeightSort ws;

  if (ws.orderWeight("56 65 74 100 99 68 86 180 90")
              .compare("100 180 90 56 65 74 68 86 99") == 0 &&
      ws.orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123")
              .compare("11 11 2000 10003 22 123 1234000 44444444 9999") == 0 &&
      ws.orderWeight("59544965313 3 16 9 38 95 1131268 49455 347464 "
                     "85246814996697 496636983114762")
              .compare("3 16 9 38 95 1131268 49455 347464 59544965313 "
                       "496636983114762 85246814996697") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
