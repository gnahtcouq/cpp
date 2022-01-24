#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n >= 2)
    cout << n * (n + 1) / 2 - 1 + 2 * n;

  return 0;
}