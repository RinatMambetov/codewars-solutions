#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

size_t log_a_to_base_b(size_t a, size_t b) { return log2(a) / log2(b); }

long zeros(long n) {
  if (n == 0) return 0;
  std::vector<size_t> v;
  size_t k = log_a_to_base_b(n, 5);
  for (size_t i = 1; i <= k; ++i) {
    v.push_back(n / pow(5, i));
  }
  return std::accumulate(v.begin(), v.end(), 0);
}

int main() {
  std::cout << zeros(1000000000) << '\n';

  if (zeros(1000000000) == 249999998 && zeros(0) == 0 && zeros(6) == 1)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
