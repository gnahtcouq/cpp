#include <iostream>
using namespace std;

int timMax(int a[], int n) {
  int max = a[0];
  for (int i = 0; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}

int main() {
  int a[100000], b[100000], n, m = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int can, rev;
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      rev = a[0] + a[n - 1];
    else {
      can = a[i] + a[i + 1];
      b[m++] = can;
    }
  }
  b[m++] = rev;

  int max = timMax(b, m);

  for (int i = m - 1; i >= 0; i--) {
    if (i == n - 1) {
      if (max == a[0] + a[n - 1]) {
        cout << a[n - 1] << " " << a[0];
        break;
      }
    }
    else {
      if (max == a[i] + a[i + 1]) {
        cout << a[i] << " " << a[i + 1];
        break;
      }
    }
  }

  return 0;
}