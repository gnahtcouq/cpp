#include <iostream>
using namespace std;

int main() {
  long long n, n1, sum = 0;
  cin >> n;

  n1 = n;

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  if (n1 % sum == 0)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}