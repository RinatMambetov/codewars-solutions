#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

bool scramble(const std::string& s1, const std::string& s2) {
  std::string a("abcdefghijklmnopqrstuvwxyz");
  std::map<char, size_t> m;
  for (auto const& i : a) {
    m.insert(std::pair<char, size_t>(i, 0));
  }
  for (char const& i : s1) {
    ++m[i];
  }
  for (char const& i : s2) {
    if (m[i] == 0)
      return false;
    else
      --m[i];
  }
  return true;
}

int main() {
  if (scramble("rkqodlw", "world") == true &&
      scramble("scriptjavx", "javascript") == false &&
      scramble("aabbcamaomsccdd", "commas") == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
