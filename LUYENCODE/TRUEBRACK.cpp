#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  string s;
  cin >> s;

  stack<char> st;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
      st.push(s[i]);
    else {
      if (st.empty()) {
        cout << "No";
        return 0;
      }
      char c = st.top();
      st.pop();
      if ((s[i] == ')' && c != '(') || (s[i] == '}' && c != '{') || (s[i] == ']' && c != '[')) {
        cout << "No";
        return 0;
      }
    }
  }
  if (!st.empty())
    cout << "No";
  else
    cout << "Yes";

  return 0;
}