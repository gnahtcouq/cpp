#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int demSoTu(ifstream &FileIn) {
  int dem = 0;
  FileIn.open("INPUT.txt", ios_base::in);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }

  while (!FileIn.eof()) {
    string str;
    FileIn >> str;
    dem++;
    cout << "\nTu thu " << dem << " la: " << str;
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
  int soLuong = demSoTu(FileIn);
  ghiFile(FileOut, soLuong);

  system("pause");
  return 0;
}