#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
typedef struct CuonSach {
  int masach;
  char tensach[40];
  float giasach;
}Sach;
void NhapN(int& n) {
  do {
    printf("nhap so luong sach 0<n<%d: ", MAX);
    scanf("%d", &n);
  } while (n <= 0 || n > MAX);
}
void Nhap1Sach(Sach& x) {
  printf("\n\tthong tin sach: \n");
  printf("\t\t>ma sach: ");
  scanf("%d", &x.masach);
  fflush stdin;
  printf("\t\t>ten sach: ");
  gets(x.tensach);
  printf("\t\t>gia sach: ");
  float tam;
  scanf("%f", &tam);
  x.giasach = tam;
}
void Xuat1Sach(Sach& x) {
  printf("\nMa sach: %d", x.masach);
  printf("\nTen sach: %s", x.tensach);
  printf("\nGia sach: %0.2f", x.giasach);
}
void NhapDS(Sach a[], int n) {
  for (int i = 0;i < n;i++) {
    printf("\nNhap cuon sach thu %d ", i + 1);
    Nhap1Sach(a[i]);
  }
}
void XuatDS(Sach a[], int n) {
  printf("**************************");
  printf("\nDANH MUC SACH\n");
  for (int i = 0;i < n;i++) {
    printf("-----------------");
    printf("\n*Cuon sach thu %d ", i + 1);
    Xuat1Sach(a[i]);
    printf("\n");
  }
}
int Timtuantu(Sach a[], int n, int X) {
  int kq = -1;
  for (int i = 0;i < n;i++) {
    if (a[i].masach == X) {
      kq = i;
      break;
    }
  }
  return kq;
}
int main() {
  Sach a[MAX], x;
  int n, X;
  NhapN(n);
  NhapDS(a, n);
  XuatDS(a, n);
  printf("=========================");
  printf("\nnhap ma cuon sach can tim: ");
  scanf("%d", &X);
  int vt = Timtuantu(a, n, X);
  Timtuantu(a, n, X);
  if (vt == -1) printf("\nma sach khong hop le");
  else {
    printf(" >tim thay sach tai vi tri %d\n", vt + 1);
  }
  return 0;
}
