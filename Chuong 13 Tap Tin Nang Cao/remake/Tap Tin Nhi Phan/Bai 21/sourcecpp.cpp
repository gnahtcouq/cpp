#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int demSoLanXuatHien(ifstream &FileIn, string &str) {
  int dem = 0;
  FileIn.open("INPUT.txt", ios_base::in);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }

  while (!FileIn.eof()) {
    string strFile;
    FileIn >> strFile;
    if (strFile == str)
      dem++;
  }
  FileIn.close();
  return dem;
}

void ghiFile(ofstream &FileOut, int soLuong) {
  FileOut.open("OUTPUT.txt", ios_base::out);
  if (FileOut) {
    FileOut << "So lan lap lai la: " << soLuong;
  }
  FileOut.close();
}

int main() {
  ifstream FileIn;
  ofstream FileOut;

  string str;
  cout << "\nBan muon dem so lan lap lai cua tu nao: ";
  getline(cin, str);

  int soLuong = demSoLanXuatHien(FileIn, str);
  ghiFile(FileOut, soLuong);

  system("pause");
  return 0;
}