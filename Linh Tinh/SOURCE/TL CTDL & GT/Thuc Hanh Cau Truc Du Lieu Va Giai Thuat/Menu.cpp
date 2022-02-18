#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//*~~~~~~~~~~~~~~~~~~
//Quach Quang Minh
void NhapSL(int& n) {
  do {
    printf("Nhap so phan tu, 0 < SL < %d: ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
      printf("\nBan da nhap sai!");
    }
  } while (n <= 0 || n > MAX);
}
//*----------------
void NhapMang(char a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("a[%d]= ", i);
    fflush(stdin);
    scanf("%c", &a[i]);
  }
}
//*----------------
void XuatMang(char a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%5c", a[i]);
  }
}
//*----------------
char NgauNhien_Float(char x, char y) {
  //	return x + rand() % (y-x+1);
  return x + (y - x) * rand() / RAND_MAX;
}
//*----------------
void PhatSinhMang(char a[], int n, char x, char y) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    a[i] = NgauNhien_Float(x, y);
  }
}
//*----------------
char TimTuyenTinh(char a[], int n, char X) {
  int i = 0;
  while (i < n && X != a[i]) {
    i++;
  }
  if (i < n) {
    return i;
  }
  return -1;
}
//*----------------
void Swap(char& x, char& y) {
  char temp = x;
  x = y;
  y = temp;
}
//*----------------
void SapXep_Tang(char a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}
//*----------------
char TimNhiPhan_Tang(char a[], int n, char X) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] == X) {
      return mid;
    }
    if (a[mid] < X) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}
//*----------------
void SapXep_Giam(char a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}
//*----------------
char TimNhiPhan_Giam(char a[], int n, char X) {
  int left = 0, right = n - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] == X) {
      return mid;
    }
    if (a[mid] > X) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}
//*---------------
void bubblesort_tang(char a[], int n) {
  int i, j;
  for (i = 0;i < n - 1;i++)
    for (j = n - 1;j > i;j--)
      if (a[j - 1] > a[j])
        Swap(a[j], a[j - 1]);
}
void bubblesort_giam(char a[], int n) {
  int i, j;
  for (i = 0;i < n - 1;i++)
    for (j = n - 1;j > i;j--)
      if (a[j - 1] < a[j])
        Swap(a[j], a[j - 1]);
}
void selectionsort_tang(char a[], int n) {
  int i;
  int min;
  for (i = 0;i < n - 1;i++) {
    min = i;
    for (int j = i + 1;j < n;j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    Swap(a[min], a[i]);
  }
}
void selectionsort_giam(char a[], int n) {
  int i;
  int min;
  for (i = 0;i < n - 1;i++) {
    min = i;
    for (int j = i + 1;j < n;j++) {
      if (a[j] > a[min]) {
        min = j;
      }
    }
    Swap(a[min], a[i]);
  }
}
void insertsort_tang(char a[], int n) {
  int pos, x;
  for (int i = 1;i < n;i++) {
    x = a[i];
    pos = i - 1;
    while (pos >= 0 && a[pos] > x) {
      a[pos + 1] = a[pos];
      pos--;
    }
    a[pos + 1] = x;
  }
}
void insertsort_giam(char a[], int n) {
  int pos, x;
  for (int i = 1;i < n;i++) {
    x = a[i];
    pos = i - 1;
    while (pos >= 0 && a[pos] < x) {
      a[pos + 1] = a[pos];
      pos--;
    }
    a[pos + 1] = x;
  }
}
void quicksort_tang(char a[], int left, int right) {
  int i, j, x;
  x = a[(left + right) / 2];
  i = left;
  j = right;
  do {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      Swap(a[i], a[j]);
      i++;
      j--;
    }
  } while (i < j);
  if (left < j)
    quicksort_tang(a, left, j);
  if (right > i)
    quicksort_tang(a, i, right);
}
void quicksort_giam(char a[], int left, int right) {
  int i, j, x;
  x = a[(left + right) / 2];
  i = left;
  j = right;
  do {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      Swap(a[i], a[j]);
      i++;
      j--;
    }
  } while (i < j);
  if (left < j)
    quicksort_giam(a, left, j);
  if (right > i)
    quicksort_giam(a, i, right);
}
void Copy(char a[], int n, char b[]) {
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
}
void XuatMenu(int& chon) {
  printf("\n\n\t\t===========MENU============\n\n");
  printf("\n1: TimTuyenTinh");
  printf("\n2: SapXep_Giam");
  printf("\n3: SapXep_Tang");
  printf("\n4: TimNhiPhanTang");
  printf("\n5: TimNhiPhanGiam");
  printf("\n6: BubblesortTang");
  printf("\n7: BubblesortGiam");
  printf("\n8: SelectionsortTang");
  printf("\n9: SelectionsortGiam");
  printf("\n10: InsertsortTang");
  printf("\n11: InsertsortGiam");
  printf("\n12: QuicksortTang");
  printf("\n13: QuicksortGiam");
  printf("\n0: Thoat\n");
  printf("\nHay chon cong viec: ");
  scanf("%d", &chon);
}
//*~~~~~~~~~~~~~~~~~~
int main() {
  //	float a[MAX];
  //	int n;

  char a[MAX] = { 98 , 97, 100, 99, 101, 102, 103, 104, 105, 106 };
  int n = 10;
  char b[MAX];
  char X;
  char ph;
  int kq;
  //	NhapSL(n);
  //	NhapMang(a,n);
  //	PhatSinhMang(a,n,-2.5,15.6);
  XuatMang(a, n);
  int chon;
  int left;
  int right;
  do {
    Copy(a, n, b);
    XuatMenu(chon);
    switch (chon) {

    case 1:
      printf("\nMang ban dau:\n");
      XuatMang(b, n);
      printf("\nKy tu can tim: ");
      fflush(stdin);
      scanf("%c", &X);
      kq = TimTuyenTinh(b, n, X);
      if (kq == -1) {
        printf("\nTim tuyen tinh khong co!");
      }
      else {
        printf("\nTim tuyen tinh: %c ton tai vi tri: %d", X, kq);
      }
      break;
    case 2:
      printf("\nMang ban dau:\n");
      XuatMang(b, n);
      SapXep_Giam(b, n);
      printf("\nMang sau khi sap xep giam:\n");
      XuatMang(b, n);
      break;
    case 3:
      printf("\nMang ban dau:\n");
      XuatMang(b, n);
      SapXep_Tang(b, n);
      printf("\nMang sau khi sap xep tang:\n");
      XuatMang(b, n);
      break;
    case 4:
      SapXep_Tang(b, n);
      printf("Mang sau khi tang: \n");
      XuatMang(b, n);
      kq = TimNhiPhan_Tang(b, n, X);
      if (kq == -1) {
        printf("\nTim nhi phan khong co!");
      }
      else {
        printf("\nTim nhi phan: %c ton tai vi tri: %d", X, kq);
      }
      break;
    case 5:
      SapXep_Giam(b, n);
      printf("Mang sau khi tang: \n");
      XuatMang(b, n);
      kq = TimNhiPhan_Giam(b, n, X);
      if (kq == -1) {
        printf("\nTim nhi phan khong co!");
      }
      else {
        printf("\nTim nhi phan: %c ton tai vi tri: %d", X, kq);
      }
      break;
    default: chon = 0;
      break;
    case 6:
      printf("\n=====================MANG BAN DAU====================\n");
      XuatMang(b, n);
      bubblesort_tang(b, n);
      printf("\n=====================MANG SAU KHI TANG====================\n");
      XuatMang(b, n);
      break;
    case 7:
      printf("\n=====================MANG BAN DAU====================\n");
      XuatMang(b, n);
      bubblesort_giam(b, n);
      printf("\n=====================MANG SAU KHI GIAM====================\n");
      XuatMang(b, n);
      break;
    case 8:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      selectionsort_tang(b, n);
      printf("\n =============================selection_tang===========================\n ");
      XuatMang(b, n);
      break;
    case 9:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      selectionsort_giam(b, n);
      printf("\n =============================selection_giam===========================\n ");
      XuatMang(b, n);
      break;
    case 10:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      insertsort_tang(b, n);
      printf("\n =============================insertsort_tang===========================\n ");
      XuatMang(b, n);
      break;
    case 11:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      insertsort_giam(b, n);
      printf("\n =============================insertsort_giam===========================\n ");
      XuatMang(b, n);
      break;
    case 12:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      quicksort_tang(b, left, right);
      printf("\n =============================quicksort_tang===========================\n ");
      XuatMang(b, n);
      break;
    case 13:
      printf("\n =============================MANG BAN DAU===========================\n ");
      XuatMang(b, n);
      quicksort_giam(b, left, right);
      printf("\n =============================quicksort_giam===========================\n ");
      XuatMang(b, n);
      break;
    }
  } while (chon != 0);
}
//	do
//	{
//		printf("\nNhap gia tri can tim: ");
//		scanf("%f", &X);
//		
//		kq=TimTuyenTinh(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim tuyen tinh khong co!");
//		}
//		else
//		{
//			printf("\nTim tuyen tinh: %f ton tai vi tri: %d",X,kq);
//		}
//		
//		SapXep_Tang(a,n);
//		printf("\nMang sau khi tang:\n");
//		XuatMang(a,n);
//		kq=TimNhiPhan_Tang(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim nhi phan khong co!");
//		}
//		else
//		{
//			printf("\nTim nhi phan: %.1f ton tai vi tri %d",X,kq);
//		}
//		
//		SapXep_Giam(a,n);
//		printf("\nMang sau khi giam:\n");
//		XuatMang(a,n);
//		kq=TimNhiPhan_Giam(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim nhi phan khong co!");
//		}
//		else
//		{
//			printf("\nTim nhi phan: %.1f ton tai vi tri %d",X,kq);
//		}
//				
//		printf("\n\nBan co muon tiep tuc khong[Y/N]: ");
//		ph=getche();
//	}while(ph == 'Y' || ph == 'y');
//	do
//	{
//		Copy(a,n,b);
//		printf("\nKy tu can tim: ");
//		fflush(stdin);
//		scanf("%c", &X);
//		kq=TimTuyenTinh(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim tuyen tinh khong co!");
//		}
//		else
//		{
//			printf("\nTim tuyen tinh: %c ton tai vi tri: %d",X,kq);
//		}
//		SapXep_Tang(a,n);
//		printf("\nMang sau khi tang:\n");
//		XuatMang(a,n);
//		kq=TimNhiPhan_Tang(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim nhi phan khong co!");
//		}
//		else
//		{
//			printf("\nTim nhi phan: %c ton tai vi tri %d",X,kq);
//		}
//		SapXep_Giam(a,n);
//		printf("\nMang sau khi giam:\n");
//		XuatMang(a,n);
//		kq=TimNhiPhan_Giam(a,n,X);
//		if(kq == -1)
//		{
//			printf("\nTim nhi phan khong co!");
//		}
//		else
//		{
//			printf("\nTim nhi phan: %c ton tai vi tri %d",X,kq);
//		}
//		printf("\n\nBan co muon tiep tuc khong[Y/N]: ");
//		ph=getche();
//	}while(ph == 'Y' || ph == 'y');
//	return 0;
//}
