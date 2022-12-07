#include <bitset>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

unsigned int countBits(unsigned long long n) {
  std::bitset<64> set = n;
  return set.count();
}

int main() {
  if (countBits(26) == 3 && countBits(77231418) == 14)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
