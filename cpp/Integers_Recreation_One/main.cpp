#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

bool isSqrt(long long num) {
  long long t = sqrt(num);
  if (t * t == num) return true;
  return false;
}

long long getSumSqrtDivs(long long num) {
  std::vector<long long> v;
  for (long long i = 1; i <= sqrt(num); ++i) {
    if (num % i == 0) {
      if (num / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(num / i);
      }
    }
  }
  return std::inner_product(v.begin(), v.end(), v.begin(), 0);
}

class SumSquaredDivisors {
 public:
  static std::vector<std::pair<long long, long long>> listSquared(long long m,
                                                                  long long n) {
    std::vector<std::pair<long long, long long>> result;
    for (long long i = m; i <= n; ++i) {
      long long sum = getSumSqrtDivs(i);
      if (isSqrt(sum) == true)
        result.push_back(std::pair<long long, long long>(i, sum));
    }
    return result;
  }
};

void p(std::vector<std::pair<long long, long long>> v) {
  for (auto const &i : v) {
    std::cout << i.first << " " << i.second << '\n';
  }
}

int main() {
  std::vector<std::pair<long long, long long>> v0{
      {1, 1}, {42, 2500}, {246, 84100}};
  std::vector<std::pair<long long, long long>> v1{{42, 2500}, {246, 84100}};
  std::vector<std::pair<long long, long long>> v2{{287, 84100}};
  std::vector<std::pair<long long, long long>> v3{};

  SumSquaredDivisors ssd;

  p(ssd.listSquared(1, 250));
  p(ssd.listSquared(42, 250));
  p(ssd.listSquared(250, 500));
  p(ssd.listSquared(300, 600));

  // std::cout << isSqrt(2500) << '\n';
  // std::cout << getSumSqrtDivs(246) << '\n';

  return 0;
}
