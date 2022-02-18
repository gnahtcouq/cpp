#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;

    for (int i = 0; i < str.length(); i++)
      if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] -= 32;
        break;
      }

    for (int i = 0; i < str.length(); i++)
      if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
        str[i + 1] -= 32;

    cout << str << "\n";
  }

  return 0;
}