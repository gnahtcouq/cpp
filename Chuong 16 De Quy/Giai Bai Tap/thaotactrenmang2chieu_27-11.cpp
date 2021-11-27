#include <iostream>
#include <limits.h>
using namespace std;

/*

De bai: Nhap vao mang 2 chieu cac so nguyen
xuat ra mang vua nhap va thuc hien cac thao tac sau:
a/ Tinh tong cac phan tu cua mang
b/ Tim min - max cua mang
c/ Dem so luong cac so chan trong mang
d/ Sap xep mang tang dan/giam dan theo chieu tu tren xuong duoi, tu trai sang phai

Yeu cau: lam hoan toan bang de quy


*/

// void nhapMang1(int *a, int n) {
//   if (n == 0)
//     return;
//   nhapMang1(a, n - 1);
//   cout << "\nNhap vao a[" << n - 1 << "] = ";
//   cin >> a[n - 1];
// }

void nhapMang(int **a, int dong, int cot, int i = 0) { // de quy duoi
  if (i == dong * cot)
    return; // Ket thuc
  cout << "\nNhap vao a[" << i / cot << "]" << "[" << i % cot << "]= ";
  cin >> a[i / cot][i % cot];
  nhapMang(a, dong, cot, i + 1);
}

void xuatMang(int **a, int dong, int cot, int i = 0) {
  if (i == dong * cot)
    return;
  if (i % cot == 0)
    cout << "\n";
  cout << a[i / cot][i % cot] << " ";
  xuatMang(a, dong, cot, i + 1);
}

int tinhTong(int **a, int dong, int cot, int i = 0, int tong = 0) {
  if (i == dong * cot)
    return tong;
  return tinhTong(a, dong, cot, i + 1, tong + a[i / cot][i % cot]);
}

int timMin(int **a, int dong, int cot, int i = 0, int min = INT_MAX) {
  if (i == dong * cot)
    return min;
  return timMin(a, dong, cot, i + 1, a[i / cot][i % cot] < min ? a[i / cot][i % cot] : min);
}

int timMax(int **a, int dong, int cot, int i = 0, int max = INT_MIN) {
  if (i == dong * cot)
    return max;
  return timMax(a, dong, cot, i + 1, a[i / cot][i % cot] > max ? a[i / cot][i % cot] : max);
}

int demChan(int **a, int dong, int cot, int i = 0, int dem = 0) {
  if (i == dong * cot)
    return dem;
  return demChan(a, dong, cot, i + 1, a[i / cot][i % cot] % 2 == 0 ? dem + 1 : dem);
}

void hoanVi(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void sapXepTangDan(int **a, int dong, int cot, int i = 0) {
  if (i == dong * cot - 1)
    return;
  for(int k = i + 1; k < dong * cot; k++) {
    if(a[i / cot][i % cot] > a[k / cot][k % cot])
      hoanVi(a[i / cot][i % cot], a[k / cot][k % cot]);
  }
  sapXepTangDan(a, dong, cot, i + 1);
}

void sapXepGiamDan(int **a, int dong, int cot, int i = 0) {
  if (i == dong * cot - 1)
    return;
  for(int k = i + 1; k < dong * cot; k++) {
    if(a[i / cot][i % cot] < a[k / cot][k % cot])
      hoanVi(a[i / cot][i % cot], a[k / cot][k % cot]);
  }
  sapXepGiamDan(a, dong, cot, i + 1);
}

int main() {
  int dong = 3, cot = 3;
  int **a = new int*[dong]; // cap phat so dong
  
  // voi moi dong thi cap phat cot tuong ung
  for(int i = 0; i < dong; i++){
    a[i] = new int[cot];
  }

  nhapMang(a, dong, cot);
  // nhapMang1(a, n);
  xuatMang(a, dong, cot);

  cout << "\nTong = " << tinhTong(a, dong, cot);
  cout << "\nMin = " << timMin(a, dong, cot);
  cout << "\nMax = " << timMax(a, dong, cot);
  cout << "\nDem chan = " << demChan(a, dong, cot);

  sapXepTangDan(a, dong, cot);
  cout << "\nMang sau khi sap tang dan la: ";
  xuatMang(a, dong, cot);

  sapXepGiamDan(a, dong, cot);
  cout << "\nMang sau khi sap giam dan la: ";
  xuatMang(a, dong, cot);

  // Giai phong con tro cap 2
  for(int i = 0; i < dong; i++) {
    delete[] a[i];
  }
  delete[] a;
  cout << endl;
  return 0;
}