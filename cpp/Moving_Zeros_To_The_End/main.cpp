#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  std::vector<int> v = input;
  int zero_counter(0);
  for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
    if (*it == 0) {
      v.erase(it);
      ++zero_counter;
    } else
      ++it;
  }
  while (zero_counter) {
    v.push_back(0);
    --zero_counter;
  }
  return v;
}

int main() {
  std::vector<int> v0{1, 2, 0, 1, 0, 1, 0, 3, 0, 1};
  std::vector<int> v1{1, 2, 5, 1, 5, 1, 5, 3, 2, 1};
  std::vector<int> v00 = move_zeroes(v0);
  std::vector<int> v11 = move_zeroes(v1);
  std::vector<int> res0{1, 2, 1, 1, 3, 1, 0, 0, 0, 0};
  std::vector<int> res1{1, 2, 5, 1, 5, 1, 5, 3, 2, 1};

  if (std::equal(v00.begin(), v00.end(), res0.begin()) == true &&
      std::equal(v00.begin(), v00.end(), res0.begin()) == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
