#include <iostream>
#include <fstream>
using namespace std;

void docFile(ifstream &FileIn, int *&a, int &n) {
  FileIn.open("INPUT.txt", ios_base::in);
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }
  FileIn >> n;
  a = (int *)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++){
    FileIn >> a[i];
  }
  FileIn.close();
}

void sapXep(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        swap(a[i], a[j]);
    }
  }
}

void ghiFile(ofstream &FileOut, int *a, int n) {
  FileOut.open("OUTPUT.txt", ios_base::out);
  for(int i = 0; i < n; i++) {
    FileOut << a[i] << " ";
  }
  FileOut.close();
}

int main() {
  ifstream FileIn;
  ofstream FileOut;
  int *a, n;
  docFile(FileIn, a, n);
  sapXep(a, n);
  ghiFile(FileOut, a, n);

  delete[] a;

  system("pause");
  return 0;
}