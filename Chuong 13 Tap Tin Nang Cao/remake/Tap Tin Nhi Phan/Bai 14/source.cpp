#include <stdio.h>
#include <conio.h>

void nhapFile(int& a, int& b, int& c) {
  printf("\nNhap a = ");
  scanf("%d", &a);
  printf("\nNhap b = ");
  scanf("%d", &b);
  printf("\nNhap c = ");
  scanf("%d", &c);
}
void ghiFile(FILE*& FileOut, int a, int b, int c) {
  FileOut = fopen("OUTPUT.txt", "w");
  if (FileOut != NULL) {
    fprintf(FileOut, "a = %d\nb = %d\nc = %d\n", a, b, c);
  }
  fclose(FileOut);
}

int main() {
  FILE* FileOut;
  int a, b, c;
  nhapFile(a, b, c);
  ghiFile(FileOut, a, b, c);

  getch();
  return 0;
}