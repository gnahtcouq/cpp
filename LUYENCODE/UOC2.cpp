#include <iostream>
#include <math.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  faster();
  int a, b;
  cin >> a >> b;

  int GCD = gcd(a, b);
  int tong = 0;
  for (int i = 1; i <= sqrt(GCD); i++) {
    if (GCD % i == 0) {
      tong += i;
      if (GCD / i != i)
        tong += GCD / i;
    }
  }

  cout << tong;

  return 0;
}