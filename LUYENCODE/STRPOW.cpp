#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s, str, temp;
  cin >> s >> str >> n;

  temp = s;
  n -= 1;

  while (n--)
    temp += s;

  if (str == temp)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}