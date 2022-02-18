#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;

  k %= 25;
  for (int i = 0; i < (int)s.length(); ++i) {
    s[i] -= k;
    if (s[i] < 97)
      s[i] += 26;
    cout << s[i];
  }

  return 0;
}