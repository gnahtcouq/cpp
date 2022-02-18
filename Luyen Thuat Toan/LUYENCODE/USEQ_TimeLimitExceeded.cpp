#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int* a = new int[1000000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int* b = new int[1000000];
  int m = 0;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      count++;
    else {
      b[m++] = a[i - 1];
      b[m++] = count;
      count = 1;
    }
  }
  b[m++] = a[n - 1];
  b[m++] = count;

  for (int i = 0; i < m; i++)
    if (i % 2 != 0)
      if (b[i] % 2 != 0)
        cout << b[i - 1];

  delete[] a;
  delete[] b;

  return 0;
}