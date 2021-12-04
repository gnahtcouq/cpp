#include <iostream>
#include <limits.h>
using namespace std;

/*

De bai: Nhap vao mang 1 chieu cac so nguyen
xuat ra mang vua nhap va thuc hien cac thao tac sau:
a/ Tinh tong cac phan tu cua mang
b/ Tim min - max cua mang
c/ Dem so luong cac so chan trong mang
d/ Sap xep mang tang dan/giam dan

Yeu cau: lam hoan toan bang de quy


*/

// void nhapMang1(int *a, int n) {
//   if (n == 0)
//     return;
//   nhapMang1(a, n - 1);
//   cout << "\nNhap vao a[" << n - 1 << "] = ";
//   cin >> a[n - 1];
// }

void nhapMang(int *a, int n, int i = 0) { // de quy duoi
  if (i == n)
    return; // Ket thuc
  cout << "\nNhap vao a[" << i << "] = ";
  cin >> a[i];
  nhapMang(a, n, i + 1);
}

void xuatMang(int *a, int n, int i = 0) {
  if (i == n)
    return;
  cout << a[i] << " ";
  xuatMang(a, n, i + 1);
}

int tinhTong(int *a, int n, int i = 0, int tong = 0) {
  if (i == n)
    return tong;
  return tinhTong(a, n, i + 1, tong + a[i]);
}

int timMin(int *a, int n, int i = 0, int min = INT_MAX) {
  if (i == n)
    return min;
  return timMin(a, n, i + 1, a[i] < min ? a[i] : min);
}

int timMax(int *a, int n, int i = 0, int max = INT_MIN) {
  if (i == n)
    return max;
  return timMax(a, n, i + 1, a[i] > max ? a[i] : max);
}

int demChan(int *a, int n, int i = 0, int dem = 0) {
  if (i == n)
    return dem;
  return demChan(a, n, i + 1, a[i] % 2 == 0 ? dem + 1 : dem);
}

void hoanVi(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void sapXepTangDan(int *a, int n, int i = 0) {
  if (i == n - 1)
    return;
  for(int k = i + 1; k < n; k++) {
    if(a[i] > a[k])
      hoanVi(a[i], a[k]);
  }
  sapXepTangDan(a, n, i + 1);
}

void sapXepGiamDan(int *a, int n, int i = 0) {
  if (i == n - 1)
    return;
  for(int k = i + 1; k < n; k++) {
    if(a[i] < a[k])
      hoanVi(a[i], a[k]);
  }
  sapXepGiamDan(a, n, i + 1);
}

int tong(int a[], int n) {
  if (n == 1)
    return a[0];
  return tong(a, n - 1) + a[n - 1];
}


int main() {
  // int n = 5;
  // int *a = new int[n];
  // nhapMang(a, n);
  // // nhapMang1(a, n);
  // xuatMang(a, n);

  // cout << "\nTong = " << tinhTong(a, n);
  // cout << "\nMin = " << timMin(a, n);
  // cout << "\nMax = " << timMax(a, n);
  // cout << "\nDem chan = " << demChan(a, n);

  // sapXepTangDan(a, n);
  // cout << "\nMang sau khi sap tang dan la: ";
  // xuatMang(a, n);

  // sapXepGiamDan(a, n);
  // cout << "\nMang sau khi sap giam dan la: ";
  // xuatMang(a, n);

  int a[] = {1, 2, 3, 4, 5};
  cout << tong(a, 5);

  // delete[] a;
  cout << endl;
  return 0;
}