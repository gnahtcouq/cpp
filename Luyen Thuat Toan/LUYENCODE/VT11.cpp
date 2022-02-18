#include <iostream>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n - 1; i++)
    for (int j = i + 1; j < n - 1; j++)
      if (a[i] > a[j])
        swap(a[i], a[j]);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}