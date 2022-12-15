#include <clocale>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

std::string greekLeet(std::string str) {
  std::map<char, std::string> m;
  m.insert(std::pair<char, std::string>('a', "α"));
  m.insert(std::pair<char, std::string>('b', "β"));
  m.insert(std::pair<char, std::string>('d', "δ"));
  m.insert(std::pair<char, std::string>('e', "ε"));
  m.insert(std::pair<char, std::string>('i', "ι"));
  m.insert(std::pair<char, std::string>('k', "κ"));
  m.insert(std::pair<char, std::string>('n', "η"));
  m.insert(std::pair<char, std::string>('o', "θ"));
  m.insert(std::pair<char, std::string>('p', "ρ"));
  m.insert(std::pair<char, std::string>('r', "π"));
  m.insert(std::pair<char, std::string>('t', "τ"));
  m.insert(std::pair<char, std::string>('u', "μ"));
  m.insert(std::pair<char, std::string>('v', "υ"));
  m.insert(std::pair<char, std::string>('w', "ω"));
  m.insert(std::pair<char, std::string>('x', "χ"));
  m.insert(std::pair<char, std::string>('y', "γ"));
  std::string greece;
  for (char i : str) {
    if (m.find(std::tolower(i)) == m.end())
      greece.push_back(std::tolower(i));
    else
      greece += (m.find(std::tolower(i))->second);
  }
  return greece;
}

int main() {
  std::cout << greekLeet("AbcdeF") << '\n';
  if (greekLeet("a").compare("α") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
