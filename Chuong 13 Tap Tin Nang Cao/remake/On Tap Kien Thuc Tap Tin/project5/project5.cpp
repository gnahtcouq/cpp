/* Bài 5: Cấu trúc file INPUT.TXT như sau:
- Một dòng duy nhất chứa các số, mỗi số cách nhau bởi 1 khoảng trắng.

Yêu cầu:
Đọc dữ liệu từ file và lưu vào mảng, sau đó sắp xếp mảng tăng dần. Kết quả ghi vào file OUTPUT.TXT

vd:
INPUT.TXT
5 2 3 4 1

OUTPUT.TXT
1 2 3 4 5 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void docFile(FILE*& FileIn, int*& a, int &n) {
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0);
  }

  n = 100;
  a = (int *)malloc(n * sizeof(int *));

  int dem = 0;
  // Neu chua di den cuoi file thi tra ve 0, neu da den cuoi thi tra ve != 0
  while (feof(FileIn) == 0) { // Cach 2: while (!feof(FileIn))
    fscanf(FileIn, "%d", &a[dem++]);
  }
  n = dem; // Cap nhat lai n
  realloc(a, n * sizeof(int *)); // Cap nhat lai bo nho
  fclose(FileIn);
}

void hoanVi(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void sapXep(int* a, int n, char phanloai) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (phanloai == 't')
        if (a[i] > a[j])
          hoanVi(a[i], a[j]);
      if (phanloai == 'g')
        if (a[i] < a[j])
          hoanVi(a[i], a[j]);
    }
  }
}

void ghiFile(FILE*& FileOut, int* a, int n) {
  FileOut = fopen("OUTPUT.txt", "w");
  for (int i = 0; i < n; i++) {
    fprintf(FileOut, "%d ", a[i]);
  }
  fclose(FileOut);
}

int main() {
  FILE* FileIn, * FileOut;

  int* a, n;

  docFile(FileIn, a, n);
  sapXep(a, n, 't');
  // sapXep(a, n, 'g');
  ghiFile(FileOut, a, n);


  free(a);
  cout << endl;
  system("pause");
  return 0;
}