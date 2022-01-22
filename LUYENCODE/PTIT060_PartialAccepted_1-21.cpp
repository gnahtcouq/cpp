#include <iostream>
using namespace std;

int main() {
  int a[100000], n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  k %= n;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n - 1; j++)
      swap(a[j], a[j + 1]);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";

  return 0;
}