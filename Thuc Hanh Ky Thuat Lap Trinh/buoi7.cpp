#include <iostream>
using namespace std;
#define MAX 100

struct NhanVien {
  char ten[50];
  int luongCB;
  float heSoLuong;
};
struct CongTy {
  NhanVien ds[100];
  int soLuong;
};
void nhapNhanVien(NhanVien& nv);
void xuatNhanVien(NhanVien nv);
void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv);
void xuatDanhSachNhanVien(DanhSachNhanVien dsnv);
bool ghiDanhSachNhanVien(DanhSachNhanVien ds, char* tenFile);
bool docDanhSachNhanVien(DanhSachNhanVien& ds, char* tenFile);

int main() {
  NhanVien nv;
  DanhSachNhanVien ds1, ds2;
  cout << endl;
  system("pause");
  return 0;
}

void nhapNhanVien(NhanVien& nv) {
  cout << "Nhap ten nhan vien: ";
  cin.getline(nv.ten, 50);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 50);
  cout << "He so luong: ";
  cin >> nv.heSoLuong;
  cout << endl;
  cin.ignore();
}

void xuatNhanVien(NhanVien nv) {
  cout << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(DanhSachNhanVien& dsnv) {
  do {
    cout << "\nNhap so luong nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}

void xuatDanhSachNhanVien(DanhSachNhanVien dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++) {
    xuatNhanVien(dsnv.ds[i]);
  }
}

bool ghiDanhSachNhanVien(DanhSachNhanVien ds, char* tenFile) {
  FILE* f;
  fopen_s(&f, tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&ds.soLuong, sizeof(int), 1, f);
  fwrite(&ds.ds, sizeof(NhanVien), ds.soLuong, f);
  fclose(f);
  return true;
}