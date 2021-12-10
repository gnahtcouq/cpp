#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void xoa(char *s, int vitrixoa) {
  int n = strlen(s);
  for (int i = vitrixoa + 1; i < n; i++) {
    s[i - 1] = s[i];
  }
  s[n - 1] = '\0';
}
void them(char *s, int vitrithem, char phantuthem) {
  int n = strlen(s);
  for (int i = n - 1; i >= vitrithem; i--) {
    s[i + 1] = s[i];
  }
  s[vitrithem] = phantuthem;
  s[n + 1] = '\0';
}

int main() {
  // char s[] = "abcdef";
  // xoa(s, 3);
  // cout << "\ns = " << s;

  // them(s, 3, 'g');
  // cout << "\ns = " << s;

  // string s = "Quoc Thang";
  // cout << s;

  string s;
  cout << "\nNhap chuoi: ";
  getline(cin, s);
  cout << "\nChuoi vua nhap la: " << s;

  int dodai = s.length();

  system("pause");
  return 0;
}
