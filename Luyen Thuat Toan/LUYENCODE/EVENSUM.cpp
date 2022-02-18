#include <iostream>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int tong = 0;
  for (int i = 0; i < n; i++)
    if (i % 2 != 0)
      tong += a[i];

  cout << tong;

  return 0;
}