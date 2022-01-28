#include <iostream>
#include <math.h>
#include <string>
using namespace std;

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
  string s;
  getline(cin, s);

  for (int i = 0; i < (int)s.length(); ++i)
    if (kiemtraSNT(i))
      s[i] = '*';

  cout << s;

  return 0;
}