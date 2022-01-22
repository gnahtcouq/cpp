#include <iostream>
using namespace std;

int main() {
  int a[100000], b[100000], n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < q * 3; i++)
    cin >> b[i];

  for (int i = 0; i < q * 3; i++)
    cout << b[i] << " ";

  int c[100000], m = 0;
  for (int i = 2; i < q * 3; i++) {
    c[m++] = b[i];
    i += 2;
  }

  cout << "\n\n";
  for (int i = 0; i < m; i++)
    cout << c[i] << " ";

  return 0;
}