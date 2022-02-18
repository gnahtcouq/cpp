#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int tich = a * b;
  if (tich > 0)
    cout << 1;
  else if (tich < 0) cout << -1;
  else cout << 0;

  return 0;
}