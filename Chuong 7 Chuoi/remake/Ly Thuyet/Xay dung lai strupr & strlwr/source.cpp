#include <iostream>
using namespace std;

int STRLEN(char *s) {
  int dem = 0;
  // while (s[dem++] != '\0') {

  // }
  // return dem - 1;

  while (true) {
    if (s[dem] == '\0')
      return dem;
    dem++;
  }
}

void STRLWR(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += 32;
  }
}

void STRUPR(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 32;
  }
}

int main() {
  char s1[] = "Quoc Thang";

  // strlwr(s1) => s1 = "quoc thang";
  // strupr(s1) => s1 = "QUOC THANG";

  // nho nguyen tac
  // ky tu hoa sang thuong -> lay ky tu +32
  // ky tu thuong sang hoa -> lay ky tu -32

  STRLWR(s1);
  cout << "\ns1 = " << s1;

  STRUPR(s1);
  cout << "\ns1 = " << s1;

  cout << endl;
  return 0;
}