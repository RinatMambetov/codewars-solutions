#include <cmath>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> resplit(const std::string &s,
                                 const std::regex &sep_regex = std::regex{
                                     "\\s+"}) {
  std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
  std::sregex_token_iterator end;
  return {iter, end};
}

std::string change(std::string &i) {
  char first = i[0];
  i = i.substr(1);
  i += first;
  i += "ay";
  return i;
}

std::string pig_it(std::string str) {
  std::vector<std::string> v = resplit(str);
  std::string s;
  for (std::string &i : v) {
    if (i.size() == 1 && (i[0] < 'A' || i[0] > 'z'))
      s += i;
    else
      s += change(i);
    s += ' ';
  }
  s.pop_back();
  return s;
}

int main() {
  std::string s0("This is my string");
  std::string s1("Pig latin is cool");

  if (pig_it(s0).compare("hisTay siay ymay tringsay") == 0 &&
      pig_it(s1).compare("igPay atinlay siay oolcay") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}

// std::string pig_it(std::string Z) {
//   std::regex reg(("(\\w)(\\w*)(\\s|$)"));
//   return std::regex_replace(Z, reg, "$2$1ay$3");
// }
