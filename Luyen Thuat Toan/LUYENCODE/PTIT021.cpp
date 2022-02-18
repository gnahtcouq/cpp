#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int min = a[0], max = a[0];
  for (int i = 0; i < n; i++)
    if (a[i] < min)
      min = a[i];

  for (int i = 0; i < n; i++)
    if (a[i] > max)
      max = a[i];

  int count = 0;
  for (int i = min; i <= max; i++)
    count++;

  cout << abs(n - count);

  return 0;
}