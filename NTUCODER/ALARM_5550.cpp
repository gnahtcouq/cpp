#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
  int h = 0, m = 0;
  while (h < 24) {
    if (a[h / 10] + a[h % 10] + a[m / 10] + a[m % 10] == n) {
      printf("%02d:%02d", h, m);
      return 0;
    }
    m++;
    if (m == 60) {
      m = 0;
      h++;
    }
  }
  cout << "Impossible";

  return 0;
}