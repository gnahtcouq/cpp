#include <iostream>
#include <fstream>
using namespace std;

void xuatMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

void docFile(ifstream &FileIn, int*& a, int& n) {
  FileIn.open("taptin.dat", ios::in | ios::binary);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }

  FileIn.seekg(0, ios::end); // Cho con tro nhay den cuoi
  n = ((int)FileIn.tellg() + 1) / sizeof(int);
  FileIn.seekg(0, ios::beg); // Cho con tro ve dau lai

  a = new int[n];
  FileIn.read((char *)a, n * sizeof(int));

  FileIn.close();
}

int main() {
  ifstream FileIn;
  int* a, n;

  docFile(FileIn, a, n);
  xuatMang(a, n);

  delete[] a;

  system("pause");
  return 0;
}