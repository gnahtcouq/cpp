#include <iostream>
using namespace std;

int timMin(int a[], int n, int& posMin) {
  int min = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] < min) {
      min = a[i];
      posMin = i + 1;
    }
  return min;
}

int timMax(int a[], int n, int& posMax) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max) {
      max = a[i];
      posMax = i + 1;
    }
  return max;
}

int main() {
  int a[100000], b[100000], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int posMin = 0, posMax = 1;
  b[m++] = timMin(a, n, posMin);
  b[m++] = posMin;
  b[m++] = timMax(a, n, posMax);
  b[m++] = posMax;

  for (int i = 0; i < m; i++)
    cout << b[i] << " ";

  return 0;
}