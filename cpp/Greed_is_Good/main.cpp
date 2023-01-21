#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

int score(const std::vector<int>& dice) {
  std::map<int, int> m;
  for (size_t i = 1; i <= 6; ++i) {
    m.insert(std::pair<int, int>(i, 0));
  }
  for (auto const& i : dice) {
    ++m[i];
  }
  int score(0);
  for (auto const& [key, value] : m) {
    if (key == 6 && m[key] > 2) score += 600;
    if (key == 4 && m[key] > 2) score += 400;
    if (key == 3 && m[key] > 2) score += 300;
    if (key == 2 && m[key] > 2) score += 200;
    if (key == 1 && m[key] > 2) {
      score += 1000;
      m[key] -= 3;
    }
    if (key == 5 && m[key] > 2) {
      score += 500;
      m[key] -= 3;
    }
    if (key == 1 && m[key] > 0) {
      for (int i = 0; i < m[key]; ++i) {
        score += 100;
      }
    }
    if (key == 5 && m[key] > 0) {
      for (int i = 0; i < m[key]; ++i) {
        score += 50;
      }
    }
  }
  return score;
}

int main() {
  if (score({2, 3, 4, 6, 2}) == 0 && score({2, 4, 4, 5, 4}) == 450 &&
      score({5, 1, 3, 4, 1}) == 250 && score({1, 1, 1, 3, 1}) == 1100 &&
      score({2, 4, 4, 5, 4}) == 450)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
