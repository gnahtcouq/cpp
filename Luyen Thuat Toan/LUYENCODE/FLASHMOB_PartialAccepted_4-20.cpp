#include <iostream>
using namespace std;

int main() {
  int a[10000], C1, n;

  cin >> C1 >> n;
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];

  int count = 1, giucovodich, check = 0;

  for (int i = 0; i < n * 2; i++) {
    if (check == 0 && i % 2 == 0 && a[i + 1] == C1) {
      giucovodich = a[i];
      check = 1;
      count++;
      i += 2;
    }
    if (check != 0 && i % 2 == 0 && a[i + 1] == giucovodich) {
      giucovodich = a[i];
      count++;
      i += 2;
    }
  }

  cout << giucovodich << " " << count;

  return 0;
}