#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[3], n = 3;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  int b[3], m = 3;
  b[0] = 5;
  b[1] = 5;
  b[2] = 7;

  if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
    cout << "YES";
  else
    cout << "NO";

  return 0;
}