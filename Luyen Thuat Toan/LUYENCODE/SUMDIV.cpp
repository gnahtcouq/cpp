#include <iostream>
#include <math.h>
using namespace std;

int cp(int n) {
  int x = sqrt(n);
  if (x * x == n) return 1;
  else return 0;
}

int sum(int n) {
  int sum = 0;
  for (int i = 1; i < sqrt(n); i++)
    if (n % i == 0)
      sum += i + n / i;
  if (cp(n) == 1)
    sum += sqrt(n);
  return sum;
}

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    cout << sum(n) << endl;
  }

  return 0;
}