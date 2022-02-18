#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s;
  int t;
  cin >> t;

  while (t--) {
    int socandoi;
    cin >> socandoi;
    while (socandoi != 0) {
      int data = socandoi % 16;
      socandoi /= 16;
      s.push(data);
    }
    int x = s.top();
    s.pop();
    if (x < 10)
      cout << x << "\n";
    else if (x == 10)
      cout << "A\n";
    else if (x == 11)
      cout << "B\n";
    else if (x == 12)
      cout << "C\n";
    else if (x == 13)
      cout << "D\n";
    else if (x == 14)
      cout << "E\n";
    else if (x == 15)
      cout << "F\n";
  }

  return 0;
}