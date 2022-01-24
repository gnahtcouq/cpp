#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i <= (3 * n) + 1; i++)
    sum += (pow(-1, i + 1)) * i;
  cout << sum;

  return 0;
}