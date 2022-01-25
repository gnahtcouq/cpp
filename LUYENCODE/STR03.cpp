#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);

  for (int i = 0; i < str.length(); i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 32;

  int t;
  cin >> t;

  char x;
  int count;

  while (t--) {
    cin >> x;
    if (x >= 'A' && x <= 'Z')
      x += 32;
    count = 0;
    for (int i = 0; i < str.length(); i++)
      if (x == str[i])
        count++;
    cout << count << "\n";
  }

  return 0;
}