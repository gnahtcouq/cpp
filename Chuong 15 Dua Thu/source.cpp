#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define SUTU_THOIGIANBATDAU 9
#define THO_THOIGIANBATDAU 8
#define RUA_THOIGIANBATDAU 7

#define SUTU_QUANGDUONGCHAY 210
#define THO_QUANGDUONGCHAY 210
#define RUA_QUANGDUONGCHAY 135

struct ConVat {
  string m_Code;
  int m_Speed, m_Equiment;
};
typedef struct ConVat CONVAT;

void nhapConVat(ifstream& FileIn, CONVAT& cv) {
  FileIn >> cv.m_Code;
  FileIn >> cv.m_Speed;
  FileIn >> cv.m_Equiment;
}

void xuatConVat(ofstream& FileOut, CONVAT cv) {
  FileOut << cv.m_Code << " ";
  FileOut << cv.m_Speed << " ";
  FileOut << cv.m_Equiment << " ";
}

void nhapDanhSach(ifstream& FileIn, vector<CONVAT>& danhSach) {
  int n;
  FileIn >> n;
  for (int i = 0; i < n; i++) {
    CONVAT cv;
    nhapConVat(FileIn, cv);

    danhSach.push_back(cv);
  }
}

void xuatDanhSach(ofstream& FileOut, vector<CONVAT> danhSach) {
  int n = danhSach.size();
  for (int i = 0; i < n; i++) {
    xuatConVat(FileOut, danhSach[i]);
    FileOut << endl;
  }
}

int timVanTocThucSu(CONVAT cv) {
  if (cv.m_Equiment == 0)
    return cv.m_Speed;
  else {
    if (cv.m_Code[0] == 'L')
      return cv.m_Speed * 2;
    else if (cv.m_Code[0] == 'R')
      return cv.m_Speed + 30;
    else if (cv.m_Code[0] == 'T')
      return cv.m_Speed * 5;
  }
}

double timThoiGianDiHetQuangDuong(CONVAT cv) {
  int vantocthucsu = timVanTocThucSu(cv);
  if (cv.m_Code[0] == 'L') {
    return (double)SUTU_QUANGDUONGCHAY / vantocthucsu;
  }
  else if (cv.m_Code[0] == 'R') {
    return (double)THO_QUANGDUONGCHAY / vantocthucsu;
  }
  else if (cv.m_Code[0] == 'T') {
    return (double)RUA_QUANGDUONGCHAY / vantocthucsu;
  }
}

double timThoiGianVeDich(CONVAT cv) {
  double thoigianchay = timThoiGianDiHetQuangDuong(cv);
  if (cv.m_Code[0] == 'L') {
    return SUTU_THOIGIANBATDAU + thoigianchay;
  }
  else if (cv.m_Code[0] == 'R') {
    return THO_THOIGIANBATDAU + thoigianchay;
  }
  else if (cv.m_Code[0] == 'T') {
    return RUA_THOIGIANBATDAU + thoigianchay;
  }
}

void hoanVi(CONVAT& a, CONVAT& b) {
  CONVAT temp = a;
  a = b;
  b = temp;
}

void sapXepDanhSach(vector<CONVAT>& danhSach) {
  int n = danhSach.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double thoigianvedich_1 = timThoiGianVeDich(danhSach[i]);
      double thoigianvedich_2 = timThoiGianVeDich(danhSach[j]);
      // if(thoigianvedich_1 <= 12 && thoigianvedich_2 <= 12)
      if (thoigianvedich_1 > thoigianvedich_2)
        hoanVi(danhSach[i], danhSach[j]);
    }
  }
}

int main() {
  ifstream FileIn("input.txt");
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    return 0;
  }
  // CONVAT cv;
  vector<CONVAT> danhSach;
  nhapDanhSach(FileIn, danhSach);
  // nhapConVat(FileIn, cv);
  FileIn.close();

  ofstream FileOut("output.txt");
  sapXepDanhSach(danhSach);
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
  FileOut.seekp(0, FileOut.beg); // dich con tro chi ve ve dau
  FileOut << dem << endl;
  // xuatConVat(FileOut, cv);
  // xuatDanhSach(FileOut, danhSach);
  FileOut.close();

  system("pause");
  return 0;
}