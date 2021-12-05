/* 

Co 2 dang: doi thanh so nguyen & doi thanh so thuc

Doi thanh so nguyen
"123" ->123
ta thay 123 = 1*10^2 + 2*10^1 + 3*10^0
s[0] = '1' -> co ma ascii la 49
s[1] = '2' -> co ma ascii la 50
s[2] = '3' -> co ma ascii la 51

"12345" -> 12345
ta thay 12345 = 1*10^4 + 2*10^3 + 3*10^2 + 4*10^1 + 5*10^0

quy tac:
- Tu 1 ky tu so ma muon chuyen sang so tuong ung thi lay ky tu so do - 48
vd: '1' - 48 = 1

- Tu 1 so nguyen ma muon chuyen sang ky tu tuong ung thi lay so nguyen do +48
vd: 1 + 48 = '1'

*/

#include <iostream>
#include <math.h>
using namespace std;

int STRLEN(char *s) {
  int dem = 0;
  while (s[dem++] != '\0') {}
  return dem - 1;
}

int ATOI(char *s) {
  int length = STRLEN(s);

  int i = 0;
  int temp = length - 1;
  if (s[0] == '-') {
    i = 1;
    temp -= 1;
  }

  int number = 0;
  for (; i < length; i++) {
    number += (s[i] - 48) * pow(10.0, temp--);
  }
  if (s[0] == '-') {
    return -number;
  }
  return number;
}

double ATOF(char *s) {
  // "12.34" -> 12.34 ??
  // "-12.34" -> -12.34 ???

  /* Y tuong: Bo dau . di se thanh 1234
  -> dung lai ham o tren de bien doi thanh 1234
  nhan thay sau dau . co 2 chu so -> 1234/10^2 = 12.34 */

  char a[20];
  int length = STRLEN(s);
  int idx = 0;
  int k;
  for (int i = 0; i < length; i++) {
    if (s[i] != '.') {
      a[idx++] = s[i];
    }
    else {
      k = i; // luu vi tri cua dau .
    }
  }
  a[idx] = '\0';
  int soluong = length - 1 - k;
  return ATOI(a) / pow(10.0, soluong);
}

int main() {
  // char s[] = "1234";
  // int number = ATOI(s);
  // cout << "\nnumber = " << number;

  // char s2[] = "-1234";
  // int number2 = ATOI(s2);
  // cout << "\nnumber2 = " << number2;

  char s3[] = "12.34";
  double number3 = ATOF(s3);
  cout << "\nnumber3 = " << number3;

  cout << endl;
  return 0;
}