#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

bool is_equal(float num1, float num2) {
  float delta = 0.1e-3;
  if ((num1 + delta) > num2 && (num1 - delta) < num2) return true;
  return false;
}

float find_not_uniq(const std::vector<float> &v) {
  if (is_equal(v[0], v[1]) && is_equal(v[0], v[2])) return v[0];
  if (is_equal(v[0], v[1]) && !is_equal(v[0], v[2])) return v[0];
  if (is_equal(v[0], v[2]) && !is_equal(v[0], v[1])) return v[0];
  return v[1];
}

float find_uniq(const std::vector<float> &v) {
  float not_uniq = find_not_uniq(v);
  for (auto const &elem : v) {
    if (!is_equal(elem, not_uniq)) return elem;
  }
  return -1.f;
}

int main() {
  std::vector<float> v0 = {1, 1, 1, 2, 1, 1};
  std::vector<float> v1 = {999.666, 999.666, 999.666, 999.666, 999.666,
                           999.666, 999.666, 999,     999.666};

  // std::cout << find_uniq(v0) << '\n';
  // std::cout << find_uniq(v1) << '\n';

  if (find_uniq(v0) == 2.f && find_uniq(v1) == 999.f)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  // std::cout << is_equal(0.1, 0.1) << '\n';
  // std::cout << is_equal(0, 0) << '\n';
  // std::cout << is_equal(1, 0) << '\n';
  // std::cout << is_equal(0.1, 0.2) << '\n';

  // std::cout << find_not_uniq(v0) << '\n';
  // std::cout << find_not_uniq(v1) << '\n';

  return 0;
}
