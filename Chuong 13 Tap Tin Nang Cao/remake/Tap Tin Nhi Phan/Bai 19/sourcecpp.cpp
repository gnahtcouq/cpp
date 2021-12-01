#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int demSoKyTuChuCai(ifstream &FileIn) {
  int dem = 0;
  FileIn.open("INPUT.txt", ios_base::in);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }
  char c;
  while (!FileIn.eof()) { // Doc vao 1 ky tu tu tap tin va luu vao bien c
    FileIn.get(c);
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
      dem++;
  }
  FileIn.close();
  return dem;
}

void ghiFile(ofstream &FileOut, int soLuong) {
  FileOut.open("OUTPUT.txt", ios_base::out);
  if (FileOut) {
    FileOut << "So luong ky tu la chu cai la: " << soLuong;
  }
  FileOut.close();
}

int main() {
  ifstream FileIn;
  ofstream FileOut;
  int soLuong = demSoKyTuChuCai(FileIn);
  ghiFile(FileOut, soLuong);

  system("pause");
  return 0;
}