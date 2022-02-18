#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int t;
  cin >> t;
  double n, s;
  while (t--) {
    s = 0;
    cin >> n;
    s = (2 * n) / (n + 1);
    cout << setprecision(8) << fixed << s << "\n";
  }

  return 0;
}