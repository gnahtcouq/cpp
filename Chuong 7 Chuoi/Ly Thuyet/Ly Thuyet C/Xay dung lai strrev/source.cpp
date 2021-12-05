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

void hoanVi(char &x, char &y) {
  char temp = x;
  x = y;
  y = temp;
}

void STRREV(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length / 2; i++) {
    swap(s[i], s[length - 1 - i]);
  }
}


int main() {
  char s1[] = "Quoc Thang";

  // strrev(s1);
  // => s1 = "gnahT couQ"

  STRREV(s1);
  cout << "\ns1 = " << s1;

  cout << endl;
  return 0;
}