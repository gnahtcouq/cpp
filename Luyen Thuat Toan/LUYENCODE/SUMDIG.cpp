#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  string s;
  cin >> t;
  cin.ignore();
  while (t--) {
    long long tong = 0;
    getline(cin, s);
    int length = s.length();
    for (int i = 0; i < length; i++)
      tong += (int)s[i] - 48;
    cout << tong << endl;
  }

  return 0;
}