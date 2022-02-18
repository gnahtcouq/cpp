#include <iostream>
using namespace std;

int main() {
  int a[100], n, chenhlech;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < n; ++i) {
    if (i != n - 1 && i % 2 != 0) {
      chenhlech = abs(a[i + 1] - a[i - 1]);
      a[i] += chenhlech;
    }
    if (i == n - 1 && i % 2 != 0)
      a[i] += a[i - 1];
  }

  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  return 0;
}