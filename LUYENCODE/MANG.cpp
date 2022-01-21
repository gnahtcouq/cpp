#include <iostream>
using namespace std;

int kiemTraMangToanDuong(int a[], int n) {
  int i = 0;
  while ((i < n) && (a[i] <= 0)) i++;
  if (i == n) return -1;
  else return 0;
}

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int tong = 0, demChan = 0;
  for (int i = 0; i < n; i++) {
    tong += a[i];
    if (a[i] % 2 == 0)
      demChan++;
  }
  cout << tong << " " << demChan << " ";

  if (kiemTraMangToanDuong(a, n) == -1)
    cout << 0;
  else {
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > 0) {
        cout << a[i];
        break;
      }
    }
  }

  return 0;
}