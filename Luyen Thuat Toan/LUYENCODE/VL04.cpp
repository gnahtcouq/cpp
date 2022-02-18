#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;

  double sum = 0;
  if (n >= 2) {
    for (double i = 2; i <= n; i++)
      sum += 1 / i;
    cout << setprecision(4) << fixed << sum;
  }

  return 0;
}