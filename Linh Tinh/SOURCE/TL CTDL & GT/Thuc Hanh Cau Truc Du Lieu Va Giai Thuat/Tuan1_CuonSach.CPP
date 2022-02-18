#include <stdio.h>
#include <conio.h>
#include <string.h>


#define MAX 100
//==========================================
typedef struct CuonSach {
  int masach;
  char tensach[40];
  float gia;
}SACH;
//==========================================
void NhapN(int& n) {
  do {
    printf("nhap so luong cuon sach (0<N<=%d): ", MAX);
    scanf("%d", &n);
    if (n<1 || n>MAX) printf("Nhap sai\n");
  } while (n<1 || n>MAX);
}
//==========================================
void Nhap1SACH(SACH& x) {
  printf("nhap ma cuon sach: ");
  scanf("%d", &x.masach);

  printf("nhap ten cuon sach: ");
  fflush(stdin); gets(x.tensach);

  printf("nhap gia cuon sach: ");
  scanf("%f", &x.gia);
}
//==========================================
void TieuDe() {
  printf("\n |===============|=======================================|===========|");
  printf("\n |%-15s|%-39s|%11s|", "MA SACH", "TEN CUON SACH", "GIA");
  printf("\n |===============|=======================================|===========|");
}
//==========================================   
void Xuat1SACH(SACH x) {
  printf("\n |%-15d|%-39s|%11.2f|", x.masach, x.tensach, x.gia);
}
//==========================================
void NhapMang(SACH a[], int n) {
  for (int i = 0;i < n;i++) {
    printf("nhap cuon sach thu %d:\n", i + 1);
    Nhap1SACH(a[i]);
  }
}
//==========================================
void XuatMang(SACH a[], int n) {
  TieuDe();
  for (int i = 0;i < n;i++) {
    Xuat1SACH(a[i]);
  }
  printf("\n |===============|=======================================|===========|");
}
//==========================================
int LinearSearch(SACH a[], int n, int key) {
  int i = 0;
  while (i < n && key != a[i].masach)
    i++;
  if (i < n) return i;
  return -1;
}
//===============================================
void Swap(SACH& x, SACH& y) {
  SACH temp = x;
  x = y;
  y = temp;
}
//===============================================
void SapXepTang_MaSACH(SACH a[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i].masach > a[j].masach)
        Swap(a[i], a[j]);
}
//===============================================
int BinarySearch(SACH a[], int n, int key) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid].masach == key)
      return mid;
    if (a[mid].masach < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}
//===============================================
void XuatMenu(int& chon) {
  printf("\n\n==============MENU===============");
  printf("\n1. LinearSearch theo MA cuon sach");
  printf("\n2. BinarySearch theo MA cuon sach");

  printf("\n0. Exit");
  printf("\n=================================");
  printf("\nBan chon chuc nang: "); scanf("%d", &chon);
}
//===============================================
void ArrayCopy(SACH a[], int n, SACH tam[]) {
  for (int i = 0; i < n; i++)
    tam[i] = a[i];
}
//===============================================
int main() {
  SACH a[MAX] = {
          {44444, "Go cua trai tim", 35.15},
          {66666, "Ai Cho toi tinh Yeu", 40.49},
          {11111, "Tinh Yeu Que Huong", 32.36},
          {99999, "Dat Nuoc va Con Nguoi", 65.40},
          {33333, "Mai Mai Ben Nhau", 32.15},
          {22222, "Tinh Nhat Phai", 38.28},
          {88888, "Anh O Dau Song, Em Cuoi Song", 92.41},
          {10001, "Lan va Diep", 73.65},
          {77777, "Hoa Trinh Nu", 12.42},
          {55555, "Khoa Hoc Ky Thuat", 81.75}
  };
  SACH tam[MAX];
  int n = 10, chon, kq;
  int X;
  //   	NhapN(n);
  //   	NhapMang(a,n);

  do {
    ArrayCopy(a, n, tam);
    printf("\n\n Nhung cuon sach ban dau:\n");
    XuatMang(tam, n);

    XuatMenu(chon);
    switch (chon) {
    case 1:
      printf("\nNhap MA cuon sach can tim: ");
      scanf("%d", &X);
      kq = LinearSearch(tam, n, X);
      if (kq == -1)
        printf("\nTim tuyen tinh khong co");
      else {
        printf("\n LinearSearch Tim thay: ");
        printf("\n |===============|=======================================|===========|");
        Xuat1SACH(tam[kq]);
        printf("\n |===============|=======================================|===========|");
      }
      break;

    case 2:
      SapXepTang_MaSACH(tam, n);
      printf("\nNhung cuon sach sau khi sap tang:\n");
      XuatMang(tam, n);

      printf("\nNhap MA cuon sach can tim: ");
      scanf("%d", &X);
      kq = BinarySearch(tam, n, X);
      if (kq == -1)
        printf("\nTim nhi phan khong co");
      else {
        printf("\n BinarySearch Tim thay: ");
        printf("\n |===============|=======================================|===========|");
        Xuat1SACH(tam[kq]);
        printf("\n |===============|=======================================|===========|");
      }
      break;

    default:
      chon = 0;
    }

  } while (chon != 0);

  //    printf("\n\n\n\n\n");
  return 0;
}
//==========================================

