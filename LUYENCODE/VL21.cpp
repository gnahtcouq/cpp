#include <iostream>
using namespace std;

int main() {
  long long x, tong = 0;
  cin >> x;

  for (long long i = 1; i <= x; i++) {
    tong += i;
    if (tong > x) {
      x = i - 1;
      break;
    }
  }
  cout << x;

  return 0;
}