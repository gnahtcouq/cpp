#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int d, m, y;
    cin >> d >> m >> y;
    if ((d < 1 || d > 31) || (m < 1 || m > 12) || (y < 1990 || y > 3000))
      cout << "FALSE\n";
    else if (m == 2 && d > 28) {
      if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        if (d > 29)
          cout << "FALSE\n";
        else
          cout << "TRUE\n";
      }
      else
        cout << "FALSE\n";
    }
    else
      cout << "TRUE\n";
  }
  return 0;
}