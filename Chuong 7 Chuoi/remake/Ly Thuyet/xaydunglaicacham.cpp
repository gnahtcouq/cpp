#include <iostream>
#include <string.h>
#include <math.h>
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
    hoanVi(s[i], s[length - i - 1]);
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

// strcat(s1, s2); // Noi s2 vao sau s1
void STRCAT(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  for (int i = 0; i < length_s2; i++) {
    s1[length_s1++] = s2[i];
  }
  s1[length_s1] = '\0';
}

// strstr(s1, s2); // Tim vi tri xuat hien dau tien cua chuoi s2 trong chuoi s1. Neu khong co thi tra ra -1
// vd:
// s1 = "Tran Van Quoc Thang"
// s2 = "Quoc Thang"
int STRSTR(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  int start;
  bool check;
  for (int i = 0; i < length_s1; i++) {
    if (s1[i] == s2[0]) {
      start = i;
      check = true; // Mac dinh
      int temp = start;
      for (int j = 1; j < length_s2; j++) {
        if (s1[++temp] != s2[j]) {
          check = false;
          break;
        }
      }
      if (check == true)
        return start;
    }
  }
  return -1;
}

// strdup(s); // Sao chep chuoi s bo qua vung nho moi co do lon vua du chua
// do lon sao chep = length + 1
char* STRDUP(char *s) {
  int length = STRLEN(s);
  char *p = (char *)new char[length + 1];
  for (int i = 0; i < length; i++) {
    p[i] = s[i];
  }
  p[length] = '\0';
  return p;
}

// atoi(s);
// th1: "1234" -> 1234
// th2: "12abc34" -> 12
// th3: "abc1234" -> 0

/*
"1234"
Lan luot lay tung ky tu ra roi doi sang so tuong ung
ta thay ket qua mong muon se la 1234
1234 =  1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
*/
int ATOI(char *s) {
  int tong = 0;
  int length = STRLEN(s);
  int temp = length;

  // Xac dinh temp de biet pham vi minh se duyet
  for (int i = 0; i < length; i++) {
    if (s[i] < '0' || s[i] > '9') {
      temp = i;
      break;
    }
  }
  // Tinh ra ket qua
  int temp1 = temp;
  for (int i = 0; i < temp; i++) {
    tong += (s[i] - 48) * pow(10.0, --temp1);
  }
  return tong;
}

double ATOF(char *s) {
  int length = STRLEN(s);
  char phannguyen[30];
  char phanle[30];
  int idx = 0;
  bool check = true; // luc nao cung la phan nguyen het

  // Do phan nguyen sang
  for (int i = 0; i < length; i++) {
    if (check == true)
      phannguyen[idx++] = s[i];
    else
      phanle[idx++] = s[i];
    if (s[i] == '.') {
      check = false;
      idx = 0; // reset lai
    }
  }
  return ATOI(phannguyen) + ATOI(phanle) / pow(10.0, idx);
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

// int doiSangHe10(char *chuoi, int cosobandau) {
// }


// substr(s, x, y); Cat chuoi con trong doan x, y cua chuoi s
// char* SUBSTR(char *s, int x, int y) {
//   char ketqua[100];
// 	int idx = 0;
// 	for(int i = x; i <= y; i++) {
// 		ketqua[idx++] = s[i];
// 	}
// 	ketqua[idx] = '\0';
// 	return ketqua;
// }

/*
Tim tu co chieu dai lon nhat, xuat ra tu do va do dai tuong ung cua no
Dinh nghia:
Tu la 1 hoac nhieu ky tu khac khoang trang
*/




int main() {
  // char s[] = "Quoc Thang";
  // // int length = STRLEN(s);
  // // cout << "\nlength = " << length;

  // char s1[30];
  // STRCPY(s1, (char *) "gnahtcouq quocthang");
  // cout << "\ns1 = " << s1;

  // STRLWR(s);
  // cout << "\nChu thuong: " << s;
  // STRUPR(s);
  // cout << "\nChu hoa: " << s;

  // char s2[] = "QuocThang";
  // STRREV(s2);
  // cout << "\ns2 = " << s2;

  // char s3[] = "abcd";
  // char s4[] = "abCD";
  // int ketqua = STRICMP(s3, s4);
  // cout << "\nketqua = " << ketqua;

  // char s5[6] = "abc";
  // char s6[7] = "defghi";
  // STRCAT(s5, s6);
  // cout << "\ns5 = " << s5;

  // char s7[] = "Tran Van Quoc Thang";
  // char s8[] = "Quoc Thang";
  // int vitri = STRSTR(s7, s8);
  // cout << "\nvitri = " << vitri;

  // char s9[] = "Thang Dep Trai";
  // char *p = STRDUP(s9);
  // cout << "\np = " << p;
  // delete p;

  // char s10[] = "abc01234";
  // int x = ATOI(s10);
  // cout << "\nx = " << x;

  // char s11[] = "1a6.96";
  // double y = ATOF(s11);
  // cout << "\ny = " << y;

  // int value = 250;
  // char result[100];
  // int coso = 2;
  // ITOA(value, result, coso);
  // cout << "\nketqua = " << result;

  // char s[] = "Tran Van Quoc Thang";
  // char sub[100];
  // STRCPY(sub, SUBSTR(s, 7, 10));
  // cout << "\nsub = " << sub;

  char s[] = "   Tran   Van  Quoc   Thang  hahahahahahihihii";
  int length = STRLEN(s);
  int start, end;
  int max = 1;
  int startMax, endMax;
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ') {
      start = i + 1;
      for (int j = start + 1; j <= length; j++) {
        if (s[j] == ' ' || s[j] == '\0') {
          end = j - 1;
          i = end;
          break;
        }
      }
      int dodai = end - start + 1;
      if (dodai > max) {
        max = dodai;
        startMax = start;
        endMax = end;
      }
    }
  }
  cout << "\nKet qua la: ";
  for (int i = startMax; i <= endMax; i++) {
    cout << s[i];
  }
	cout << "\nDo dai la: " << max;

  /*
  char s[] = "    Nguyen   Viet   Nam   Son hahahahihi";
  int length = strlen(s);
  int Start, End;
  int max = 1;
  int StartMax, EndMax;
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ') {
      Start = i + 1;
      for (int j = Start + 1; j <= length; j++) {
        if (s[j] == ' ' || s[j] == '\0') {
          End = j - 1;
          i = End;
          break;
        }
      }
      int dodai = End - Start + 1;
      if (dodai > max) {
        max = dodai;
        StartMax = Start;
        EndMax = End;
      }
    }
  }

  cout << "\nKet qua la: ";
  for (int i = StartMax; i <= EndMax; i++) {
    cout << s[i];
  }

	cout << "\nDo dai la: " << max;
  */

  cout << endl;
  system("pause");
  return 0;
}