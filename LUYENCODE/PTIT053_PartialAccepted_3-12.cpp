#include <iostream>
#include <math.h>
using namespace std;

int sum(int n) {
  if (n < 10)
    return n;
  return sum((n % 10) + sum(n / 10));
}

int kiemtraSNT(int n) {
  if (n < 2)
    return 0; // Khong thoa
  else if (n > 2) {
    if (n % 2 == 0)
      return 0; // Khong thoa
    for (int i = 3; i <= (int)sqrt((double)n); i += 2) {
      if (n % i == 0)
        return 0; // Khong thoa
    }
  }
  return 1; // Thoa
}


int main() {
  long long l, r;
  cin >> l >> r;

  int count = 0;
  for (int i = l + 1; i <= r; ++i)
    if (kiemtraSNT(sum(i)))
      count++;
  cout << count;

  return 0;
}