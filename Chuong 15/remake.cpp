#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define SUTU_THOIGIANBATDAU 9
#define THO_THOIGIANBATDAU 8
#define RUA_THOIGIANBATDAU 7

#define SUTU_QUANGDUONGPHAIDI 210
#define THO_QUANGDUONGPHAIDI 210
#define RUA_QUANGDUONGPHAIDI 135

struct ConVat {
  string maSo;
  int tocDo, trangBi;
};
typedef struct ConVat CONVAT;

void nhapConVat(ifstream &FileIn, CONVAT &cv) {
  FileIn >> cv.maSo;
  FileIn >> cv.tocDo;
  FileIn >> cv.trangBi;
}

void xuatConVat(ofstream &FileOut, CONVAT cv) {
  FileOut << cv.maSo << " ";
  FileOut << cv.tocDo << " ";
  FileOut << cv.trangBi << " ";
}

void nhapDanhSachConVat(ifstream &FileIn, vector<CONVAT> &danhSach) {
  int n;
  FileIn >> n;
  for (int i = 0; i < n; i++) {
    CONVAT cv;
    nhapConVat(FileIn, cv);
    danhSach.push_back(cv);
  }
}

void xuatDanhSachConVat(ofstream &FileOut, vector<CONVAT> danhSach) {
  int n = danhSach.size();
  for (int i = 0; i < n; i++) {
    xuatConVat(FileOut, danhSach[i]);
    FileOut << endl;
  }
}

int timVanTocThucSu(CONVAT cv) {
  if (cv.trangBi == 0)
    return cv.tocDo;
  else {
    if (cv.maSo[0] == 'L')
      return cv.tocDo * 2;
    else if (cv.maSo[0] == 'R')
      return cv.tocDo + 30;
    else if (cv.maSo[0] == 'T')
      return cv.tocDo * 5;
  }
}

double timThoiGianDiHetQuangDuong(CONVAT cv) {
  int vantocthucsu = timVanTocThucSu(cv);
  if (cv.maSo[0] == 'L')
    return (double)SUTU_QUANGDUONGPHAIDI / vantocthucsu;
  else if (cv.maSo[0] == 'R')
    return (double)THO_QUANGDUONGPHAIDI / vantocthucsu;
  else if (cv.maSo[0] == 'T')
    return (double)RUA_QUANGDUONGPHAIDI / vantocthucsu;
}

double timThoiGianVeDich(CONVAT cv) {
  float thoigianchay = timThoiGianDiHetQuangDuong(cv);
  if (cv.maSo[0] == 'L')
    return (double)SUTU_THOIGIANBATDAU + thoigianchay;
  else if (cv.maSo[0] == 'R')
    return (double)THO_THOIGIANBATDAU + thoigianchay;
  else if (cv.maSo[0] == 'T')
    return (double)RUA_THOIGIANBATDAU + thoigianchay;
}

void hoanVi(CONVAT &a, CONVAT &b) {
  CONVAT temp = a;
  a = b;
  b = temp;
}

void sapXepDanhSachConVat(vector<CONVAT> &danhSach) {
  int n = danhSach.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double thoigianvedich_1 = timThoiGianVeDich(danhSach[i]);
      double thoigianvedich_2 = timThoiGianVeDich(danhSach[j]);
      // if (thoigianvedich_1 <= 12 && thoigianvedich_2 <= 12)
      if (thoigianvedich_1 > thoigianvedich_2)
        hoanVi(danhSach[i], danhSach[j]);
    }
  }
}

int main() {
  ifstream FileIn("input.txt");
  while (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    return 0;
  }
  vector<CONVAT> danhSach;
  nhapDanhSachConVat(FileIn, danhSach);
  FileIn.close();


  // Kiem tra thoi gian ve dich
  // int n = danhSach.size();
  // for (int i = 0; i < n; i++) {
  //   cout << danhSach[i].maSo << " => " << timThoiGianVeDich(danhSach[i]) << endl;
  // }

  ofstream FileOut("output.txt");
  sapXepDanhSachConVat(danhSach);
  int n = danhSach.size();
  FileOut << " " << endl;
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (timThoiGianVeDich(danhSach[i]) <= 12) {
      FileOut << i + 1 << ". ";
      xuatConVat(FileOut, danhSach[i]);
      FileOut << endl;
      dem++;
    }
  }
  FileOut.seekp(0, FileOut.beg);
  FileOut << dem << endl;
  FileOut.close();

  system("pause");
  return 0;
}