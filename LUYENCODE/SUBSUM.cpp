#include <iostream>
using namespace std;

int main() {
  long long a, b, x, y;
  cin >> a >> b;

  y = (b - a) / (-2);
  x = a - y;
  cout << x << " " << y;

  return 0;
}