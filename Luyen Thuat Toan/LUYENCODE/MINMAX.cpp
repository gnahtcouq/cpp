#include <iostream>
using namespace std;

int timMin(int a[], int n) {
  int min = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] < min)
      min = a[i];
  // posMin = i + 1;
  return min;
}

int timMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  // posMax = i + 1;
  return max;
}

int timViTriMin(int a[], int n) {
  int min = timMin(a, n);
  int posMin;
  for (int i = 0; i < n; i++)
    if (a[i] == min) {
      posMin = i + 1;
      break;
    }
  return posMin;
}

int timViTriMax(int a[], int n) {
  int max = timMax(a, n);
  int posMax;
  for (int i = 0; i < n; i++)
    if (a[i] == max) {
      posMax = i + 1;
      break;
    }
  return posMax;
}

int main() {
  int a[100000], b[100000], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int min = timMin(a, n);
  int max = timMax(a, n);
  int posMin = timViTriMin(a, n);
  int posMax = timViTriMax(a, n);

  b[m++] = min;
  b[m++] = posMin;
  b[m++] = max;
  b[m++] = posMax;

  for (int i = 0; i < m; i++)
    cout << b[i] << " ";

  return 0;
}