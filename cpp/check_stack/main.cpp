#include <sys/resource.h>

#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

int main(void) {
  struct rlimit limit;

  getrlimit(RLIMIT_STACK, &limit);
  printf("\nStack Limit = %llu and %llu max\n", limit.rlim_cur, limit.rlim_max);
}
