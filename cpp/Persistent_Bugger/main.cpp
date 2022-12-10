#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int persistence(long long n) {
  std::string str = std::to_string(n);
  int counter(0);
  while (str.size() > 1) {
    int multi(1);
    for (auto const &i : str) {
      multi *= i - '0';
    }
    str = std::to_string(multi);
    ++counter;
  }
  return counter;
}

int main() {
  if (persistence(39) == 3 && persistence(999) == 4)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
