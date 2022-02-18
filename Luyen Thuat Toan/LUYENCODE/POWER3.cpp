#include <iostream>
#include <math.h>
using namespace std;

int main() {
  short t;
  cin >> t;
  long long n, x1;
  double x;

  while (t--) {
    cin >> n;
    x = pow(n, 1.0 / 3);
    x1 = (long long)x;
    if (x1 * x1 * x1 == n || (x1 + 1) * (x1 + 1) * (x1 + 1) == n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}