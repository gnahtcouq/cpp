#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  string s = "1 + 2 * 3 - 4 / 5";
  vector<string> a;

  // cout << s.substr(0, 1); // lay 1 phan tu
  
  // Buoc 1
  char *p = strtok((char *)s.c_str(), " ");
  while (p != NULL) {
    a.push_back(p);
    p = strtok(NULL, " ");
  }
  
  for (int i = 1; i < a.size(); i += 2) {
    if (a[i] == "*" || a[i] == "/") {
      float x = stof(a[i - 1]);
      float y = stof(a[i + 1]);
      float ketqua;
      if (a[i] == "*")
        ketqua = x * y;
      else if (a[i] == "/")
        ketqua = x / y;
      a[i - 1] = to_string(ketqua);
      cout << a[i - 1] << endl;
      // xoa a[i] va a[i + 1] di

    }
  }

  // Tach chuoi neu dung substr ben C++
  /* int start = 0;
  int end;
  for (int i = start + 1; i < s.length(); ++i) {
    if (s[i] == ' ') {
      end = i;
      cout << s.substr(start, end - start) << endl;
      start = end + 1;
    }
  }
  cout << s.substr(start, s.length() - start) << endl; */

  system("pause");
  return 0;
}
// 1:10:05