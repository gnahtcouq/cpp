#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int length = s.size();
  if (length == 2)
    cout << "0" << s[length - 2] << s[length - 1];
  else if (length == 1)
    cout << "0" << "0" << s[length - 1];
  if (length > 2)
    cout << s[length - 3] << s[length - 2] << s[length - 1];

  return 0;
}