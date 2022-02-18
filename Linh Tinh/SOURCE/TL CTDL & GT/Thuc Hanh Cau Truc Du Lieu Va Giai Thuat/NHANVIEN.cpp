#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
typedef struct NHANVIEN {
  int maso;
  char hoten[40];
  float luong;
}Nhanvien;
void NhapN(int& n) {
  do {
    printf("nhap so luong nhan vien 0<n<%d: ", MAX);
    scanf("%d", &n);
  } while (n <= 0 || n > MAX);
}
void Nhap1Nhanvien(Nhanvien& x) {
  printf("\n\tthong tin Nhan vien: \n");
  printf("\t\t>ma so: ");
  scanf("%u", &x.maso);
  fflush stdin;
  printf("\t\t>ho ten: ");
  gets(x.hoten);
  printf("\t\t>luong: ");
  float tam;
  scanf("%f", &tam);
  x.luong = tam;
}
void Xuat1Nhanvien(Nhanvien& x) {
  printf("\nMa so: %u", x.maso);
  printf("\nHo ten: %s", x.hoten);
  printf("\nLuong: %0.2f", x.luong);
}
void NhapDS(Nhanvien a[], int n) {
  for (int i = 0;i < n;i++) {
    printf("\nNhap nhan vien thu %d ", i + 1);
    Nhap1Nhanvien(a[i]);
  }
}
void XuatDS(Nhanvien a[], int n) {
  printf("**************************");
  printf("\nDANH MUC NHAN VIEN\n");
  for (int i = 0;i < n;i++) {
    printf("-----------------");
    printf("\n*Nhan vien thu %d ", i + 1);
    Xuat1Nhanvien(a[i]);
    printf("\n");
  }
}
int Timtuantu(Nhanvien a[], int n, int X) {
  int kq = -1;
  for (int i = 0;i < n;i++) {
    if (a[i].maso == X) {
      kq = i;
      break;
    }
  }
  return kq;
}
int main() {
  Nhanvien a[MAX], x;
  int n, X;
  NhapN(n);
  NhapDS(a, n);
  XuatDS(a, n);
  printf("=========================");
  printf("\nnhap ma nhan vien can tim: ");
  scanf("%d", &X);
  int vt = Timtuantu(a, n, X);
  Timtuantu(a, n, X);
  if (vt == -1) printf("\nKhong hop le");
  else {
    printf(" >tim thay nhan vien tai vi tri %d\n", vt + 1);
  }
  return 0;
}
