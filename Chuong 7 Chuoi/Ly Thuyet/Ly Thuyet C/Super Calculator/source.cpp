/*
B1: Những số mà độ dài không bằng nhau 
=> Thêm số 0 vào đầu cho cân bằng

B2: Duyệt từ cuối về đầu của 2 chuỗi số tương ứng
, lấy từng ký tự ở từng vị trí tương ứng 
chuyển nó sang số tương ứng rồi cộng lại với nhau
, nếu kết quả > 10 => lấy phần dư và nhớ 1 để c
ộng thêm vào cho lần sau

B3: Cứ thế lặp lại B2 cho đến khi đi hết chuỗi
*/

#include <iostream>
using namespace std;

//    123456 & 89
// -> 123456 & 000089

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

void themKyTuVaoChuoi(char *s, char kytuthem, int vitrithem) {
  int length = STRLEN(s);
  for (int i = length - 1; i >= vitrithem; i--) {
    s[i + 1] = s[i];
  }
  s[vitrithem] = kytuthem;
  s[length + 1] = '\0';
}

void chuanHoaCungDoDai(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  
  int min, max;
  if (length_s1 < length_s2)
    min = length_s1;
  else
    min = length_s2;
  if (length_s1 > length_s2)
    max = length_s1;
  else
    max = length_s2;

  if (min == length_s1) {
    for (int i = 1; i <= max - min; i++) {
      themKyTuVaoChuoi(s1, '0', 0);
    }
  }
  else if (min == length_s2) {
    for (int i = 1; i <= max - min; i++) {
      themKyTuVaoChuoi(s2, '0', 0);
    }
  }
}

// char* tinhTong(char *s1, char *s2) {
//   char ketqua[200];
//   int idx = 0; // idx cua ket qua
//   int nho = 0; // Mac dinh nho = 0
//   for (int i = max - 1; i >= 0; i--) {
//     int so = (s1[i] - 48) + (s2[i] - 48) + nho;
//     nho = so / 10; // 16 thi nho 1
//     so %= 10; // 16 thi lay 6

//     ketqua[idx++] = so + 48; // Doi so sang ky tu roi luu vao chuoi ket qua
//   }
//   if (nho != 0) {
//     ketqua[idx++] = nho + 48; 
//   }
//   ketqua[idx] = '\0'; // phai co ket thuc chuoi

//   // dao lai boi vi nay gio minh lam tu trai sang phai chu khong phai tu phai sang trai
//   STRREV(ketqua);

//   return ketqua;
// }

int main() {
  // char s[30] = "12";
  // themKyTuVaoChuoi(s, '0', 0);
  // cout << "\ns = " << s;

  char s1[100] = "95";
  char s2[100] = "98";

  /* ------------------ BUOC 1 ------------------ */
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  
  int min, max;
  if (length_s1 < length_s2)
    min = length_s1;
  else
    min = length_s2;
  if (length_s1 > length_s2)
    max = length_s1;
  else
    max = length_s2;

  // if (min == length_s1) {
  //   for (int i = 1; i <= max - min; i++) {
  //     themKyTuVaoChuoi(s1, '0', 0);
  //   }
  // }
  // else if (min == length_s2) {
  //   for (int i = 1; i <= max - min; i++) {
  //     themKyTuVaoChuoi(s2, '0', 0);
  //   }
  // }
  /* -------------------------------------------- */

  // cout << "\ns1 = " << s1;
  // cout << "\ns2 = " << s2;

  chuanHoaCungDoDai(s1, s2);
  // cout << "\ns1 = " << s1;
  // cout << "\ns2 = " << s2;



  /* ------------------ BUOC 2 ------------------ */
  char ketqua[100];
  int idx = 0; // idx cua ket qua
  int nho = 0;
  for (int i = max - 1; i >= 0; i--) {
    int so = (s1[i] - 48) + (s2[i] - 48) + nho;
    nho = so / 10; // 16 thi nho 1
    so %= 10; // 16 thi lay 6

    ketqua[idx++] = so + 48;
  }
  if (nho != 0) {
    ketqua[idx++] = nho + 48; 
  }
  ketqua[idx] = '\0'; // phai co ket thuc chuoi

  // dao lai boi vi nay gio minh lam tu trai sang phai chu khong phai tu phai sang trai
  STRREV(ketqua);


  // cout << "\ns1 = " << s1;
  // cout << "\ns2 = " << s2;
  cout << "\nketqua = " << ketqua; 


  

  // system("pause");
  return 0;
}