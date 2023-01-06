#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int range_sum(const std::vector<int>& arr, size_t f, size_t s) {
  int sum(0);
  for (size_t i = f; i <= s; ++i) {
    sum += arr[i];
  }
  return sum;
}

int maxSequence(const std::vector<int>& arr) {
  if (arr.size() == 0) return 0;
  bool pos(true);
  for (auto& i : arr) {
    if (i <= 0) pos = false;
  }
  if (pos == true) return std::accumulate(arr.begin(), arr.end(), 0);
  bool neg(true);
  for (auto& i : arr) {
    if (i > 0) neg = false;
  }
  if (neg == true) return 0;
  int max_sum(0);
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] > max_sum) max_sum = arr[i];
    for (size_t j = i + 1; j < arr.size(); ++j) {
      if (range_sum(arr, i, j) > max_sum) {
        max_sum = range_sum(arr, i, j);
      }
    }
  }
  return max_sum;
}

int main() {
  std::vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  std::cout << maxSequence(v) << '\n';

  if (maxSequence(v) == 6)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
