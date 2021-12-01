#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// 1 2 1 -> nghiem kep
// 3 8 2 -> 2 nghiem phan biet


// Doc du lieu tu file vao chuong trinh
void nhapFile(ifstream &FileIn, int& a, int& b, int& c) {
  FileIn.open("INPUT.txt", ios_base::in);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0); // Ket thuc toan bo chuong trinh
  }
  FileIn >> a >> b >> c;
  FileIn.close();
}

// Xu ly va ghi ket qua ra file
void ghiFile(ofstream &FileOut, int a, int b, int c) {
  FileOut.open("OUTPUT.txt", ios_base::out);
  if (FileOut) {
    // Xu ly giai phuong trinh
    if (a == 0) { // bx + c = 0
      if (b == 0) {
        if (c == 0) {
          FileOut << "Phuong trinh co vo so nghiem";
        }
        else {
          FileOut << "Phuong trinh vo nghiem";
        }
      }
      else {
        float x = (float)-c / b;
        FileOut << "Phuong trinh co 1 nghiem duy nhat x = " << x;
      }
    }
    else {
      float denTa = b * b - 4 * a * c;
      if (denTa < 0) {
        FileOut << "Phuong trinh vo nghiem";
      }
      else if (denTa == 0) {
        float x = (float)-b / (2 * a);
        FileOut << "Phuong trinh co nghiem kep x1 = x2 = " << x;
      }
      else { // denTa > 0
        float x1 = (-b + sqrt(denTa)) / (2 * a);
        float x2 = (-b - sqrt(denTa)) / (2 * a);
        FileOut << "Phuong trinh co 2 nghiem phan biet:\nx1 = " << x1 << "\nx2 = " << x2;
      }
    }
  }
  FileOut.close();
}

int main() {
  ifstream FileIn;
  ofstream FileOut;
  int a, b, c;
  nhapFile(FileIn, a, b, c);
  ghiFile(FileOut, a, b, c);

  system("pause");
  return 0;
}