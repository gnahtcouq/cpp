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
  int a[100000], n;
  int b[100000], m = 0;
  int c[100000], k = 0;
  int d[100000], e = 0;

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
  // for (int i = 0; i < m; i++) {
  //   cout << b[i] << " ";
  // }
  int max = timMax(b, m);
  // cout << "\nmax = " << max;
  // cout << "\n\n\n";
  int check = 0;
  for (int i = 0; i < m; i++) {
    if (i == n - 1) {
      if (max == a[0] + a[n - 1]) {
        // cout << a[0] << " " << a[n - 1];
        c[k++] = a[0];
        c[k++] = a[n - 1];
        check++;
      }
    }
    else {
      if (max == a[i] + a[i + 1]) {
        // cout << a[i] << " " << a[i + 1];
        c[k++] = a[i];
        c[k++] = a[i + 1];
        check++;
      }
    }
  }

  // if (check > 1) {
  //   for (int i = m - 1; i >= 0; i--) {
  //     if (i == n - 1) {
  //       if (max == a[0] + a[n - 1]) {
  //         d[e++] = a[0];
  //         d[e++] = a[n - 1];
  //         break;
  //       }
  //     }
  //     else {
  //       if (max == a[i] + a[i - 1]) {
  //         d[e++] = a[i];
  //         d[e++] = a[i - 1];
  //         break;
  //       }
  //     }
  //   }
  // }

  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++)
      if (c[i] < c[j])
        swap(c[i], c[j]);
    if (check == 1)
      cout << c[i] << " ";
  }

  // for (int i = 0; i < e; i++) {
  //   for (int j = i + 1; j < e; j++)
  //     if (d[i] < d[j])
  //       swap(d[i], d[j]);
  //   if (check > 1)
  //     cout << d[i] << " ";
  // }

  return 0;
}