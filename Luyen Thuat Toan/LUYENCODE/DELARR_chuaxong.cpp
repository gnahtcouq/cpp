#include <iostream>
#include <algorithm>
using namespace std;

void xoaPhanTu(int a[], int& n, int vitrixoa) {
  for (int i = vitrixoa + 1; i < n; i++)
    a[i - 1] = a[i];
  n--;
}

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  int tong = 0;
  int countMin = 0;
  int countMax = 0;

  for (int i = 0; i < n; i++) {
    tong += a[i];
    if (a[0] == a[i])
      countMin++;
    if (a[n - 1] == a[i])
      countMax++;
  }
  cout << "\ncountMin = " << countMin;
  cout << "\ncountMax = " << countMax;


  if (tong - a[0] == 0 || tong - a[n - 1] == 0)
    cout << countMin + countMax;

  return 0;
}