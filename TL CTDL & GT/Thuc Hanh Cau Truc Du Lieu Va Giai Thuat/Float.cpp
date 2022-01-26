#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
//*~~~~~~~~~~~~~~~~~~
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
void NhapMang(float a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("a[%d]= ", i);
    scanf("%f", &a[i]);
  }
}
//*----------------
void XuatMang(float a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%7.1f", a[i]);
  }
}
//*----------------
float NgauNhien_Float(float x, float y) {
  //	return x + rand() % (y-x+1);
  return x + (y - x) * rand() / RAND_MAX;
}
//*----------------
void PhatSinhMang(float a[], int n, float x, float y) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    a[i] = NgauNhien_Float(x, y);
  }
}
//*----------------
int TimTuyenTinh(float a[], int n, float X) {
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
void Swap(float& x, float& y) {
  float temp = x;
  x = y;
  y = temp;
}
//*----------------
void SapXep_Tang(float a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}
//*----------------
int TimNhiPhan_Tang(float a[], int n, float X) {
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
void SapXep_Giam(float a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        Swap(a[i], a[j]);
      }
    }
  }
}
//*----------------
int TimNhiPhan_Giam(float a[], int n, float X) {
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
void Copy(float a[], int n, float b[]) {
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
}
//*~~~~~~~~~~~~~~~~~~
int main() {
  //	float a[MAX];
  //	int n;
  float a[MAX] = { 1.5, -2.6, 3.0, 0.0, -5.9, 12.0, -8.1, 10.2, -0.5, 3.7 };
  int n = 10;
  float b[MAX];
  float X;
  char ph;
  int kq;
  //	NhapSL(n);
  //	NhapMang(a,n);
  //	PhatSinhMang(a,n,-2.5,15.6);
  XuatMang(a, n);
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
  do {
    Copy(a, n, b);
    printf("\nNhap gia tri can tim: ");
    scanf("%f", &X);
    kq = TimTuyenTinh(a, n, X);
    if (kq == -1) {
      printf("\nTim tuyen tinh khong co!");
    }
    else {
      printf("\nTim tuyen tinh: %.1f ton tai vi tri: %d", X, kq);
    }
    SapXep_Tang(a, n);
    printf("\nMang sau khi tang:\n");
    XuatMang(a, n);
    kq = TimNhiPhan_Tang(a, n, X);
    if (kq == -1) {
      printf("\nTim nhi phan khong co!");
    }
    else {
      printf("\nTim nhi phan: %.1f ton tai vi tri %d", X, kq);
    }
    SapXep_Giam(a, n);
    printf("\nMang sau khi giam:\n");
    XuatMang(a, n);
    kq = TimNhiPhan_Giam(a, n, X);
    if (kq == -1) {
      printf("\nTim nhi phan khong co!");
    }
    else {
      printf("\nTim nhi phan: %.1f ton tai vi tri %d", X, kq);
    }
    printf("\n\nBan co muon tiep tuc khong[Y/N]: ");
    ph = getche();
  } while (ph == 'Y' || ph == 'y');
  return 0;
}
