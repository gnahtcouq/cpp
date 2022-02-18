#include <iostream>
using namespace std;

int main() {
  double n, x, y;
  int n_2, a, b;

  cin >> n;
  n_2 = (int)n;

  if (n >= 0) {
    a = n_2 + 1;
    b = n_2;

    x = a - n;
    y = n - b;
    if (x < y || x == 0.5)
      cout << a;
    else
      cout << b;
  }
  else {
    a = n_2 - 1;
    b = n_2;

    x = a - n;
    y = n - b;
    if (x < y || x == 0.5)
      cout << b;
    else
      cout << a;
  }

  return 0;
}