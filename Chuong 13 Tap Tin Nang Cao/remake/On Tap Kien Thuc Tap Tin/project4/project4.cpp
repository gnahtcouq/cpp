/* Bài 4: Cấu trúc file INPUT.TXT như sau:
- Dòng đầu tiên chứa 1 số nguyên duy nhất là số lượng các số có trong chương trình.

- Dòng tiếp theo chứa lần lượt các số, mỗi số cách nhau bởi 1 khoảng trắng.

Yêu cầu:
Đọc dãy số nguyên trên vào chương trình, thực hiện sắp xếp tăng dần. Kết quả lưu vào file OUTPUT.TXT

vd:
INPUT.TXT
5
4 2 1 5 3

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
  fscanf(FileIn, "%d", &n); // Doc so luong phan tu va luu vao bien n

  // Cap phat bo nho cho con tro
  a = (int*)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    fscanf(FileIn, "%d", &a[i]);
  }
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