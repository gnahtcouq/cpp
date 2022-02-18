#include <iostream>
#include <math.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = 0;

  if (n > 0) {
    for (long long i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        int j = n / i;
        if (i == j)
          sum += i;
        else
          sum += i + j;
      }
    }
  }

  cout << sum;

  return 0;
}