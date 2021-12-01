#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void docFile(FILE*& FileIn, int*& a, int& n) {
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    printf("\nKhong tim thay tap tin");
    getch;
    exit(0);
  }
  fscanf(FileIn, "%d", &n);
  a = (int*)malloc(n * sizeof(int*));
  for(int i = 0; i < n; i++) {
    fscanf(FileIn, "%d", &a[i]);
  }
  fclose(FileIn);
}

void hoanVi(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void sapXep(int* a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        hoanVi(a[i], a[j]);
    }
  }
}

void ghiFile(FILE*& FileOut, int* a, int n) {
  FileOut = fopen("OUTPUT.txt", "w");
  for(int i = 0; i < n; i++) {
    fprintf(FileOut, "%d ", a[i]);
  }
  fclose(FileOut);
}

int main() {
  FILE *FileIn, *FileOut;
  int *a, n;
  docFile(FileIn, a, n);
  sapXep(a, n);
  ghiFile(FileOut, a, n);

  free(a);
  getch();
  return 0;
}