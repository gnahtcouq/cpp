#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;

  if (a + b <= c || b + c <= a || a + c <= b)
    cout << "NO";
  else {
    double chuvi = a + b + c;
    double nuachuvi = (a + b + c) / 2;
    double dientich = (sqrt(nuachuvi * (nuachuvi - a) * (nuachuvi - b) * (nuachuvi - c)));
    cout << chuvi << " ";
    cout << setprecision(2) << fixed << dientich;
  }

  return 0;
}