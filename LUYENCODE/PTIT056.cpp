#include <iostream>
#include <math.h>
using namespace std;

int tongcacchuso(long long n) {
  long long sotachra;
  long long s = 0;;
  for (;n != 0;) {
    sotachra = n % 10;
    s += sotachra;
    n /= 10;
  }
  return s;
}

bool kiemtraSNT(long long n) {
  if (n < 2)
    return false; // Khong thoa
  else if (n > 2) {
    if (n % 2 == 0)
      return false; // Khong thoa
    for (int i = 3; i <= (long long)sqrt((double)n); i += 2) {
      if (n % i == 0)
        return false; // Khong thoa
    }
  }
  return true; // Thoa
}

int main() {
  long long n;
  cin >> n;

  if (kiemtraSNT(n) == true && kiemtraSNT(tongcacchuso(n)) == true)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}