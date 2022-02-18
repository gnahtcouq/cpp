#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  char a[100][100];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }

  int cr = 1, cd = 2;



  return 0;
}