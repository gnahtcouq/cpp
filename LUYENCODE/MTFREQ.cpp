#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[100000], b[100000], n, x = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  b[0] = a[0];
  for (int i = 1; i < n; i++) {
    int dem = 0;
    for (int j = 0; j < x; j++)
      if (a[i] == a[j])
        dem++;
    if (dem == 0) {
      b[x] = a[i];
      x++;
    }
  }
  cout << x << endl;
  for (int j = 0; j < x; j++) {
    int dem = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == b[j])
        dem++;
    cout << b[j] << " " << dem << endl;
  }

  return 0;
}