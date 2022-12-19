#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

// trim from start (in place)
static inline void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

std::vector<std::string> resplit(const std::string &s,
                                 const std::regex &sep_regex = std::regex{
                                     "\\s+"}) {
  std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
  std::sregex_token_iterator end;
  return {iter, end};
}

std::size_t replace_all(std::string &inout, std::string_view what,
                        std::string_view with) {
  std::size_t count{};
  for (std::string::size_type pos{};
       inout.npos != (pos = inout.find(what.data(), pos, what.length()));
       pos += with.length(), ++count) {
    inout.replace(pos, what.length(), with.data(), with.length());
  }
  return count;
}

std::string decodeMorse(std::string morseCode) {
  trim(morseCode);
  replace_all(morseCode, "   ", " ! ");
  std::map<std::string, std::string> m = {
      {".-", "A"},   {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"},
      {".", "E"},    {"..-.", "F"}, {"--.", "G"},  {"....", "H"},
      {"..", "I"},   {".---", "J"}, {"-.-", "K"},  {".-..", "L"},
      {"--", "M"},   {"-.", "N"},   {"---", "O"},  {".--.", "P"},
      {"--.-", "Q"}, {".-.", "R"},  {"...", "S"},  {"-", "T"},
      {"..-", "U"},  {"...-", "V"}, {".--", "W"},  {"-..-", "X"},
      {"-.--", "Y"}, {"--..", "Z"}, {"!", " "},    {"---...---", "SOS"}};
  std::vector<std::string> decodeMorseArray = resplit(morseCode);
  std::string decoded;
  for (auto const &p : decodeMorseArray) {
    if (m.find(p) != m.end()) {
      decoded += m.find(p)->second;
    }
  }
  return decoded;
}

int main() {
  std::string str0 = ".... . -.--   .--- ..- -.. .";
  std::string exp0 = "HEY JUDE";
  std::string str1 = "---...---";
  std::string exp1 = "SOS";

  if (decodeMorse(str0).compare(exp0) == 0 &&
      decodeMorse(str1).compare(exp1) == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
