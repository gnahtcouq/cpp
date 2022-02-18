#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a;
  cin >> a;

  a = abs(a);
  int count = 0;
  for (int i = a; i > 0; i--)
    if (a % i == 0)
      count++;

  cout << count;

  return 0;
}
