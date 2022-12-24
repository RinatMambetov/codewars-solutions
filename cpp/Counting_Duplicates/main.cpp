#include <cmath>
#include <iostream>
#include <map>
#include <string>

// size_t duplicateCount(const std::string& in);  // helper for tests

size_t duplicateCount(const char* in) {
  std::string str(in);
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  std::map<char, int> m;
  for (size_t i = 0; i < str.size(); ++i) {
    if (m.find(str[i]) == m.end())
      m.insert(std::pair<char, int>(str[i], 1));
    else
      ++m.find(str[i])->second;
  }
  int counter(0);
  for (auto const& i : m) {
    if (i.second > 1) ++counter;
  }
  return counter;
}

int main() {
  if (duplicateCount("aabbcde") == 2 && duplicateCount("Indivisibilities") == 2)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
