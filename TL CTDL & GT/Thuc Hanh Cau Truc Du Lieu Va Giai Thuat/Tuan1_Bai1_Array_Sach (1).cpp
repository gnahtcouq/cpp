#include<stdio.h>
#include<conio.h>
#include<time.h>
#define MAX 100
#include<stdlib.h>
#include<string.h>
typedef struct CUONSACH {
  int masach;
  char tensach[40];
  float gia;

}SACH;
void Nhap1Sach(SACH& x) {
  printf("\n Nhap ma sach: ");
  scanf("%d", &x.masach);

  printf("\nTen sach: ");
  fflush(stdin);
  gets(x.tensach);

  printf("Gia sach: ");
  scanf("%f", &x.gia);
}
void TieuDe() {
  printf("%8s| %-32s| %8s|\n", "MA SACH", "TEN SACH", "GIA");
}
void Xuat1Sach(SACH x) {
  printf("%8d|%-32s|%8.2f|\n", x.masach, x.tensach, x.gia);
}
void NhapSl(int& n) {
  do {
    printf("Nhap so luong sach (0 < N <= %d): ", MAX);
    scanf("%d", &n);
    if (n<1 || n>MAX)
      printf("Nhap sai\n");

  } while (n<1 || n>MAX);
}
void NhapMang(SACH a[], int n) {
  for (int i = 0;i < n;i++) {
    printf("Nhap sach thu %d:\n ", i + 1);
    Nhap1Sach(a[i]);
  }
}
void XuatMang(SACH a[], int n) {
  TieuDe();
  for (int i = 0;i < n;i++) {
    Xuat1Sach(a[i]);
  }
}
int main() {

  SACH a[MAX] = {
          {444,"Tinh yeu", 4.12},
          {111,"Quai thu", 2.25},
          {555,"Toan hoc", 4.65},

  };
  char b[MAX];
  int n = 10, kq;
  char X;
  char ph;
  NhapSl(n);
  NhapMang(a, n);
  XuatMang(a, n);
  return 0;
}
