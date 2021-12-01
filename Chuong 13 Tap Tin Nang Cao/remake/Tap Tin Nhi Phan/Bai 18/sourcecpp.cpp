#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void docFile(ifstream &FileIn, string &str) {
  FileIn.open("INPUT.txt", ios_base::in);
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }
  getline(FileIn, str);
  FileIn.close();
}

int main() {
  string str;
  ifstream FileIn;

  docFile(FileIn, str);
  cout << "\nChuoi doc duoc la: " << str;

  system("pause");
  return 0;
}