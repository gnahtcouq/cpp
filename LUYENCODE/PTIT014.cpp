#include <iostream>
#include <math.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n <= 60)
    cout << (long long)(pow(2, n)) % 10;

  return 0;
}