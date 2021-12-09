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

int STRCMP(char *s1, char *s2) {
  // s1 = "Quoc"
  // s2 = "Quoc Thang"
  int min = STRLEN(s1) < STRLEN(s2) ? STRLEN(s1) : STRLEN(s2);
  int i;
  for (i = 0; i < min; i++) {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  if (s1[i] == '\0') { // s1 la chuoi ngan
    if (s2[i] == '\0')
      return 0;
    else
      return -1;
  }
  if (s2[i] == '\0') {
    if (s1[i] == '\0')
      return 0;
    else
      return 1;
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

int STRICMP(char *s1, char *s2) {
  // Bien ca 2 thanh cung chu hoa hay cung chu thuong de cho dong bo
  STRLWR(s1);
  STRLWR(s2);
  return STRCMP(s1, s2);
}


int main() {
  char s1[] = "quoc thang";
  // char s2[] = "Quoc";
  // char s2[] = "Quoc Thang";
  char s2[] = "Quoc thang";


  int ketqua = STRICMP(s1, s2);
  cout << "\nketqua = " << ketqua;



  cout << endl;
  return 0;
}