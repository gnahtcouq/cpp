#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  set<string> a;
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    a.insert(s);
  }
  cout << a.size();

  return 0;
}