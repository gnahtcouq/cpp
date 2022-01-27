#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  string str = "";
  long long sum = 0;
  for (int i = 0; i <= (int)s.length(); ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      str.push_back(s[i]);
    else {
      if (str != "") {
        sum += stoll(str);
        str = "";
      }
    }
  }
  cout << sum;

  return 0;
}