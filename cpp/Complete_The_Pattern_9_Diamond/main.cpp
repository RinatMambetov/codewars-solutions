#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

std::string pattern(int n) {
  if (n < 1) return "";
  if (n == 1) return "1";
  int hight = n * 2 - 1;
  std::string result;
  for (int h = 0; h <= hight / 2; ++h) {
    for (int s = 0; s < hight / 2 - h; s++) {
      result.push_back(' ');
    }
    int w(1);
    for (; w <= h; ++w) {
      result.push_back(w % 10 + '0');
    }
    for (; w > 0; --w) {
      result.push_back(w % 10 + '0');
    }
    for (int s = 0; s < hight / 2 - h; s++) {
      result.push_back(' ');
    }
    result.push_back('\n');
  }
  for (int h = hight / 2 - 1; h >= 0; --h) {
    for (int s = 0; s < hight / 2 - h; s++) {
      result.push_back(' ');
    }
    int w(1);
    for (; w <= h; ++w) {
      result.push_back(w % 10 + '0');
    }
    for (; w > 0; --w) {
      result.push_back(w % 10 + '0');
    }
    for (int s = 0; s < hight / 2 - h; s++) {
      result.push_back(' ');
    }
    if (h != 0) result.push_back('\n');
  }
  return result;
}

int main() {
  std::string expected7 =
      "      1      \n     121     \n    12321    \n   1234321   \n  123454321 "
      " \n 12345654321 \n1234567654321\n 12345654321 \n  123454321  \n   "
      "1234321   \n    12321    \n     121     \n      1      ";
  std::string expected3 = "  1  \n 121 \n12321\n 121 \n  1  ";

  if (pattern(3).compare(expected3) == 0 && pattern(7).compare(expected7) == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  std::cout << pattern(10) << '\n';

  return 0;
}
