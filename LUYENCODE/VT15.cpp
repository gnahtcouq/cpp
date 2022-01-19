#include <iostream>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] > a[j])
        swap(a[i], a[j]);

  int x = a[0] * a[1] * a[n - 1];
  int y = a[n - 1] * a[n - 2] * a[n - 3];

  if (x < y)
    cout << y;
  else
    cout << x;

  return 0;
}