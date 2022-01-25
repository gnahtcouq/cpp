#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  while (cin >> str) {
    int length = str.length();
    if (str[0] == str[length - 1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}