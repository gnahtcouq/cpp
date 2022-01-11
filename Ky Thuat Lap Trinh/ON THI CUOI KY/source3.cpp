#include <iostream>
#include <math.h>
using namespace std;
#define MAX 50

struct MangNguyen {
  int n;
  int data[MAX];
};

void nhapDaySo(MangNguyen &ds);
void xuatDaySo(MangNguyen ds);
bool KiemTraChinhPhuong(int x);
void xuatChinhPhuong(MangNguyen ds);
int timSoChinhPhuongLonNhat(MangNguyen ds);

int main() {
  MangNguyen ds;
  int n;
  cout << "\nNhap n can kiem tra la so chinh phuong: ";
  cin >> n;
  bool check = KiemTraChinhPhuong(n);
  if (check)
    cout << n << " la so chinh phuong";
  else
    cout << n << " khong phai la so chinh phuong";

  nhapDaySo(ds);
  xuatDaySo(ds);

  cout << "\nCac so chinh phuong co trong mang nguyen la: ";
  xuatChinhPhuong(ds);


  int result = timSoChinhPhuongLonNhat(ds);
  if (result == -1)
    cout << "\nKhong co so chinh phuong lon nhat";
  else
    cout << "\nSo chinh phuong lon nhat = " << result;
    
  


  system("pause");
  return 0;
}

void nhapDaySo(MangNguyen &ds) {
  do {
    cout << "\nNhap so luong phan tu: ";
    cin >> ds.n;
    if (ds.n < 1 || ds.n > MAX)
      cout << "\nNhap sai. Hay nhap lai";
  } while (ds.n < 1 || ds.n > MAX);

  for (int i = 0; i < ds.n; i++) {
    cout << "\nNhap phan tu thu " << i + 1 << " = ";
    cin >> ds.data[i];
  }
}

void xuatDaySo(MangNguyen ds) {
  for (int i = 0; i < ds.n; i++)
    cout << ds.data[i] << " ";
}

bool KiemTraChinhPhuong(int x) {
  return sqrt((float)x) == (int)sqrt((float)x);
}

void xuatChinhPhuong(MangNguyen ds) {
  for (int i = 0; i < ds.n; i++)
    if (KiemTraChinhPhuong(ds.data[i]))
      cout << ds.data[i] << " ";
}

int timSoChinhPhuongLonNhat(MangNguyen ds) {
  int soChinhPhuongDauTien;
  for (int i = 0; i < ds.n; i++) {
    if (KiemTraChinhPhuong(ds.data[i]))
      soChinhPhuongDauTien = ds.data[i];
    else
      return -1;
  }
  int soChinhPhuongLonNhat = soChinhPhuongDauTien;
  for (int i = 0; i < ds.n; i++)
    if (KiemTraChinhPhuong(ds.data[i]))
      if (ds.data[i] > soChinhPhuongLonNhat)
        soChinhPhuongLonNhat = ds.data[i];
  return soChinhPhuongLonNhat;
}