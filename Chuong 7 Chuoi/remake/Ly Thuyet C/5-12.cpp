#include <iostream>
#include <string.h>
using namespace std;

char* bienKyTuDauThanhHoa(char* s) {
  char* p = strdup(s);
  int length = strlen(p);
  if (p[0] != ' ')
    if (p[0] >= 'a' && p[0] <= 'z')
      p[0] -= 32;
  for (int i = 0; i < length; i++) {
    if (p[i] == ' ' && p[i + 1] != ' ')
      if (p[i + 1] >= 'a' && p[i + 1] <= 'z')
        p[i + 1] -= 32;
  }
  return p;
}

void xoaKyTu(char* s, int vitrixoa) {
  int length = strlen(s);
  for (int i = vitrixoa + 1; i < length; i++) {
    s[i - 1] = s[i];
  }
  s[length - 1] = '\0';
}

char* xoaHetKhoangTrangThua(char* s) {
  char* p = strdup(s);
  int length = strlen(p);
  for (int i = 0; i < length; i++) {
    if (p[i] == ' ' && p[i + 1] == ' ') {
      xoaKyTu(p, i);
      i--;
      length--;
    }
  }
  if (p[0] == ' ') {
    xoaKyTu(p, 0);
    length--;
  }
  if (p[length - 1] == ' ') {
    xoaKyTu(p, length - 1);
    length--;
  }
  return p;
}

int demSoTu(char* s) {
  int dem;
  if (s[0] == ' ')
    dem = 0;
  else
    dem = 1;
  int length = strlen(s);
  for (int i = 0; i < length - 1; i++) {
    if (s[i] == ' ' && s[i + 1] != ' ')
      dem++;
  }
  return dem;
}

void xuatTuTrenCacDongLienTiep(char* s) {
  int start = -1, end;
  int length = strlen(s);
  if (s[0] != ' ')
    start = 0;
  for (int i = 0; i <= length - 1; i++) {
    // tim bat dau
    if ((s[i] == ' ' && s[i + 1] != ' ') || start == 0) {
      start = i + 1;
      if (start == 1)
        start = 0;
      for (int j = start + 1; j < length - 1; j++) {
        if (s[j] != ' ' && s[j + 1] == ' ') {
          end = j;
          i = j; // cap nhat lai vi tri duyet
          break;
        }
      }
      // in ra cac ky tu trong doan start -> end
      for (int k = start; k <= end; k++) {
        cout << s[k];
      }
      start = -1;
      cout << "\n";
    }
  }
}

void timDoDaiTuLonNhatVaXuat(char* s) {
  int start = -1, end;
  int length = strlen(s);
  if (s[0] != ' ') {
    start = 0;
  }
  int doDaiMax = 0;
  int startMax, endMax;
  for (int i = 0; i < length - 1; i++) {
    // tim bat dau
    if ((s[i] == ' ' && s[i + 1] != ' ') || start == 0) {
      start = i + 1;
      if (start == 1) {
        start = 0;
      }
      for (int j = start + 1; j < length - 1; j++) {
        if (s[j] != ' ' && s[j + 1] == ' ') {
          end = j;
          i = j; // cap nhat lai vi tri duyet
          break;
        }
      }
      if (end - start + 1 > doDaiMax) {
        doDaiMax = end - start + 1;
        startMax = start;
        endMax = end;
      }
      start = -1;
      cout << "\n";
    }
  }
  cout << "\nDo dai lon nhat la: " << doDaiMax;
  cout << "\nChuoi tim duoc la: ";
  for (int k = startMax; k <= endMax; k++) {
    cout << s[k];
  }
}

// char* subString(char *s, int start, int count) {
//   char p[30];
//   int k = 0;
//   for (int i = start; i < start + count; i++) {
//     p[k++] = s[i];
//   }
//   p[k] = '\0'; // ket thuc chuoi
//   return p;
// }

int main() {
  char s[] = "Quoc Thang dep trai";
  char p[30];

  // strcpy(p, bienKyTuDauThanhHoa(s));
  // cout << "\ns = " << s;
  // cout << "\np = " << p;

  // int length = strlen(s);
  // xoaKyTu(s, length - 1);
  // cout << "\ns = " << s;

  // strcpy(p, xoaHetKhoangTrangThua(s));
  // cout << "\ns = " << s;
  // cout << "\np = " << p;

  // int sotu = demSoTu(s);
  // cout << "\nSo tu = " << sotu;

  // timDoDaiTuLonNhatVaXuat(s);

  // char *p;
  // p = strdup(subString(s, 5, 5));

  // char p[30];
  // strcpy(p, subString(s, 5, 10));

  cout << p;

  return 0;
}