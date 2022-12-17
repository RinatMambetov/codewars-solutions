#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

// class Transform {
//  public:
//   static int operation(int a, int b) {
//     if (a == b) return 0;
//     if (a < b) {
//       return static_cast<int>(sqrt(b / a));
//     } else if (a > b) {
//       int counter(0);
//       while (a != b) {
//         if (a % 2 == 0) {
//           a /= 2;
//         } else {
//           a = (a - 1) / 2;
//         }
//         ++counter;
//       }
//       return counter;
//     }
//     return 0;
//   }
// };

class Transform {
 public:
  static int operation(int a, int b) {
    return a == b ? 0 : 1 + operation(a > b ? a >> 1 : a, a > b ? b : b >> 1);
  }
};

int main() {
  Transform tr;
  if (tr.operation(1, 1) == 0 && tr.operation(4, 1) == 2 &&
      tr.operation(1, 4) == 2 && tr.operation(2, 8) == 2)
    std::cout << "Well done!\n";
  else
    std::cout << "Wrong!\n";

  return 0;
}
