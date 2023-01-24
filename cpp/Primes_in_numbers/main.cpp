#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

bool isPrime(int number) {
  if (number < 2) return false;
  if (number == 2) return true;
  if (number % 2 == 0) return false;
  for (int i = 3; (i * i) <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}

std::map<int, int> getPrimes(int lst) {
  std::map<int, int> primes;

  for (int i = 2; i <= lst; ++i) {
    if (i == 2 || (i > 2 && i % 2 != 0)) {
      if (isPrime(i) == true && lst % i == 0) {
        if (primes.find(i) == primes.end()) {
          primes.insert(std::pair<int, int>(i, 1));
        } else {
          ++primes[i];
        }
        lst /= i;
        i = 1;
      }
    }
  }
  return primes;
}

class PrimeDecomp {
 public:
  static std::string factors(int lst) {
    std::map<int, int> primes = getPrimes(lst);

    std::string res;

    for (auto [key, value] : primes) {
      res += '(';
      if (value == 1)
        res += std::to_string(key);
      else {
        res += std::to_string(key);
        res += "**";
        res += std::to_string(value);
      }
      res += ')';
    }
    return res;
  }
};

int main() {
  PrimeDecomp pd;

  std::cout << pd.factors(7775460) << '\n';

  if (pd.factors(7775460).compare("(2**2)(3**3)(5)(7)(11**2)(17)") == 0 &&
      pd.factors(7919).compare("(7919)") == 0)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
