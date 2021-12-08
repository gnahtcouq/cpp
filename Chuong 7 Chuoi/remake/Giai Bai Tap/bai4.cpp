/*
Bai 2
Viet ham nhan vao 1 chuoi va tra ve 1 chuoi tuong ung (giu nguyen chuoi dau vao):
+ Cac ky tu thanh ky tu thuong (giong strlwr)
+ Cac ky tu thanh ky tu hoa (giong strupr)
+ Cac ky tu dau tien moi tu thanh ky tu hoa
+ Chuan hoa chuoi (xoa khoang trang thua) */

#include <iostream>
#include <string>
using namespace std;

int STRLEN(char *s);
void STRCPY(char *s1, char *s2);
char* STRDUP(char *s);
char* STRLWR(char *s);
char* STRUPR(char *s);
void vietHoaKyTuDau(char *s);
void xoaMotKyTu(char *s, int vitrixoa);
void xoaKhoangTrangThua(char *s);
int demSoTu(char* s);

int main() {
  char s[30];
  STRCPY(s, "Thang Dep Trai");

  // 'a' -> 97
  // 'A' -> 65
  // Cach nhau 32
  cout << "\ns ban dau = " << s;

  char p[30];
  STRCPY(p, STRLWR(s));
  cout << "\nSTRLWR = " << p;

  STRCPY(p, STRUPR(s));
  cout << "\nSTRUPR = " << p;

  char s2[100];
  STRCPY(s2, "thang    dep  trai      hihi");
  vietHoaKyTuDau(s2);
  cout << "\nViet hoa ki tu dau: " << s2;


  char s3[100];
  STRCPY(s3, "quoc thang");
  cout << "\ns3 = " << s3;
  xoaMotKyTu(s3, 3);
  cout << "\ns3 sau khi xoa la: " << s3;

  char s4[100];
  STRCPY(s4, "thang    dep  trai      hihi   ");
  cout << "\ns4 = " << s4;
  xoaKhoangTrangThua(s4);
  cout << "\ns4 sau khi xoa khoang trang thua: " << s4;

  cout << "\nSo tu cua s4 = " << demSoTu(s4);

  system("pause");
  return 0;
}

int STRLEN(char *s) {
  int dem = 0;
  while (s[dem] != '\0') {
    dem++;
  }
  return dem;
}

char* STRDUP(char *s) {
  int length = STRLEN(s);
  char* p = new char[length + 1]; // cap phat bo nho tro p vua du chua length + 1
  STRCPY(p, s); // gan s sang p
  return p;
}

void STRCPY(char *s1, char *s2) {
  // gan tung ky tu tu s2 -> s1
  int length_s2 = STRLEN(s2);
  for (int i = 0; i < length_s2; i++) {
    s1[i] = s2[i];
  }
  s1[length_s2] = '\0'; // phai co ket thuc chuoi
}

// char* tra ve 1 mang ky tu, hay con goi la chuoi
char* STRLWR(char *s) {
  char* p = STRDUP(s);
  int length = STRLEN(p);

  for (int i = 0; i < length; i++) {
    if (p[i] >= 'A' && p[i] <= 'Z')
      p[i] += 32; // Doi sang thuong
  }
  return p;
}

char* STRUPR(char *s) {
  char* p = STRDUP(s);
  int length = STRLEN(p);

  for (int i = 0; i < length; i++) {
    if (p[i] >= 'a' && p[i] <= 'z')
      p[i] -= 32; // Doi sang hoa
  }
  return p;
}

void vietHoaKyTuDau(char *s) {
  int length = STRLEN(s);
  if (s[0] != ' ') {
    if (s[0] >= 'a' && s[0] <= 'z')
      s[0] -= 32;
  }
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ' ) {
      if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
        s[i + 1] -= 32;
    }
  }
}

void xoaMotKyTu(char *s, int vitrixoa) {
  int length = STRLEN(s);
  for (int i = vitrixoa + 1; i < length; i++) {
    s[i - 1] = s[i];
  }
  s[length - 1] = '\0';
}

void xoaKhoangTrangThua(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] == ' ') {
      xoaMotKyTu(s, i);
      i--;
      length--;
    }
  }
  if (s[0] == ' ') {
    xoaMotKyTu(s, 0);
    length--;
  }
  if (s[length - 1] == ' ') {
    xoaMotKyTu(s, length - 1);
    length--;
  }
}

int demSoTu(char* s) {
  int dem;
  if (s[0] == ' ')
    dem = 0;
  else
    dem = 1;
  int length = STRLEN(s);
  for (int i = 0; i < length - 1; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ')
      dem++;
  }
  return dem;
}