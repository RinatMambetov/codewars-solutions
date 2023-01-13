#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

std::string inc_num(std::string const& num) {
  size_t n = std::stoul(num);
  ++n;
  return std::to_string(n);
}

std::string inc_num_with_zero(std::string const& num) {
  size_t len = num.size();
  size_t n = std::stoul(num);
  ++n;
  std::string inc_num(std::to_string(n));
  std::reverse(inc_num.begin(), inc_num.end());
  while (inc_num.size() < len) inc_num.push_back('0');
  std::reverse(inc_num.begin(), inc_num.end());
  return inc_num;
}

std::string incrementString(const std::string& str) {
  std::string num;
  for (size_t i = 0; i < str.size(); ++i) {
    if (std::isdigit(str[i]))
      num += str[i];
    else
      num.clear();
  }
  size_t len = num.size();
  if (len == 0) return str + "1";
  size_t item = str.size() - len;
  if (num[0] != '0')
    num = inc_num(num);
  else
    num = inc_num_with_zero(num);
  return str.substr(0, item) + num;
}

int main() {
  if (incrementString("foobar000").compare("foobar001") == 0 &&
      incrementString("foo").compare("foo1") == 0 &&
      incrementString("foobar001").compare("foobar002") == 0 &&
      incrementString("foobar99").compare("foobar100") == 0 &&
      incrementString("foobar099").compare("foobar100") == 0 &&
      incrementString("").compare("1") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
