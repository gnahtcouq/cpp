#include <iostream>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (i == 1 && a[1] == a[0])
      dem++;
    if (i == n - 1 && a[n - 1] == a[n - 2])
      dem++;
    if (i > 1 && i < n - 1)
      if (a[i] == a[i + 1])
        dem++;
  }
  cout << dem;

  return 0;
}