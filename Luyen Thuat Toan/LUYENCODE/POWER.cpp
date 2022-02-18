#include <iostream>
using namespace std;

int main() {
  short n;
  cin >> n;

  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0) {
      if (a < 0)
        a = -a;
      if (b < 0)
        b = -b;
    }
    if (c == 0)
      cout << "=\n";
    else if (a > b)
      cout << ">\n";
    else if (a == b)
      cout << "=\n";
    else
      cout << "<\n";
  }

  return 0;
}