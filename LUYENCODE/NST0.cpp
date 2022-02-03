#include <iostream>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int sum = 0, max = 0;
  for (int i = 0; i < n; ++i) {
    sum = a[i];
    for (int j = i; j < n; ++j) {
      if (i != j)
        sum += a[j];
      if (sum >= 0 && (j + 1 - i) > max)
        max = j + 1 - i;
    }
  }

  if (max)
    cout << max;
  else
    cout << -1;


  return 0;
}