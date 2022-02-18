#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  for (int i = 0; i <= 30; ++i)
    cout << n << " x " << i << " = " << n * i << endl;

  return 0;
}