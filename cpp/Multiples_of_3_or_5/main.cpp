#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int solution(int number) {
  if (number < 3) return 0;
  int sum(0);
  for (int i = 3; i < number; ++i) {
    if (i % 3 == 0 || i % 5 == 0) sum += i;
  }
  return sum;
}

int main() {
  if (solution(10) == 23)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
