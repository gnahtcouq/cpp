#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  // int a[100000], n;
  // cin >> n;
  // for (int i = 0; i < n; i++)
  //   cin >> a[i];

  // sort(a, a + n);

  // int dem = 0;
  // for (int i = 0; i < n; i++)
  //   for (int j = i + 1; j < n; j++)
  //     if (a[i] == a[j])
  //       dem++;

  // cout << n - (dem * 2);



  int* a = new int[1000000];
  int* b = new int[1000000];
  int n, dem = 0;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];

  for (int i = 1; i <= max; i++)
    b[i] = 0;

  for (int i = 0; i < n; i++)
    ++b[a[i]];

  for (int i = 0; i <= n; i++)
    if (b[a[i]] == 1)
      ++dem;


  delete[] a;
  delete[] b;

  cout << dem;

  return 0;
}