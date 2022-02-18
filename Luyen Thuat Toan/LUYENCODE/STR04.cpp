#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  string s, n, nTemp;
  getline(cin, s);

  for (int i = 0; i < (int)s.length(); ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += 32; // chuyển tất cả kí tự về in thường
    if (s[i] >= '0' && s[i] <= '9')
      n += s[i];
    if (s[i] >= 'a' && s[i] <= 'z')
      n += s[i];
  }
  nTemp = n;
  // sắp xếp lại chuỗi n theo thứ tự tăng dần
  sort(n.begin(), n.end());

  // xóa các kí tự trùng
  for (int i = 0; i < n.length() - 1; ++i) {
    for (int j = i + 1; j < n.length(); ++j) {
      if (n[i] == n[j]) {
        n.erase(j, 1);
        j--;
      }
    }
  }

  // đếm số lần xuất hiện
  for (int i = 0; i < n.length(); ++i) {
    int count = 0;
    for (int j = 0; j < nTemp.length(); ++j)
      if (n[i] == nTemp[j])
        count++;
    cout << n[i] << " " << count << endl;
  }

  return 0;
}