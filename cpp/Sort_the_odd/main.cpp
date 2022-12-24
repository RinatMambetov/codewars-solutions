#include <algorithm>
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

class Kata {
 public:
  std::vector<int> sortArray(std::vector<int> array) {
    std::map<int, int> m;
    std::vector<int> odds;
    for (size_t i = 0; i < array.size(); ++i) {
      if (array[i] % 2 == 0)
        m.insert(std::pair<int, int>(i, array[i]));
      else
        odds.push_back(array[i]);
    }
    std::sort(odds.begin(), odds.end());
    std::vector<int> result;
    int odds_elem(0);
    for (size_t i = 0; i < array.size(); ++i) {
      if (m.find(i) != m.end())
        result.push_back(m.find(i)->second);
      else {
        result.push_back(odds[odds_elem]);
        ++odds_elem;
      }
    }
    return result;
  }
};

int main() {
  std::vector<int> v0 = {5, 3, 2, 8, 1, 4};
  std::vector<int> exp0 = {1, 3, 2, 8, 5, 4};
  std::vector<int> v1 = {5, 3, 1, 8, 0};
  std::vector<int> exp1 = {1, 3, 5, 8, 0};

  Kata k;
  std::vector<int> res0 = k.sortArray(v0);
  std::vector<int> res1 = k.sortArray(v1);

  printv(res0);
  printv(res1);

  if (std::equal(res0.begin(), res0.end(), exp0.begin()) == true &&
      std::equal(res1.begin(), res1.end(), exp1.begin()) == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
