#include <iostream>
#include <time.h>
using namespace std;

// Bai 733
// 1/2 + 1/4 + ... + 1/2n

float deQuy(int n) {
  if (n == 1)
    return 1.0/2;
  return deQuy(n - 1) + 1.0 / (2*n);
}

float khuDeQuy(int n) {
  float tong = 0;
  for (int i = 1; i <= n; i++)
    tong += 1.0 / (2 * i);
  return tong;
}

float deQuyDuoi(int n, float x = (float) 1/2) {
  if (n == 1)
    return x;
  return deQuyDuoi(n - 1, x + 1.0 / (2 * n));
}


int main() {

  int n = 2;

  cout << "\nTong deQuy(" << n << ") = " << deQuy(n);
  cout << "\nTong khuDeQuy(" << n << ") = " << khuDeQuy(n);
  cout << "\nTong deQuyDuoi(" << n << ") = " << deQuyDuoi(n);

  cout << endl;
  return 0;
}