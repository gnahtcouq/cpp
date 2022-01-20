#include <iostream>
using namespace std;

int main() {
  int a[10000], C1, n;
  int b[10000], m = 0;
  cin >> C1 >> n;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];

  // for (int i = 0; i < n * 2; i++)
  //   cout << a[i] << " ";

  int count = 1;
  int giucovodich;

  // i    = 0 1 2 3 4 5
  // a[i] = 2 1 3 2 4 1

  for (int i = 0; i < n * 2; i++) {
    if (a[i] % 2 == 0) {
      if (a[i + 1] == C1) {
        b[m] = a[i];
        count++;
      }
      i += 2;
      if (a[i + 1] == b[m]) {
        b[m] = a[i];
        count++;
      }
      i += 2;
      if (a[i + 1] != b[m])
        giucovodich = a[i];
    }
  }

  cout << "\n\n\n\n";


  for (int i = 0; i <= m; i++)
    cout << b[i] << " ";

  cout << "\n\n\n\n";

  cout << giucovodich << " " << count;
  return 0;
}