#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> v;
  std::string str;
  for (size_t i = 0; i < s.size(); ++i) {
    if (i % 2 == 0)
      str += s[i];
    else {
      str += s[i];
      v.push_back(str);
      str.clear();
    }
  }
  if (s.size() % 2 != 0) {
    str += '_';
    v.push_back(str);
  }
  return v;
}

int main() {
  std::vector<std::string> v0 = {"ab", "cd", "e_"};
  std::vector<std::string> v1 = {"He", "ll", "oW", "or", "ld"};
  std::vector<std::string> sol0 = solution("abcde");
  std::vector<std::string> sol1 = solution("HelloWorld");

  if (std::equal(sol0.begin(), sol0.end(), v0.begin()) == true &&
      std::equal(sol1.begin(), sol1.end(), v1.begin()) == true)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
