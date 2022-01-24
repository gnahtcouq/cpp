#include <iostream>
using namespace std;

int main() {
  int a[3], n = 3, b[3], m = 3;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  int count_a = 0, count_b = 0;

  if (a[0] > b[0])
    count_a++;
  else if (a[0] == b[0]) {
    count_a += 0;
    count_b += 0;
  }
  else
    count_b++;

  if (a[1] > b[1])
    count_a++;
  else if (a[1] == b[1]) {
    count_a += 0;
    count_b += 0;
  }
  else
    count_b++;

  if (a[2] > b[2])
    count_a++;
  else if (a[2] == b[2]) {
    count_a += 0;
    count_b += 0;
  }
  else
    count_b++;

  cout << count_a << " " << count_b;

  return 0;
}