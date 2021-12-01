#include <iostream>
#include <fstream>
using namespace std;

void nhapMang(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap vao a[" << i << "] = ";
    cin >> a[i];
  }
}

void ghiFile(ofstream &FileOut, int *a, int n) {
  FileOut.open("taptin.dat", ios::out | ios::binary);
  if(FileOut) {
    FileOut.write((char *)a, n * sizeof(int));
  }
  FileOut.close();
}

int main() {
  ofstream FileOut;
  int n = 5;
  int *a = new int[n];

  nhapMang(a, n);
  ghiFile(FileOut, a, n);

  delete[] a;

  system("pause");
  return 0;
}