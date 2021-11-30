/* Bài 3: Đọc 1 chuỗi chứa họ tên lưu trong file INPUT.TXT vào chương trình và ghi ra tập tin OUTPUT.TXT lời chào kèm theo tên đó.

vd:
INPUT.TXT
Son dep trai

OUTPUT.TXT
Chao Son dep trai */

#include <iostream>
#include <string>
using namespace std;

void docFile(FILE *&FileIn, char hoTen[30]) {
  FileIn = fopen("INPUT.txt", "r");
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0);
  }
  fgets(hoTen, 30, FileIn);
  // fscanf(FileIn, "%s", hoTen);
  fclose(FileIn);
}

void ghiFile(FILE *&FileOut, char hoTen[30]) {
  FileOut = fopen("OUTPUT.txt", "w");
  fprintf(FileOut, "Chao %s", hoTen);
  fclose(FileOut);
}

int main() {
  char hoTen[30];
  FILE *FileIn, *FileOut;
  docFile(FileIn, hoTen);
  ghiFile(FileOut, hoTen);
  
  cout << endl;
  system("pause");
  return 0;
}