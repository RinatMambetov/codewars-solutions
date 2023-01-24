#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

int main() {
  int a(0);
  int b(1);

  std::cout << std::boolalpha;
  std::cout << (a and b) << '\n';
  std::cout << (a or b) << '\n';
  std::cout << not b << '\n';

  std::cout << CHAR_BIT << '\n';

  std::cout << sizeof(int) << '\n';

  std::cout << sizeof(int8_t) << '\n';
  std::cout << sizeof(int16_t) << '\n';
  std::cout << sizeof(int32_t) << '\n';
  std::cout << sizeof(int64_t) << '\n';

  std::cout << sizeof(uint8_t) << '\n';

  // int v = 2.5;
  // int v(2.5);
  // int v{2.5};

  return 0;
}
