#include <iostream>
#include <string.h>
using namespace std;

void xoaMotKyTu(char* s, int vitrixoa) {
  int length = strlen(s);
  for (int i = vitrixoa + 1; i < length; i++) {
    s[i - 1] = s[i];
  }
  s[length - 1] = '\0';
}

void chuanHoaChuoi(char* s) {
  int length = strlen(s);
  // Chay tu dau den cuoi gap 2 khoang trang lien tiep thi xoa di 1
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] == ' ') {
      xoaMotKyTu(s, i);
      i--; // Xoa xong thi i-- xuong
      length--; // Phai giam length lai
    }
  }
  if (s[0] == ' ') {
    xoaMotKyTu(s, 0);
    length--;
  }
  if (s[length - 1] == ' ') {
    xoaMotKyTu(s, length - 1);
    length--;
  }
}

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    char str[1000];
    cin.getline(str, 1000);
    chuanHoaChuoi(str);
    cout << str << "\n";
  }

  return 0;
}