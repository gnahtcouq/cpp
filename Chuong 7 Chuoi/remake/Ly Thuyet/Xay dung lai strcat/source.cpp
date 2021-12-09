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

// Noi s2 vao dang sau s1
void STRCAT(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  for (int i = 0; i < length_s2; i++) {
    s1[length_s1++] = s2[i];
  }
  s1[length_s1] = '\0';
}

int main() {

  // char s1[] = "Quoc Thang";
  // char s2[] = " dep trai";
  // strcat(s1, s2);
  // => s1 = "Quoc Thang dep trai"

  char s1[100] = "Quoc Thang";
  char s2[] = " dep trai";
  STRCAT(s1, s2);
  cout << "\ns1 = " << s1;

  cout << endl;
  return 0;
}