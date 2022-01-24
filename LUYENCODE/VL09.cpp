#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  int n, tam = 1;
  double x, tong = 0;
  cin >> n >> x;

  for (int i = 1; i <= n; i++) {
    tam *= i;
    tong += (pow(x, i) / tam);
  }
  cout << setprecision(2) << fixed << tong;

  return 0;
}