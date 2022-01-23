#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  int a, b, c;
  float x1, x2;
  cin >> a >> b >> c;
  int delta = b * b - 4 * a * c;

  if (a == 0) {
    if (b == 0) {
      if (c == 0)
        cout << "INF";
      else
        cout << "NO";
    }
    else if (b > 0)
      cout << setprecision(2) << fixed << (float)(-c) / b;
    else if (b < 0) {
      if (c == 0) {
        b = abs(b);
        cout << setprecision(2) << fixed << (float)(-c) / b;
      }
      else if (c != 0)
        cout << setprecision(2) << fixed << (float)(-c) / b;
    }
  }
  else {
    if (delta > 0) {
      x1 = ((-b - sqrt(delta)) / (2 * a));
      x2 = ((-b + sqrt(delta)) / (2 * a));
      if (x1 < x2)
        cout << setprecision(2) << fixed << x1 << " " << x2;
      else
        cout << setprecision(2) << fixed << x2 << " " << x1;
    }
    else if (delta < 0)
      cout << "NO";
    else
      cout << setprecision(2) << fixed << (float)-b / (2 * a);
  }

  return 0;
}