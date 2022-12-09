#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

std::string str_tolower(std::string const& str) {
  std::string temp = str;
  for (size_t i = 0; i < temp.size(); ++i) {
    temp.at(i) = std::tolower(temp.at(i));
  }
  return temp;
}

std::map<char, int> getMap(std::string const& str) {
  std::map<char, int> m;
  for (size_t i = 0; i < str.size(); ++i) {
    if (m.find(str.at(i)) == m.end()) {
      m.insert(std::pair<char, int>(str.at(i), 1));
    } else {
      ++m.find(str.at(i))->second;
    }
  }
  return m;
}

std::string duplicate_encoder(const std::string& word) {
  std::string word_lower = str_tolower(word);
  std::map<char, int> m = getMap(word_lower);
  std::string result;
  for (const auto& i : word_lower) {
    if (m.find(i)->second > 1)
      result.push_back(')');
    else
      result.push_back('(');
  }
  return result;
}

int main() {
  if (duplicate_encoder("Recede").compare("()()()") == 0 &&
      duplicate_encoder("Success").compare(")())())") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
