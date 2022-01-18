#include <iostream>
#include <math.h>
using namespace std;

int kiemtraSNT(int n) {
  if (n < 2)
    return 0;
  else if (n > 2) {
    if (n % 2 == 0)
      return 0;
    for (int i = 3; i <= (int)sqrt((double)n); i += 2) {
      if (n % i == 0)
        return 0;
    }
  }
  return 1;
}

void sapXep(int& a, int& b) {
  int tam = a;
  a = b;
  b = tam;
}

int main() {
  int a[100], b[100], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    if (kiemtraSNT(a[i]) == 1)
      b[m++] = a[i];

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++)
      if (b[i] > b[j])
        sapXep(b[i], b[j]);
    if (b[i] != b[i - 1])
      cout << b[i] << " ";
  }

  return 0;
}