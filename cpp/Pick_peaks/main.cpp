#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

template <class T>
void printv(std::vector<T> v) {
  for (auto const &i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

struct PeakData {
  std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
  PeakData result;
  if (v.size() < 3) return result;
  for (size_t i = 1; i < v.size() - 1; ++i) {
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
      result.pos.push_back(i);
      result.peaks.push_back(v[i]);
    }
    if (v[i + 1] == v[i] && v[i - 1] < v[i]) {
      size_t tmp = i;
      while (v[i + 1] == v[i] && i < v.size() - 2) ++i;
      if (v[i + 1] < v[i]) {
        result.pos.push_back(tmp);
        result.peaks.push_back(v[tmp]);
      }
    }
  }
  return result;
}

int main() {
  PeakData pd = pick_peaks({3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  pd = pick_peaks({1, 2, 2, 2, 1});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  pd = pick_peaks({1, 2, 2, 2, 2, 1, 5, 3});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  pd = pick_peaks({1, 2, 2, 2, 3});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  pd = pick_peaks({1, 2, 2, 2, 2});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  pd = pick_peaks({2, 2, 2, 2, 1});
  printv(pd.pos);
  printv(pd.peaks);
  std::cout << "===\n";

  return 0;
}
