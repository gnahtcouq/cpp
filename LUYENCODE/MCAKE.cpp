#include <iostream>
using namespace std;

int main() {
  int a[100000], b[100000], n, L;
  cin >> n >> L;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];

  cout << "\n";
  int dukien[100000], d = 0;
  for (int i = 0; i < n * 2; i++)
    if (i % 2 != 0)
      dukien[d++] = a[i] - a[i - 1];

  for (int i = 0; i < d; i++)
    cout << dukien[i] << " ";

  cout << "\n";

  for (int i = 0; i < L; i++)
    b[i] = 0;

  for (int i = 0; i < L; i++)
    cout << b[i] << " ";

  int dem = n + 1;
  for (int i = (n * 2) - 1; i >= 0; i--) {
    if (i % 2 == 0) {
      dem--;
      for (int j = a[i] - 1; j < a[i + 1]; j++)
        for (int k = 0; k < L; k++)
          b[j] = dem;
    }
  }

  cout << "\n";

  for (int i = 0; i < L; i++)
    cout << b[i] << " ";



  return 0;
}