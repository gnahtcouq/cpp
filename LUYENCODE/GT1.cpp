#include <iostream>
using namespace std;

int main() {
  int n, tich = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    tich *= i;
  cout << tich;

  return 0;
}