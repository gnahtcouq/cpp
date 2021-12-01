#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ghiFile(ofstream &FileOut, string str) {
  FileOut.open("OUTPUT.txt", ios_base::out);
  if (FileOut) {
    FileOut << "Chuoi ban nhap vao la: " << str;
  }
  FileOut.close();
}

int main() {
  string str;
  cout << "\nMoi ban nhap vao chuoi: ";
  getline(cin, str);


  ofstream FileOut;
  ghiFile(FileOut, str);


  system("pause");
  return 0;
}