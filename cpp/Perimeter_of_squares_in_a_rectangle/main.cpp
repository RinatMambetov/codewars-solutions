#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

typedef unsigned long long ull;

// ull fibo(int n) {
//   if (n == 0) return 0;
//   if (n == 1) return 1;
//   return fibo(n - 1) + fibo(n - 2);
// }

ull fibo(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  ull a(0);
  ull b(1);
  for (int i = 2; i <= n; ++i) {
    ull t = a + b;
    a = b;
    b = t;
  }
  return b;
}

class SumFct {
 public:
  static ull perimeter(int n) {
    std::vector<ull> v;
    for (int i = 0; i <= n + 1; ++i) {
      v.push_back(fibo(i));
    }
    return std::accumulate(v.begin(), v.end(), 0) * 4;
  }
};

int main() {
  SumFct sf;

  if (sf.perimeter(5) == 80 && sf.perimeter(30) == 14098308 &&
      sf.perimeter(7) == 216)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
