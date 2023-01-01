#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int norm(int n) {
  n = n < 0 ? 0 : n;
  n = n > 255 ? 255 : n;
  return n;
}

class RGBToHex {
 public:
  static std::string rgb(int r, int g, int b) {
    r = norm(r);
    g = norm(g);
    b = norm(b);
    std::stringstream ss;
    if (r < 17) ss << '0';
    ss << std::hex << r;
    if (g < 17) ss << '0';
    ss << std::hex << g;
    if (b < 17) ss << '0';
    ss << std::hex << b;

    std::string res(ss.str());
    for (auto &i : res) {
      i = std::toupper(i);
    }
    return res;
  }
};

int main() {
  RGBToHex rgb;

  std::cout << rgb.rgb(255, 255, 255) << '\n';
  std::cout << rgb.rgb(-20, 275, 125) << '\n';

  if (rgb.rgb(255, 255, 255).compare("FFFFFF") == 0 &&
      rgb.rgb(-20, -275, 125).compare("00007D") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
