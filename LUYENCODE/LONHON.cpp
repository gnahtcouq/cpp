#include <iostream>
#include <climits>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = 0; i < INT_MAX; ++i) {
    if (i > 0) {
      a *= 3;
      b *= 2;
    }
    if (a > b) {
      cout << i;
      return 0;
    }
  }

  return 0;
}