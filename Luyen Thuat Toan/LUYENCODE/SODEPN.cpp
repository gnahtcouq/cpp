#include <iostream>
using namespace std;

int main() {
  int n, tong = 0;
  cin >> n;

  while (n != 0) {
    tong += n % 10;
    n /= 10;
  }

  if (tong % 10 == 9)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}