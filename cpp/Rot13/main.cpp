#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::string rot13(std::string msg) {
  std::string alph(
      "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST"
      "UVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
  std::string res;
  for (auto &i : msg) {
    if (alph.find(i) != std::string::npos)
      res += alph[alph.find(i) + 13];
    else
      res += i;
  }
  return res;
}

int main() {
  if (rot13("test").compare("grfg") == 0 && rot13("AbCd").compare("NoPq") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
