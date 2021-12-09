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
  int length_s2 = STRLEN(s2);
  for (int i = 0; i < length_s2; i++) {
    s1[i] = s2[i];
  }
  s1[length_s2] = '\0'; // phai co ket thuc chuoi
}

char *STRDUP(char *s) {
  int length = STRLEN(s);
  char *p = new char[length + 1]; // cap phat bo nho tro p vua du chua length + 1
  STRCPY(p, s); // gan s sang p
  return p;
}

int main() {
  char s1[] = "Quoc Thang";
  
  
  // char *s2 = strdup(s1);
  // s2 = "Quoc Thang" 
  char *s2 = STRDUP(s1);
  cout << "\ns2 = " << s2;

  delete(s2); // giai phong

  cout << endl;
  return 0;
}