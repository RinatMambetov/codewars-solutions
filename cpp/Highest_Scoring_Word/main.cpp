#include <iostream>
#include <map>
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

std::string highestScoringWord(const std::string &str) {
  std::map<char, int> m;
  std::string alphabet("abcdefghijklmnopqrstuvwxyz");
  for (size_t i = 0; i < alphabet.size(); ++i) {
    m.insert(std::pair<char, int>(alphabet.at(i), i + 1));
  }
  std::vector<std::string> words;
  words = resplit(str);
  std::string max_score_str;
  int max_score(0);
  for (auto const &elem : words) {
    int score(0);
    for (auto const &i : elem) {
      score += m.find(i)->second;
    }
    if (score > max_score) {
      max_score = score;
      max_score_str = elem;
    }
  }
  return max_score_str;
}

int main() {
  std::string s0("man i need a taxi up to ubud");
  std::string s1("what time are we climbing up the volcano");

  if (highestScoringWord(s0).compare("taxi") == 0 &&
      highestScoringWord(s1).compare("volcano") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
