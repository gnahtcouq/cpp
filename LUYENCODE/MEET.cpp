#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  char x;
  cin >> n >> x;

  while (n--) {
    string s;
    cin >> s;
    bool check = true;
    for (int i = 0; i < s.length(); ++i)
      if (s[i] == x)
        check = false;
    if (check)
      cout << s << "\n";
  }

  return 0;
}