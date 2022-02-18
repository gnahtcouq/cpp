#include <iostream>
using namespace std;

int main() {
  int a[50], b[50];
  int n = 11, m = 0;
  int sothumuoimot;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sothumuoimot = a[10];
    if (m == 10)
      break;
    b[m++] = a[i];
  }
  int flag = 0;
  for (int i = 0; i < m; i++) {
    // cout << b[i] << " ";
    if (b[i] == sothumuoimot) {
      cout << i + 1 << " ";
      flag = 1;
    }
  }
  if (flag == 0)
    cout << -1;
  return 0;
}