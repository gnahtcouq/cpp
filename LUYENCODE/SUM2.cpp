#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long tong = 0;
  for (long i = 1; i <= n; i++)
    tong += i * i;
  cout << tong;

  return 0;
}