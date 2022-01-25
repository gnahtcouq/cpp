#include <iostream>
#include <iomanip>
using namespace std;

const double pi = 3.141592653589793238462643;

int main() {
  double a;
  cin >> a;

  // double s_hinhtron = pi * a * a;
  // double s_1_4_hinhtron = s_hinhtron / 4;
  // double s_tamgiacvuong = (1 / 2) * a * a;

  // cout << setprecision(3) << fixed << (s_tamgiacvuong * 2) + ((s_1_4_hinhtron - s_tamgiacvuong) * 2);

  cout << setprecision(3) << fixed << pi * a * a / 2;

  return 0;
}