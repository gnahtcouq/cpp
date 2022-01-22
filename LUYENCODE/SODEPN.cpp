#include <iostream>
using namespace std;

int main() {
  int n, c;
  cin >> n;

  int b[100000], m = 0;
  while (n != 0) {
    c = n % 10;
    n /= 10;
    b[m++] = c;
  }

  int tong = 0;
  for (int i = 0; i < m; i++)
    tong += b[i];

  int check = tong % 10;

  if (check == 9)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}