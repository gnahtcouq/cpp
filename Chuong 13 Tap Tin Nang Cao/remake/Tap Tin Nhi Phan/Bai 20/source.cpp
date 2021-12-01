#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int demSoTu(FILE *&FileIn) {
  int dem = 0;
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    printf("\nKhong tim thay tap tin");
    getch();
    exit(0);
  }

  while (!feof(FileIn)) {
    char str[30];
    fscanf(FileIn, "%s", str);
    dem++;
    printf("\nTu thu %d la: %s",dem, str);
  }
  fclose(FileIn);
  return dem;
}

void ghiFile(FILE *&FileOut, int soLuong) {
  FileOut = fopen("OUTPUT.txt", "w");
  if (FileOut) {
    fprintf(FileOut, "So luong tu la: %d", soLuong);
  }
  fclose(FileOut);
}

int main() {
  FILE *FileIn, *FileOut;
  int soLuong = demSoTu(FileIn);
  ghiFile(FileOut, soLuong);

  getch();
  return 0;
}