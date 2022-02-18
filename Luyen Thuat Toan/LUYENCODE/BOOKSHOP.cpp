#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n, greater<int>());

  long long sum = 0;
  for (int i = 0; i < n; ++i)
    if ((i + 1) % 3 != 0)
      sum += a[i];

  cout << sum;

  return 0;
}