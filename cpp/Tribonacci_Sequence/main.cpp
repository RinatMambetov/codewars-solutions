#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
  std::vector<int> result;
  if (n == 0) return result;
  if (n < 3) {
    for (int i = 0; i < n; i++) {
      result.push_back(signature.at(i));
    }
    return result;
  }
  for (int i = 0; i < 3; ++i) {
    result.push_back(signature.at(i));
  }
  if (n < 4) return result;
  for (int i = 3; i < n; ++i) {
    result.push_back(result.at(i - 3) + result.at(i - 2) + result.at(i - 1));
  }
  return result;
}

int main() {
  std::vector<int> signature0 = {1, 1, 1};
  std::vector<int> expected0 = {1, 1, 1, 3, 5, 9, 17, 31, 57, 105};
  std::vector<int> signature1 = {1, 2, 3};
  std::vector<int> expected1 = {1, 2};

  std::vector<int> result0 = tribonacci(signature0, 10);
  std::vector<int> result1 = tribonacci(signature1, 2);
  if (std::equal(result0.begin(), result0.end(), expected0.begin()) &&
      std::equal(result1.begin(), result1.end(), expected1.begin()))
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
