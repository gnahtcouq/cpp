#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhapMang(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("\nNhap vao a[%d] = ", i);
    scanf("%d", &a[i]);
  }
}

void ghiFile(FILE *&FileOut, int *a, int n) {
  FileOut = fopen("taptin.dat", "wb");
  if(FileOut != NULL) {
    fwrite(a, sizeof(int), n, FileOut);
  }
  fclose(FileOut);
}

int main() {
  FILE *FileOut;
  int n = 5;
  int *a = (int *)malloc(n * sizeof(int));

  nhapMang(a, n);
  ghiFile(FileOut, a, n);

  free(a);

  getch();
  return 0;
}