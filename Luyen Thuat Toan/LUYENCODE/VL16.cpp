#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a * b != 0)
    cout << abs((a * b) / __gcd(a, b));

  return 0;
}