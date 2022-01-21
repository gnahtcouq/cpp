#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[100000], b[100000], n, L;
  cin >> n >> L;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];

  int dukien[100000], d = 0;
  for (int i = 0; i < n * 2; i++)
    if (i % 2 != 0)
      dukien[d++] = a[i] - a[i - 1] + 1;

  int max_dukien = dukien[0];
  for (int i = 0; i < d; i++)
    if (dukien[i] > max_dukien)
      max_dukien = dukien[i];

  for (int i = 0; i < L; i++)
    b[i] = 0;

  int lop = n + 1;
  for (int i = (n * 2) - 1; i >= 0; i--) {
    if (i % 2 == 0) {
      lop--;
      for (int j = a[i] - 1; j < a[i + 1]; j++)
        for (int k = 0; k < L; k++)
          b[j] = lop;
    }
  }

  sort(b, b + L);
  int max_thucte = 0, dem_max_thucte = 1;
  for (int i = 0; i < L; i++) {
    if (b[i] != 0 && b[i] == b[i + 1]) {
      dem_max_thucte++;
      if (dem_max_thucte > max_thucte)
        max_thucte = dem_max_thucte;
    }
    else
      dem_max_thucte = 1;
  }

  cout << max_dukien << " " << max_thucte;

  return 0;
}