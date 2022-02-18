#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (b == 0) {
    cout << "INVALID";
    exit(0);
  }

  float result = (float)a / b;

  int ucln = __gcd(a, b);
  a /= ucln;
  b /= ucln;

  if (b < 0) {
    b *= -1;
    a *= -1;
  }

  if (b != 1)
    cout << a << " " << b;
  else
    cout << a;

  return 0;
}