#include <iostream>
#include <fstream>
using namespace std;

void nhapFile(int& a, int& b, int& c) {
  cout << "\nNhap a = ";
  cin >> a;
  cout << "\nNhap b = ";
  cin >> b;
  cout << "\nNhap c = ";
  cin >> c;
}
void ghiFile(ofstream &FileOut, int a, int b, int c) {
  FileOut.open("OUTPUT.txt", ios_base::out); // ios::out
  if (FileOut){
    FileOut << "\na = " << a;
    FileOut << "\nb = " << b;
    FileOut << "\nc = " << c;
  }
  FileOut.close();
}

int main() {
  ofstream FileOut;
  int a, b, c;
  nhapFile(a, b, c);
  ghiFile(FileOut, a, b, c);

  system("pause");
  return 0;
}