#include <iostream>
using namespace std;

int main() {
  long long m, n, k;
  cin >> m >> n >> k;

  if (m >= 0 && n >= 0 && k >= 0)
    cout << m * n / k;

  return 0;
}