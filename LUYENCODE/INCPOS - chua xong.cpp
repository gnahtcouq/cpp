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


  int l[100000], o = 0;
  for (int i = 0; i < q * 3; i++) {
    l[o++] = b[i];
    i += 2;
  }

  int r[100000], u = 0;
  for (int i = 1; i < q * 3; i++) {
    r[u++] = b[i];
    i += 2;
  }

  int x[100000], m = 0;
  for (int i = 2; i < q * 3; i++) {
    x[m++] = b[i];
    i += 2;
  }

  cout << "\n\nl = ";
  for (int i = 0; i < o; i++)
    cout << l[i] << " ";

  cout << "\nr = ";
  for (int i = 0; i < u; i++)
    cout << r[i] << " ";

  cout << "\nx = ";
  for (int i = 0; i < m; i++)
    cout << x[i] << " ";

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < o; j++) { // l
      for (int k = 0; k < u; k++) { // r
        for (int e = 0; e < m; e++) { // x
          if (i >= l[j] && i <= r[u])
            a[i] += x[e];
        }
      }
    }
    cout << a[i] << " ";
  }


  return 0;
}