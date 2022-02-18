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

  int chenhlechlonhat;
  for (int i = 0; i < n; i++)
    chenhlechlonhat = a[n - 1] - a[0];

  cout << chenhlechlonhat;

  return 0;
}