#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  float a, b, toanhang;
  char pheptinh;
  cin >> a >> pheptinh >> b;
  switch (pheptinh) {
  case '+':
    cout << fixed << setprecision(2) << a + b;
    break;
  case '-':
    cout << fixed << setprecision(2) << a - b;
    break;
  case '*':
    cout << fixed << setprecision(2) << a * b;
    break;
  case '/':
    if (b == 0)
      cout << "Math Error";
    else
      cout << fixed << setprecision(2) << a / b;
    break;
  }

  return 0;
}