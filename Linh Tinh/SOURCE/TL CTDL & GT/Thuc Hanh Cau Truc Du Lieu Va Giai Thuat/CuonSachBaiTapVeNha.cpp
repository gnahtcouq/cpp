#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//Quach Quang Minh
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
void bubblesort_tang(SACH a[], int n) {
  int i, j;
  for (i = 0;i < n - 1;i++)
    for (j = n - 1;j > i;j--)
      if (a[j - 1].masach > a[j].masach)
        Swap(a[j], a[j - 1]);
}
void selectionsort_tang(SACH a[], int n) {
  int i;
  int min;
  for (i = 0;i < n - 1;i++) {
    min = i;
    for (int j = i + 1;j < n;j++) {
      if (strcmp(a[j].tensach, a[min].tensach) < 0) {
        min = j;
      }
    }
    Swap(a[min], a[i]);
  }
}
//===============================================
void XuatMenu(int& chon) {
  printf("\n\n==============MENU===============");
  printf("\n1. LinearSearch theo ma cuon sach");
  printf("\n2. BinarySearch theo ma cuon sach");
  printf("\n3. BubblesortTang theo ma sach");
  printf("\n4: SelectionsortTang theo ten sach");
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
          {108, "Toan 12", 12.15},
          {200, "Tieng anh 12", 11.49},
          {96, "Hoa hoc 12", 13.36},
          {470, "Sinh hoc 12", 10.40},
          {12, "Giao duc cong dan 12", 15.15},
          {66, "Ngu van 12", 12.28},
          {88, "Cong nghe 12", 11.41},
          {75, "Dia li 12", 13.65},
          {7, "Lich su 12", 10.42},
          {9, "Quoc phong 12", 14.75}
  };
  SACH tam[MAX];
  int n = 10, chon, kq;
  int X;
  //   NhapN(n);
  //   NhapMang(a,n);

  do {
    ArrayCopy(a, n, tam);
    printf("\n\n Nhung cuon sach ban dau:\n");
    XuatMang(tam, n);
    XuatMenu(chon);
    switch (chon) {
    case 1:
      printf("\nNhap ma cuon sach can tim: ");
      scanf("%d", &X);
      kq = LinearSearch(tam, n, X);
      if (kq == -1)
        printf("\nKhong co sach");
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

      printf("\nNhap ma cuon sach can tim: ");
      scanf("%d", &X);
      kq = BinarySearch(tam, n, X);
      if (kq == -1)
        printf("\nKhong co sach");
      else {
        printf("\n BinarySearch Tim thay: ");
        printf("\n |===============|=======================================|===========|");
        Xuat1SACH(tam[kq]);
        printf("\n |===============|=======================================|===========|");
      }
      break;
    case 3:
      bubblesort_tang(tam, n);
      printf("\n=====================Ma sach tang====================\n");
      XuatMang(tam, n);
      break;
    case 4:
      selectionsort_tang(tam, n);
      printf("\n =============================Ten sach tang===========================\n ");
      XuatMang(tam, n);
      break;
    default:
      chon = 0;
    }

  } while (chon != 0);
  //    printf("\n\n\n\n\n");
  return 0;
}
//==========================================

