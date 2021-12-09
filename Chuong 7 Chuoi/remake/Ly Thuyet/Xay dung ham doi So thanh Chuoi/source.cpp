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

/* 

itoa, ltoa, ultoa
itoa(value, buffer, 2|8|10|16)

250 đổi sang các hệ

* hệ 2 *
250 : 2 = 125 dư 0
125 : 2 = 62 dư 1
62 : 2 = 31 dư 0
31 : 2 = 15 dư 1
15 : 2 = 7 dư 1
7 : 2 = 3 dư 1
3 : 2 = 1 dư 1
1 : 2 = 0 dư 1
phần nguyên còn 0 => dừng lại
=> đọc ngược lên các giá trị dư sẽ là: 11111010

* hệ 8 *
250 : 8 = 31 dư 2
31 : 8 = 3 dư 7
3 : 8 = 0 dư 3
=> 0 thì dừng lại
=> đọc ngược lại là 372

* hệ 16 *
250 : 16 = 15 dư 10
15 : 16 = 0 dư 15
=> 0 thì dừng lại
-> đọc ngược lên nhưng theo quy tắc sau
nếu là 10 => A, 11 => B, 12 => C, 13 => D, 14 => E, 15 => F
=> FA
*/

// "1234" => "4321"
void hoanVi(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void STRREV(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length / 2; i++) {
    hoanVi(s[i], s[length - 1 - i]);
  }
}

void ITOA(int number, char *vungnho, int coso) {
  int idx = 0;
  while (number != 0) {
    int ketqua = number % coso;
    number /= coso; // cap nhat lai number

    if (ketqua < 10)
      vungnho[idx++] = ketqua + 48; // Doi so nguyen sang ky tu tuong ung
    else if (ketqua == 10)
      vungnho[idx++] = 'A';
    else if (ketqua == 11)
      vungnho[idx++] = 'B';
    else if (ketqua == 12)
      vungnho[idx++] = 'C';
    else if (ketqua == 13)
      vungnho[idx++] = 'D';
    else if (ketqua == 14)
      vungnho[idx++] = 'E';
    else if (ketqua == 15)
      vungnho[idx++] = 'F';
  }
  vungnho[idx] = '\0'; // Phai nho ket thuc chuoi
  STRREV(vungnho); // Dao nguoc chuoi lai
}




int main() {
  int number = 250;
  char vungnho[30];

  ITOA(number, vungnho, 2);
  cout << "\nKet qua = " << vungnho;

  cout << endl;
  return 0;
}