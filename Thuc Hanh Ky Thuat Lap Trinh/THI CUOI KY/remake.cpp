#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 100

struct TrangPhuc {
  char maSP[5];
  char tenSP[30];
  char boSuuTap[15];
  float donGia;
};

struct DaySo {
  int n;
  TrangPhuc data[MAX];
};

void nhap_MotTrangPhuc(TrangPhuc &tp);
void xuat_MotTrangPhuc(TrangPhuc tp);
void nhap_DSTP(DaySo &ds);
void xuat_DSTP(DaySo ds);
bool themTrangPhuc(DaySo &ds);
bool timKiemThongTinTrangPhuc(DaySo ds, char *str);
void xoaTrangPhucTaiViTri(DaySo &ds, int vitri);
bool xoaTenTrangPhuc(DaySo &ds, char *str);
int demSoLuongTrangPhucTrongBoSuuTap(DaySo ds, char *str);
void demSoLuongTrangPhucTheoBoSuuTap(DaySo ds);
void sapXepTrangPhucTheoDonGia(DaySo &ds);
void hienThiMenu();

int main() {
  hienThiMenu();

  system("pause");
  return 0;
}

void nhap_MotTrangPhuc(TrangPhuc &tp) {
  cout << "\nNhap ma SP: ";
  cin >> tp.maSP;
  cout << "Nhap ten SP: ";
  cin.ignore();
  cin.getline(tp.tenSP, 30);
  cout << "Nhap ten bo suu tap: ";
  cin.getline(tp.boSuuTap, 15);
  cout << "Nhap don gia: ";
  cin >> tp.donGia;
  cout << endl;
}

void xuat_MotTrangPhuc(TrangPhuc tp) {
  cout << "\nMa TP: " << tp.maSP;
  cout << "\nTen TP: " << tp.tenSP;
  cout << "\nBo suu tap: " << tp.boSuuTap;
  cout << "\nDon gia: " << tp.donGia;
  cout << endl;
}

void nhap_DSTP(DaySo &ds) {
  cout << "\nNhap so luong TP: ";
  cin >> ds.n;
  for (int i = 0; i < ds.n; i++) {
    nhap_MotTrangPhuc(ds.data[i]);
  }
}

void xuat_DSTP(DaySo ds) {
  for (int i = 0; i < ds.n; i++) {
    xuat_MotTrangPhuc(ds.data[i]);
  }
}

bool themTrangPhuc(DaySo &ds) {
  int vitrithem = 0;
  TrangPhuc tp;
  nhap_MotTrangPhuc(tp);
  for (int i = ds.n - 1; i >= vitrithem; i--) {
    ds.data[i + 1] = ds.data[i];
  }
  ds.data[vitrithem] = tp;
  ds.n++;
  return true;
}


bool timKiemThongTinTrangPhuc(DaySo ds, char *str) {
  for (int i = 0; i < ds.n; i++) {
    if (strcmp(ds.data[i].maSP, str) == 0) {
      xuat_MotTrangPhuc(ds.data[i]);
      return true;
    }
  }
  return false;
}

void xoaTrangPhucTaiViTri(DaySo &ds, int vitri) {
  if (vitri < 0 || vitri > ds.n)
    cout << "\nVi tri khong hop le";
  else {
    for (int i = vitri + 1; i <= ds.n; i++)
      ds.data[i - 1] = ds.data[i];
    ds.n--;
  }
}

bool xoaTenTrangPhuc(DaySo &ds, char *str) {
  for (int i = 0; i < ds.n; i++) {
    if (strcmp(ds.data[i].tenSP, str) == 0) {
      xoaTrangPhucTaiViTri(ds, i);
      return true;
    }
  }
  return false;
}

int demSoLuongTrangPhucTrongBoSuuTap(DaySo ds, char *str) {
  int dem = 0;
  for (int i = 0; i < ds.n; i++)
    if (strcmp(ds.data[i].boSuuTap, str) == 0)
      dem++;
  return dem;
}


void demSoLuongTrangPhucTheoBoSuuTap(DaySo ds) {
  char a[100][100];
  strcpy(a[0], ds.data[0].boSuuTap);
  int x = 1;
  for (int i = 1; i < ds.n; i++) {
    int dem = 0;
    for (int j = 0; j < x; j++)
      if (strcmp(ds.data[i].boSuuTap, a[j]) == 0)
        dem++;
    if (dem == 0) {
      strcpy(a[x], ds.data[i].boSuuTap);
      x++;
    }
  }

  for (int j = 0; j < x; j++) {
    int dem = 0;
    for (int i = 0; i < ds.n; i++)
      if (strcmp(ds.data[i].boSuuTap, a[j]) == 0)
        dem++;
    cout << "BST " << a[j] << " co " << dem << " trang phuc" << endl;
  }
}

void sapXepTrangPhucTheoDonGia(DaySo &ds) {
  for (int i = 0; i < ds.n; i++) {
    for (int j = i + 1; j < ds.n; j++) {
      if (ds.data[i].donGia > ds.data[j].donGia) {
        TrangPhuc tam = ds.data[i];
        ds.data[i] = ds.data[j];
        ds.data[j] = tam;
      }
    }
  }
}

void hienThiMenu() {
  TrangPhuc tp;
  DaySo ds;
  int chon = 0;
  do {
    cout << "\n0 - Thoat chuong trinh";
    cout << "\n1 - Nhap danh sach TP";
    cout << "\n2 - Xuat danh sach TP";
    cout << "\n3 - Them TP";
    cout << "\n4 - Tim thong tin SP";
    cout << "\n5 - Xoa SP";
    cout << "\n6 - Dem so luong SP trong BST";
    cout << "\n7 - Sap xep danh sach TP theo don gia";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      nhap_DSTP(ds);
      break;
    case 2:
      xuat_DSTP(ds);
      break;
    case 3:
      cout << "\nNhap trang phuc can them";
      if (themTrangPhuc(ds))
        cout << "Them trang phuc thanh cong" << endl;
      break;
    case 4:
      char str[5];
      cout << "\nNhap ma TP can xuat thong tin: ";
      cin.ignore();
      cin.getline(str, 5);
      if (!timKiemThongTinTrangPhuc(ds, str))
        cout << "\nKhong tim thay, hay thu lai" << endl;
      break;
    case 5:
      char str2[30];
      cout << "\nNhap ten SP can xoa: ";
      cin.ignore();
      cin.getline(str2, 30);
      if (!xoaTenTrangPhuc(ds, str2))
        cout << "Xoa trang phuc khong thanh cong";
      break;
    case 6:
      char str3[15];
      cout << "\nNhap ten BST can dem so luong trang phuc: ";
      cin.ignore();
      cin.getline(str3, 15);
      cout << "So luong trang phuc co trong BST " << str3 << " la: " << demSoLuongTrangPhucTrongBoSuuTap(ds, str3) << endl;
      break;
    case 7:
      cout << "\nSap xep trang phuc theo don gia";
      sapXepTrangPhucTheoDonGia(ds);
      break;
    case 8:
      demSoLuongTrangPhucTheoBoSuuTap(ds);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}