#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[500000], b[500000], c[500000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    c[i] = a[i];

  for (int i = 2 * n - 1; i >= 0; i--) {
    if ((i - n) < 0)
      break;
    c[i] = b[i - n];
  }

  sort(c, c + n * 2);
  for (int i = 0; i < n * 2; i++)
    cout << c[i] << " ";

  return 0;
}