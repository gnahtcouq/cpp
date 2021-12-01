#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void xuatMang(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%4d", a[i]);
  }
}

void docFile(FILE *&FileIn, int *&a, int &n) {
  FileIn = fopen("taptin.dat", "rb");
  if(!FileIn) {
    printf("\nKhong tim thay tap tin");
    getch();
    exit(0);
  }
  fseek(FileIn, 0, SEEK_END); // Cho con tro nhay den cuoi tap tin
  n = (ftell(FileIn) + 1) / sizeof(int); // Ham ftell(); Tra ve con tro dang o vi tri nao
  rewind(FileIn); // Cho con tro nhay ve dau file lai
  // Vi luc dau cho con tro nhay den cuoi, neu doc tiep se khong con gi de doc het Hoac dung // fseek(FileIn, 0, SEEK_SET);

  // n = 2;
  a = (int *)malloc(n * sizeof(int));
  fread(a, sizeof(int), n, FileIn);

  fclose(FileIn);
}

int main() {
  FILE *FileIn;
  int *a, n;

  docFile(FileIn, a, n);
  xuatMang(a, n);

  free(a);

  getch();
  return 0;
}