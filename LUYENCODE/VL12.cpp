#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 0)
    cout << "INF";
  else {
    for (int i = abs(n); i > 0; i--)
      if (abs(n) % i == 0)
        cout << i << " ";
  }

  return 0;
}