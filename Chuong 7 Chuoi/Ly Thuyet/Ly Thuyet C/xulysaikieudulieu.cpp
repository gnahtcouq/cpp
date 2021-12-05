#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// Neu la so thi tra ve 1, nguoc lai tra ve 0
int kiemTraLaSoNguyen(char *s) {
  int length = strlen(s);
  for (int i = 0; i < length; i++) {
    if (s[i] < '0' || s[i] > '9')
      return 0; // sai
  }
  return 1; // dung
}

int main() {
  int soLuong;
  quaylai:
  char chuoi[30];
  fflush(stdin);
  printf("\nNhap vao so luong: ");
  // scanf("%d", &soLuong);
  gets(chuoi);

  int kiemtra = kiemTraLaSoNguyen(chuoi);
  if (kiemtra == 0) {
    printf("\nLoi kieu du lieu");
    goto quaylai;
  }
  else {
    soLuong = atoi(chuoi);
    printf("\nSo luong = %d", soLuong);
  }

  getch();
  return 0;
}