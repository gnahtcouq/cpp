#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int l, r;
  cin >> l >> r;

  int count = 0;
  for (int i = l + 1; i < r; ++i) {
    int j = sqrt(i);
    if (j * j == i)
      count++;
  }
  cout << count;

  return 0;
}