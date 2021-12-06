#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

struct CuaHang {
  char maCH[5];
  char tenCH[30];
  int soNha;
  char tenDuong[30];
  char phuong[30];
  char quan[10];
  char thanhPho[30];
};
struct DaySo {
  int soLuong;
  CuaHang data[MAX];
};

void nhapCuaHang(CuaHang& ch);
void xuatCuaHang(CuaHang ch);
void nhapDanhSachCuaHang(DaySo& ds);
void xuatDanhSachCuaHang(DaySo ds);
int demSoLuongCuaHangChuaTen(DaySo ds);

int main() {
  CuaHang ch;
  DaySo ds;
  // nhapCuaHang(ch);
  // xuatCuaHang(ch);
  nhapDanhSachCuaHang(ds);
  xuatDanhSachCuaHang(ds);

  cout << "\nSo luong " << demSoLuongCuaHangChuaTen(ds);

  return 0;
}

void nhapCuaHang(CuaHang& ch) {
  cout << "Nhap ma CH: ";
  cin >> ch.maCH;
  cout << "Nhap ten CH: ";
  cin.ignore();
  cin.getline(ch.tenCH, 30);
  cout << "Nhap so nha: ";
  cin >> ch.soNha;
  cout << "Nhap ten duong: ";
  cin.ignore();
  cin.getline(ch.tenDuong, 30);
  cout << "Nhap phuong: ";
  cin.getline(ch.phuong, 30);
  cout << "Nhap quan: ";
  cin.getline(ch.quan, 10);
  cout << "Nhap thanh pho: ";
  cin.getline(ch.thanhPho, 30);
}

void xuatCuaHang(CuaHang ch) {
  cout << "\nMa CH: " << ch.maCH;
  cout << "\nTen CH: " << ch.tenCH;
  cout << "\nSo nha: " << ch.soNha;
  cout << "\nTen duong: " << ch.tenDuong;
  cout << "\nPhuong: " << ch.phuong;
  cout << "\nQuan: " << ch.quan;
  cout << "\nThanh pho: " << ch.thanhPho;
  cout << endl;
}

void nhapDanhSachCuaHang(DaySo& ds) {
  cout << "\nNhap so luong CH: ";
  cin >> ds.soLuong;
  cout << "\nNhap thong tin tung CH: ";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\nThong tin CH thu " << i + 1 << endl;
    nhapCuaHang(ds.data[i]);
  }
}

void xuatDanhSachCuaHang(DaySo ds) {
  cout << "\nDanh sach cac CH: " << endl;
  for (int i = 0; i < ds.soLuong; i++)
    xuatCuaHang(ds.data[i]);
}

int demSoLuongCuaHangChuaTen(DaySo ds) {
  char str[] = "Tong Hop";
  int dem = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (strstr(ds.data[i].tenCH, str))
      dem++;
  }
  return dem;
}