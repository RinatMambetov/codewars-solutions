#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
  std::vector<std::string> v;
  for (size_t i = 0; i < nFloors; ++i) {
    std::string str;
    for (size_t j = 0; j < nFloors - i - 1; ++j) {
      str += ' ';
    }
    for (size_t j = 0; j < i * 2 + 1; ++j) {
      str += '*';
    }
    for (size_t j = 0; j < nFloors - i - 1; ++j) {
      str += ' ';
    }
    v.push_back(str);
  }
  return v;
}

int main() {
  std::vector<std::string> expected = {"  *  ", " *** ", "*****"};
  std::vector<std::string> actual = towerBuilder(3);

  if (std::equal(expected.begin(), expected.end(), actual.begin()) == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
