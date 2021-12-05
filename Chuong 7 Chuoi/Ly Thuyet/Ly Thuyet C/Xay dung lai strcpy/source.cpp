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

void STRCPY(char *s1, char *s2) {
  // gan tung ky tu tu s2 -> s1
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  if (length_s1 < length_s2)
    cout << "\nDo dai khong hop le. Khong nen gan qua, tranh bi loi";
  else {
    for (int i = 0; i < length_s2; i++) {
      s1[i] = s2[i];
    }
    s1[length_s2] = '\0'; // phai co ket thuc chuoi
  }
}

int main() {
  char s1[] = "Quoc Thang";
  char s2[100];

  STRCPY(s2, s1);
  cout << "\ns2 = " << s2;

  // strcpy(s1, s2); // gan s2 qua s1.
  // Luu y: s1 phai du de chua s2

  cout << endl;
  return 0;
}