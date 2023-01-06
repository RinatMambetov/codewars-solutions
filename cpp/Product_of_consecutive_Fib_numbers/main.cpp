#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

typedef unsigned long long ull;

ull getFibo(ull num) {
  if (num == 0) return 0;
  if (num == 1) return 1;
  if (num == 2) return 1;
  return getFibo(num - 1) + getFibo(num - 2);
}

class ProdFib {
 public:
  static std::vector<ull> productFib(ull prod) {
    if (prod == 0) return {0, 0, 1};
    ull num1(0);
    ull num2(0);
    ull counter(1);
    while (num1 * num2 < prod) {
      num1 = getFibo(counter);
      num2 = getFibo(counter + 1);
      if (num1 * num2 == prod) return {num1, num2, 1};
      ++counter;
    }
    return {num1, num2, 0};
  };
};

int main() {
  std::vector<ull> v0{55, 89, true};
  std::vector<ull> v1{10946, 17711, 0ULL};

  ProdFib p0;
  std::vector<ull> r0 = p0.productFib(4895);
  std::vector<ull> r1 = p0.productFib(84049690);

  if (std::equal(v0.begin(), v0.end(), r0.begin()) == true &&
      std::equal(v1.begin(), v1.end(), r1.begin()) == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
