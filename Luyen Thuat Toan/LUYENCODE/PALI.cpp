#include <iostream>
using namespace std;


bool check(int n) {
  int a[10000], b[10000];
  int i = 0;

  for (;n != 0;) {
    a[i] = n % 10;
    n /= 10;
    i++;
  }

  int h = 0;
  for (int k = i - 1; k >= 0; k--) {
    b[h] = a[k];
    h++;
  }

  int count = 0;
  for (int k = 0; k < i; k++)
    if (a[k] == b[k])
      count++;

  if (count == i)
    return true;
  return false;
}

int main() {
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    if (check(a[i]))
      cout << a[i] << " ";

  return 0;
}