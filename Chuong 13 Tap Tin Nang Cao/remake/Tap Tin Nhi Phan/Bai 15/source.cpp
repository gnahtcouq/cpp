#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // De su dung ham exit(0);
#include <math.h>

// 1 2 1 -> nghiem kep
// 3 8 2 -> 2 nghiem phan biet


// Doc du lieu tu file vao chuong trinh
void nhapFile(FILE*& FileIn, int& a, int& b, int& c) {
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    printf("\nKhong tim thay tap tin");
    getch();
    exit(0); // Ket thuc toan bo chuong trinh
  }
  fscanf(FileIn, "%d%d%d", &a, &b, &c);
  fclose(FileIn);
}

// Xu ly va ghi ket qua ra file
void ghiFile(FILE*& FileOut, int a, int b, int c) {
  FileOut = fopen("OUTPUT.txt", "w");
  if (FileOut != NULL) {
    // Xu ly giai phuong trinh
    if (a == 0) { // bx + c = 0
      if (b == 0) {
        if (c == 0) {
          fprintf(FileOut, "Phuong trinh co vo so nghiem");
        }
        else {
          fprintf(FileOut, "Phuong trinh vo nghiem");
        }
      }
      else {
        float x = (float)-c / b;
        fprintf(FileOut, "Phuong trinh co 1 nghiem duy nhat x = %f", x);
      }
    }
    else {
      float denTa = b * b - 4 * a * c;
      if (denTa < 0) {
        fprintf(FileOut, "Phuong trinh vo nghiem");
      }
      else if (denTa == 0) {
        float x = (float)-b / (2 * a);
        fprintf(FileOut, "Phuong trinh co nghiem kep x1 = x2 = %f", x);
      }
      else { // denTa > 0
        float x1 = (-b + sqrt(denTa)) / (2 * a);
        float x2 = (-b - sqrt(denTa)) / (2 * a);
        fprintf(FileOut, "Phuong trinh co 2 nghiem phan biet:\nx1 = %f\nx2 = %f", x1, x2);
      }
    }
  }
  fclose(FileOut);
}

int main() {
  FILE* FileIn, * FileOut;
  int a, b, c;
  nhapFile(FileIn, a, b, c);
  ghiFile(FileOut, a, b, c);

  getch();
  return 0;
}