#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const string& a, const string& b) {
  return b + a < a + b;
}

int main() {
  int n;
  cin >> n;
  string a[100000];
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  // for (int i = 0; i < n; ++i)
  //   for (int j = i + 1; j < n; ++j)
  //     if (a[j] + a[i] > a[i] + a[j])
  //       swap(a[i], a[j]);

  sort(a, a + n, cmp);

  for (int i = 0; i < n; ++i)
    cout << a[i];

  return 0;
}