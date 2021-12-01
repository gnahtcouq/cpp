#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int demSoKyTuChuCai(FILE *&FileIn) {
  int dem = 0;
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    printf("\nKhong tim thay tap tin");
    getch();
    exit(0);
  }
  char c;
  while ((c = fgetc(FileIn)) != EOF) {
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
      dem++;
  }
  fclose(FileIn);
  return dem;
}

void ghiFile(FILE *&FileOut, int soLuong) {
  FileOut = fopen("OUTPUT.txt", "w");
  if (FileOut) {
    fprintf(FileOut, "So luong ky tu la chu cai la: %d", soLuong);
  }
  fclose(FileOut);
}

int main() {
  FILE *FileIn, *FileOut;
  int soLuong = demSoKyTuChuCai(FileIn);
  ghiFile(FileOut, soLuong);

  getch();
  return 0;
}