// Tinh s(x, n) = x^n

/*
    Ta can biet:
  + Voi n > 0 (vi du la 3) -> x^3 chinh la: x * x * x
  + Voi n < 0 (vi du la -3) -> x^-3 chinh la: 1 / (x^3) = 1/x * 1/x * 1/x
*/

#include <iostream>
using namespace std;

float deQuy(float x, int n) {
  if (n == 1)
    return x;
  if (n == -1)
    return 1.0 / x;
  if (n < 0)
    return deQuy(x, n + 1) * 1.0 / x;
  else if (n == 0)
    return 1;
  return deQuy(x, n - 1) * x;
}

int khuDeQuy(float x, int n) {
  bool check = true; // Mac dinh > 0
  int tich = 1;
  if (n == 0)
    return tich;
  else if (n < 0) {
    check = false;
    n *= -1; // Bien thanh duong lai
  }
  for (int i = 1; i <= n; i++)
    tich *= x;
  if (check == true)
    return tich;
  return 1.0 / tich;
}

float deQuyDuoi(float x, int n, int y = 1) {
  if (n == 0)
    return y;
  if (n < 0)
    return deQuyDuoi(x, n + 1, y * 1.0 / x);
  else if (n == 0)
    return 1;
  return deQuyDuoi(x, n - 1, y * x);
}


int main() {
  float x = 2;
  int n = 8;

  cout << "\nTong deQuy(" << n << ") = " << deQuy(x, n);
  cout << "\nTong khuDeQuy(" << n << ") = " << khuDeQuy(x, n);
  cout << "\nTong deQuyDuoi(" << n << ") = " << deQuyDuoi(x, n);

  cout << endl;
  return 0;
}