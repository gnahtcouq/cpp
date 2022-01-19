#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[100000], b[100000], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int dem = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1])
      dem++;
    else {
      b[m++] = a[i - 1];
      b[m++] = dem;
      dem = 1;
    }
  }

  int max = b[1], rev;
  for (int i = 0; i < m; i++)
    if (i % 2 != 0 && b[i] > max)
      max = b[i];
  for (int i = 0; i < m; i++)
    if (b[i] == max)
      rev = b[i - 1];
  cout << rev << " " << max;

  return 0;
}