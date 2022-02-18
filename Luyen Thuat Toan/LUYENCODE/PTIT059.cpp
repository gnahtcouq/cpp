#include <iostream>
using namespace std;

void themPhanTu(int a[], int& n, int vitrithem, int phantuthem) {
  for (int i = n - 1; i >= vitrithem; i--)
    a[i + 1] = a[i];
  a[vitrithem] = phantuthem;
  n++;
}

int main() {
  int a[100000], n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> x;

  if (x <= a[0])
    themPhanTu(a, n, 0, x);
  if (x >= a[n - 1])
    themPhanTu(a, n, n, x);

  if (x > a[0] && x < a[n - 1]) {
    for (int i = 0; i < n; i++)
      if (x <= a[i]) {
        themPhanTu(a, n, i, x);
        break;
      }
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  return 0;
}