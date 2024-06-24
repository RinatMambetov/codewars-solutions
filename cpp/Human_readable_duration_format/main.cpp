#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {
  if (seconds == 0) return "now";
  int y = 0;
  int d = 0;
  int h = 0;
  int m = 0;
  int s = seconds;
  if (s > 59) {
    m = s / 60;
    s %= 60;
  }
  if (m > 59) {
    h = m / 60;
    m %= 60;
  }
  if (h > 23) {
    d = h / 24;
    h %= 24;
  }
  if (d > 364) {
    y = d / 365;
    d %= 365;
  }
  // std::cout << y << '\n' << d << '\n' << h << '\n' << m << '\n' << s << '\n';
  std::stringstream res;
  if (y == 1) {
    res << "1 year";
  } else if (y > 1) {
    res << y << " years";
  }
  if (y && (d || h || m)) {
    res << ", ";
  } else if (y) {
    res << " and ";
  }

  if (d == 1) {
    res << "1 day";
  } else if (d > 1) {
    res << d << " days";
  }
  if (d && (h || m)) {
    res << ", ";
  } else if (d && h && !m && !s) {
    res << " and";
  }

  if (h == 1) {
    res << "1 hour";
  } else if (h > 1) {
    res << h << " hours";
  }
  if (h && m && s) {
    res << ", ";
  } else if ((y || d || h) && m && !s) {
    res << " and ";
  }

  if (m == 1) {
    res << "1 minute";
  } else if (m > 1) {
    res << m << " minutes";
  }
  if ((y || d || h || m) && s) {
    res << " and ";
  }

  if (s == 1) {
    res << "1 second";
  } else if (s > 1) {
    res << s << " seconds";
  }
  return res.str();
}

int main() {
  // std::cout << format_duration(0) << '\n';     // now
  // std::cout << format_duration(1) << '\n';
  // std::cout << format_duration(62) << '\n';  // 1 minute and 2 seconds
  // std::cout << format_duration(60) << '\n';
  std::cout << format_duration(120) << '\n';
  // std::cout << format_duration(3662) << '\n';
  // std::cout << format_duration(366200) << '\n';
  // std::cout << format_duration(36620000) << '\n';
  // std::cout << format_duration(366200000) << '\n';
  // seconds

  return 0;
}
