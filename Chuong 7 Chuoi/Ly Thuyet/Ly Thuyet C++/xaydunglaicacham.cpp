#include <iostream>
using namespace std;

// strlen
int STRLEN(char *s) {
  int idx = 0;
  while (s[idx] != '\0') {
    idx++;
  }
  return idx;
}

// strcpy(s1, s2); // Gan s2 qua s1
void STRCPY(char *s1, char *s2) {
  int length = STRLEN(s2);
  for (int i = 0; i < length; i++) {
    s1[i] = s2[i];
  }
  s1[length] = '\0'; // Neu khong co ky tu ket thuc chuoi thi se xuat ra them ki tu la
}

// strlwr(s); // Bien chuoi s thanh chu thuong
// 'a' : 97
// 'A' : 65

void STRLWR(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += 32; // Bien thanh thuong
  }
}

// strupr(s); // Bien chuoi s thanh chua hoa
void STRUPR(char *s) {
  int length = STRLEN(s);
  for (int i = 0; i < length; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 32; // Bien thanh hoa
  }
}

// strrev(s); // Dao nguoc chuoi s
// vd: quocthang -> gnahtcouq
/*
-> length = 9
0 1 2 3 4 5 6 7 8
q u o c t h a n g
g n a h t c o u q

0 hoan vi 8
1 hoan vi 7
2 hoan vi 6
3 hoan vi 5
*/

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

/*
So sanh chuoi
Co 2 loai
strcmp: Co phan biet hoa thuong
stricmp: Khong phan biet hoa thuong
*/

int STRCMP(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  int min = length_s1 < length_s2 ? length_s1 : length_s2;
  for (int i = 0; i < min; i++) {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  if (length_s1 > length_s2)
    return 1;
  else if (length_s1 < length_s2)
    return -1;
  return 0;
}

int STRICMP(char *s1, char *s2) {
  // Cach lam 1: de nhat
  // Bien 2 chuoi cung thanh chu thuong
  // STRLWR(s1);
  // STRLWR(s2);
  // return STRCMP(s1, s2);

  // Cach lam 2: Ta xu ly o ngay buoc so sanh ky tu
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  int min = length_s1 < length_s2 ? length_s1 : length_s2;
  for (int i = 0; i < min; i++) {
    char temp1 = s1[i];
    char temp2 = s2[i];
    // quy het tat ca ve ky tu thuong
    if (temp1 >= 'A' && temp1 <= 'Z')
      temp1 += 32;
    if (temp2 >= 'A' && temp2 <= 'Z')
      temp2 += 32;
    if (temp1 < temp2)
      return -1;
    else if (temp1 > temp2)
      return 1;
  }
  if (length_s1 > length_s2)
    return 1;
  else if (length_s1 < length_s2)
    return -1;
  return 0;
}

int main() {
  char s[] = "Quoc Thang";
  // int length = STRLEN(s);
  // cout << "\nlength = " << length;

  char s1[30];
  STRCPY(s1, (char *) "gnahtcouq quocthang");
  cout << "\ns1 = " << s1;

  STRLWR(s);
  cout << "\nChu thuong: " << s;
  STRUPR(s);
  cout << "\nChu hoa: " << s;

  char s2[] = "QuocThang";
  STRREV(s2);
  cout << "\ns2 = " << s2;

  char s3[] = "abcd";
  char s4[] = "abCD";
  int ketqua = STRICMP(s3, s4);
  cout << "\nketqua = " << ketqua;

  cout << endl;
  system("pause");
  return 0;
}