#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = abs(n) - 1; i > 0; i--)
    if (abs(n) % i == 0)
      sum += i;

  if (sum == n)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}