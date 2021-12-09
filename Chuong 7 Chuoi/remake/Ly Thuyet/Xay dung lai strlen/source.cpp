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

int main() {
  char s[] = "Quoc Thang";
  int length = STRLEN(s);
  cout << "\nDo dai = " << length;

  cout << endl;
  return 0;
}