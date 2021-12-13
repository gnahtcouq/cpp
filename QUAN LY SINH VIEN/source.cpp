#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

#define MAX 100


struct SinhVien {
  char maSV[10];
  char hoTen[30];
  char ngaySinh[15];
  float diemTB;
};
typedef struct SinhVien SINHVIEN;

struct LopHop {
  int soLuong;
  SINHVIEN data[MAX];
};
typedef struct LopHop LOPHOC;


// void nhapSinhVien(SINHVIEN &sv);
// void xuatSinhVien(SINHVIEN sv);
// void nhapDanhSachSinhVien(LOPHOC &dssv);
// void xuatDanhSachSinhVien(LOPHOC dssv);
// bool ghiDanhDachSinhVien(LOPHOC dssv, char* tenFile);
// bool docDanhDachSinhVien(LOPHOC& dssv, char* tenFile);
// bool themSinhVien(LOPHOC& dssv, SINHVIEN sv);
// void hienThiMenu();
void docThongTinMotSinhVien(ifstream &FileIn, SINHVIEN sv);
void xuatThongTinMotSinhVien(SINHVIEN sv);

int main() {
  // SINHVIEN sv;
  // LOPHOC ds;
  // nhapSinhVien(sv);
  // xuatSinhVien(sv);

  // nhapDanhSachSinhVien(ds);
  // xuatDanhSachSinhVien(ds);

  /* ---------- GHI DANH SACH SINH VIEN ---------- */
  // nhapDanhSachSinhVien(ds);
  // if (ghiDanhDachSinhVien(ds, (char *)"danhsachsinhvien.dat"))
  //   cout << "\nGhi file thanh cong" << endl;
  // else
  //   cout << "\nGhi file khong duoc";
  // xuatDanhSachSinhVien(ds);

  /* ---------- DOC DANH SACH SINH VIEN ---------- */
  // if (docDanhDachSinhVien(ds, (char *)"danhsachsinhvien.dat")) {
  //   cout << "\nThong tin cua cac nhan vien vua doc la: " << endl;
  //   xuatDanhSachSinhVien(ds);
  // }
  // else {
  //   cout << "\nDoc khong duoc";
  //   exit;
  // }

  // hienThiMenu();

  
  SINHVIEN sv;
  ifstream FileIn;
  FileIn.open("sinhvien.txt", ios::in);
  docThongTinMotSinhVien(FileIn, sv);
  xuatThongTinMotSinhVien(sv);
  FileIn.close();

  system("pause");
  return 0;
}

// void nhapSinhVien(SINHVIEN &sv) {
//   fflush(stdin);
//   cout << "\n\tNhap MSSV: ";
//   cin.getline(sv.maSV, 15);
//   cout << "\tNhap ho ten: ";
//   cin.getline(sv.hoTen, 30);
//   cout << "\tNhap ngay sinh: ";
//   cin.getline(sv.ngaySinh, 15);
//   cout << "\tNhap diem TB: ";
//   cin >> sv.diemTB;
// }

// void xuatSinhVien(SINHVIEN sv) {
//   cout << setw(15) << left << sv.maSV << "\t";
//   cout << setw(30) << left << sv.hoTen << "\t";
//   cout << setw(15) << left << sv.ngaySinh << "\t";
//   cout << setw(10) << left << sv.diemTB << "\t" << endl;
// }

// void nhapDanhSachSinhVien(LOPHOC &dssv) {
//   cout << "\nNhap so luong Sinh Vien: ";
//   cin >> dssv.soLuong;
//   for (int i = 0; i < dssv.soLuong; i++) {
//     cout << "\nNhap sinh vien thu " << i + 1;
//     nhapSinhVien(dssv.data[i]);
//   }
// }

// void xuatDanhSachSinhVien(LOPHOC dssv) {
//   cout << setw(15) << left << "MSSV" << "\t";
//   cout << setw(30) << left << "Ho ten" << "\t";
//   cout << setw(15) << left << "Ngay sinh" << "\t";
//   cout << setw(10) << left << "Diem TB" << "\t" << endl;
//   for (int i = 0; i < dssv.soLuong; i++) {
//     xuatSinhVien(dssv.data[i]);
//   }
// }

void docThongTinMotSinhVien(ifstream &FileIn, SINHVIEN sv) {
  FileIn.getline(sv.hoTen, ',');
  FileIn.seekg(1, FileIn.cur);
  FileIn.getline(sv.maSV, ',');
  FileIn.seekg(1, FileIn.cur);
  FileIn.getline(sv.ngaySinh, ',');
  FileIn.seekg(2, FileIn.cur);
  FileIn >> sv.diemTB;
}

void xuatThongTinMotSinhVien(SINHVIEN sv) {
  cout << "\nHo ten: " << sv.hoTen;
  cout << "\nMSSV: " << sv.maSV;
  cout << "\nNgay sinh: " << sv.ngaySinh;
  cout << "\nDiem TB: " << sv.diemTB;
}

// void hienThiMenu() {
//   SINHVIEN sv;
//   LOPHOC ds;
//   int chon = 0;
//   do {
//     cout << "\n\tQUAN LY SINH VIEN";
//     cout << "\n0 - Thoat chuong trinh";
//     cout << "\n1 - In danh sach SV";
//     cout << "\n2 - Them SV";
//     cout << "\n3 - ";
//     cout << "\n4 - ";
//     cout << "\n5 - ";
//     cout << "\n6 - ";
//     cout << "\n7 - ";
//     cout << "\nVui long chon: ";
//     cin >> chon;
//     switch (chon) {
//     case 0:
//       break;
//     case 1:
//       if (docDanhDachSinhVien(ds, (char *)"danhsachsinhvien.dat")) {
//         cout << "\n\t\t\tDANH SACH SINH VIEN" << endl;
//         xuatDanhSachSinhVien(ds);
//       }
//       else {
//         cout << "\nKhong tim thay";
//         exit;
//       }
//       break;
//     case 2:
//       themSinhVien(ds, sv);
//       break;
//     case 3:
//       break;
//     case 4:
//       break;
//     case 5:
//       break;
//     case 6:
//       break;
//     case 7:
//       break;
//     default:
//       cout << "\nLua chon cua ban khong co trong Menu. Hay thu lai !";
//       break;
//     }
//   } while (chon != 0);
// }