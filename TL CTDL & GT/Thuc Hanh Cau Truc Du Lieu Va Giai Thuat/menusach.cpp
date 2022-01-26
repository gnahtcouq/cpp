//Pham Tran Vinh Tuong
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
//=========================================================================
typedef struct Sach {
  int ma;
  char ten[70];
}S;
//=========================================================================
void NhapSach(S& x) {
  printf("\nNhap ma sach: ");	scanf("%d", &x.ma);
  printf("Nhap ten sach: ");
  fflush(stdin);
}
//=========================================================================
void XuatSach(S x) {
  printf("|%d      | %-33s  |", x.ma, x.ten);
}
//=========================================================================
void XuatMangCuonSach(S a[], int n) {
  printf("\n|============|====================================|");
  printf("\n|Ma sach     |\t      Ten sach                    |");
  printf("\n|============|====================================|\n");
  for (int i = 0;i < n;i++) {
    XuatSach(a[i]);
    printf("\n|============|====================================|");
    printf("\n");
  }
}
//=========================================================================
void swap(S& x, S& y) {
  S temp = x;
  x = y;
  y = temp;
}
//=========================================================================
int linearSearch(S a[], int n, int Key) {
  a[n].ma = Key;
  int i = 0;
  while (Key != a[i].ma)
    i++;
  if (i < n) return i;
  return -1;
}
//=========================================================================
int BinarySearchTang(S a[], int n, int key) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid].ma == key)
      return mid;
    if (a[mid].ma < key)
      left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}
//=========================================================================
void bubblesort_tang(S a[], int n)		//masach
{
  int i, j;
  for (i = 0;i < n - 1;i++)
    for (j = n - 1;j > i;j--)
      if (a[j - 1].ma > a[j].ma)
        swap(a[j], a[j - 1]);
}
//=========================================================================
void selectionsort_tang(S a[], int n)		//tensach
{
  int vtmin;
  for (int i = 0; i < n - 1; i++) {									//xep theo chu cai phai hk a,b,c,d... dung roi do  thay ko ? ok roi do <3
    vtmin = i;
    for (int j = i + 1; j < n; j++) {
      if (stricmp(a[j].ten, a[vtmin].ten) < 0) // stricmp la ham` so sanh chuoi~ neu <0 thi chuoi a[i] nho hon a[vtmin] = 0 thi bang nhau
                        // >0 thi a[j] > a[vtmin]  -> neu a[j] nho hon la no thuoc nhung chu~ cai dau tien (a,b,c) nen cho no len dau`
      {
        vtmin = j;
      }
    }
    swap(a[vtmin], a[i]);

  }
}
//=========================================================================
void SapXepTang(S a[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i].ma > a[j].ma)
        swap(a[i], a[j]);
}
//=========================================================================
void XuatMenu(int& chon) {
  printf("\n|=========|===============MENU=======================|");
  printf("\n|  Phim   |\t\tCong viec\t       	     |");
  printf("\n|=========|==========================================|");
  printf("\n|  \\1\\    |\tLinearSearch ma sach!                | ");
  printf("\n|=========|==========================================|");
  printf("\n|  \\2\\    |\tBinarySearch ma sach!                |");
  printf("\n|=========|==========================================|");
  printf("\n|  \\3\\    |\tBubblesort_tang theo ma sach!        |");
  printf("\n|=========|==========================================|");
  printf("\n|  \\4\\    |\tSelectionsort_tang theo ten sach!    |");
  printf("\n|=========|==========================================|");
  printf("\n|  \\0\\    |\t\tThoat!                       |");
  printf("\n|=========|==========================================|");
  printf("\n\nMoi ban chon chuc nang:");	scanf("%d", &chon);
}
//=========================================================================
void Copy(S a[], int n, S b[]) {
  for (int i = 0;i < n;i++) {
    b[i] = a[i];
  }
}//=========================================================================
int main() {
  S a[MAX] = {
        {190001,"Dac Nhan Tam"},
        {190003,"Ban Dat Gia Bao Nhieu?"},
        {190007,"Doi Ngan Dung Ngu Dai"},
        {190002,"Tuoi Tre Dang Gia Bao Nhieu"},
        {190005,"Dung Lua Chon An Nhan Khi Con Tre"},
        {190009,"Kheo An Noi Se Co Duoc Thien Ha"},
        {190004,"Cafe Cung TONY"}
  };
  S b[MAX];
  int n = 7;
  int chon;
  int X, vtma;
  int kq;
  printf("\n ==================Thong tin sach ban dau==================\n ");
  XuatMangCuonSach(a, n);
  do {
    printf("\n\n");
    Copy(a, n, b);
    XuatMenu(chon);
    switch (chon)
      //===============================
    {
    case 1:
      printf("\nNhap ma sach can tim ");
      scanf("%d", &X);
      kq = linearSearch(b, n, X);
      if (kq == -1)
        printf("\nTim ma sach hk co");
      else
        printf("\nTim ma sach: %d\n", X);
      printf("\n|============|====================================|");
      printf("\n|Ma sach     |\t      Ten sach                    |");
      printf("\n|============|====================================|\n");
      XuatSach(b[kq]);
      printf("\n|============|====================================|");
      break;
      //===============================
    case 2:
      SapXepTang(b, n);
      printf("\nMang Sau Khi Sap Tang \n");
      XuatMangCuonSach(b, n);
      printf("\nNhap ma sach can tim ");
      scanf("%d", &X);
      kq = BinarySearchTang(b, n, X);
      if (kq == -1)
        printf("\nTim Nhi Phan Tang Khong Co Be Oi :(( ");
      else
        printf("\nTim Nhi Phan Tang Tai Vi Tri: %d", kq);
      printf("\n|============|====================================|");
      printf("\n|Ma sach     |\t      Ten sach                    |");
      printf("\n|============|====================================|\n");
      XuatSach(b[kq]);
      printf("\n|============|====================================|");
      break;
      //===============================
    case 3:
      //					printf("\n ==================Thong tin sach ban dau==================\n ");
      //					XuatMangCuonSach(b,n);
      bubblesort_tang(b, n);
      printf("\n ==================Bubblesort_MaSachtang==================\n ");
      XuatMangCuonSach(b, n);
      break;
      //===============================
    case 4:
      //					printf("\n ==================Thong tin sach ban dau==================\n ");
      //					XuatMangCuonSach(b,n);
      selectionsort_tang(b, n);
      printf("\n ==================Selectionsort_TenSacntang==================\n ");
      XuatMangCuonSach(b, n);
      break;
    }
  } while (chon != 0);
  return 0;
}
