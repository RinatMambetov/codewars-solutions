#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int findNum(std::vector<int> arr, int isOdd) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (!isOdd && arr.at(i) % 2 == 0) return arr.at(i);
    if (isOdd && arr.at(i) % 2 != 0) return arr.at(i);
  }
  return 0;
}

int FindOutlier(std::vector<int> arr) {
  int odd_conter(0);
  int even_conter(0);
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr.at(i) % 2 == 0)
      ++even_conter;
    else
      ++odd_conter;
    if (even_conter > 1) return findNum(arr, 1);
    if (odd_conter > 1) return findNum(arr, 0);
  }
  return 0;
}

int main() {
  std::vector<int> v0{2, 4, 0, 100, 4, 11, 2602, 36};
  std::vector<int> v1{160, 3, 1719, 19, 11, 13, -21};

  if (FindOutlier(v0) == 11 && FindOutlier(v1) == 160)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
