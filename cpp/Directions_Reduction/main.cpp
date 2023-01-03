#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

template <class T>
void printv(std::vector<T> v) {
  for (auto const &i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

class DirReduction {
 public:
  static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
    std::map<std::string, int> m = {
        {"NORTH", 1}, {"SOUTH", 1}, {"WEST", 2}, {"EAST", 2}};
    std::vector<std::string> v(arr);
    std::vector<std::string>::iterator it = v.begin();
    while (v.size() > 1 && it != v.end() - 2) {
      if (m.at(*it) == m.at(*(it + 1)) && (*it).compare(*(it + 1)) != 0) {
        v.erase(it, it + 2);
        it = v.begin();
      } else
        ++it;
    }
    return v;
  }
};

int main() {
  std::vector<std::string> d1 = {"NORTH", "NORTH", "SOUTH", "SOUTH",
                                 "EAST",  "WEST",  "NORTH", "WEST"};
  std::vector<std::string> d2 = {"NORTH", "SOUTH", "SOUTH", "EAST",
                                 "WEST",  "NORTH", "NORTH"};
  std::vector<std::string> sol1 = {"WEST"};
  std::vector<std::string> sol2 = {"NORTH"};

  DirReduction dr;

  std::vector<std::string> v1 = dr.dirReduc(d1);
  std::vector<std::string> v2 = dr.dirReduc(d2);

  // printv(v1);
  // printv(v2);

  if (std::equal(v1.begin(), v1.end(), sol1.begin()) == true &&
      std::equal(v2.begin(), v2.end(), sol2.begin()) == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
