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

  if (a[0] < 0 && a[1] < 0)
    cout << a[0] * a[1];
  else
    cout << a[n - 1] * a[n - 2];
  return 0;
}