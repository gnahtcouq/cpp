#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[100000], b[100000], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n, greater<int>());

  int count_1 = n / 2, giatricuoi;
  for (int i = 0; i < count_1; i++) {
    b[m++] = a[i];
    giatricuoi = a[count_1 - 1];
  }

  int solanthem = 0;
  for (int i = 0; i < m; i++)
    if (b[i] == giatricuoi)
      solanthem++;

  int min = b[m - 1];

  int count_2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == min) {
      b[m++] = a[i + 1];
      count_2++;
    }
  }

  cout << count_1 + count_2 - solanthem;

  return 0;
}