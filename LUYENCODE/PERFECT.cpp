#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  int a[100000], n, res = INT_MAX;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  for (int i = 1; i < n; i++)
    res = min(res, a[i] - a[i - 1]);

  cout << res;

  return 0;
}