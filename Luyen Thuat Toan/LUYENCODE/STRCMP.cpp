#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (n < m)
    while (m--)
      cout << n;
  else
    while (n--)
      cout << m;

  return 0;
}