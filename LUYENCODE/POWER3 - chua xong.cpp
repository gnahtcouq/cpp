#include <iostream>
#include <math.h>
using namespace std;

int main() {
  long long n[100000];
  short t;
  cin >> t;
  for (int i = 0; i < t; i++)
    cin >> n[i];

  double a[100000], x;
  int m = 0;
  for (int i = 0; i < t; i++) {
    x = pow(n[i], 1.0 / 3);
    a[m++] = x;
    a[m++] = (long long)x;
  }

  for (int i = 0; i < m; i++)
    cout << a[i] << " ";

  // for (int i = 0; i < m; i++) {
  //   if (i % 2 != 0) {
  //     if (a[i] * a[i] * a[i] == a[i - 1] || (a[i] + 1) * (a[i] + 1) * (a[i] + 1) == a[i - 1])
  //       cout << "YES" << endl;
  //     else
  //       cout << "NO" << endl;
  //   }
  // }


  return 0;
}