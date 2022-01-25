#include <iostream>
#include <string>
using namespace std;


int main() {
  string s1, s2;
  cin >> s1 >> s2;

  while (s1.size() < s2.size())
    s1 = '0' + s1;
  while (s2.size() < s1.size())
    s2 = '0' + s2;

  string ketqua;
  int idx = 0, nho = 0;
  for (int i = s1.size() - 1; i >= 0; i--) {
    int so = (s1[i] - 48) + (s2[i] - 48) + nho;
    nho = so / 10;
    so %= 10;
    ketqua += so + 48;
  }
  if (nho != 0)
    ketqua += nho + 48;

  for (int i = ketqua.size() - 1; i >= 0; i--)
    cout << ketqua[i];

  return 0;
}