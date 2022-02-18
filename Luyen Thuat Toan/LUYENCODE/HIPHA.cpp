#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int posInit = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1)
      posInit--;
    else if (a[i] == 2)
      posInit++;
  }
  cout << abs(posInit);

  return 0;
}