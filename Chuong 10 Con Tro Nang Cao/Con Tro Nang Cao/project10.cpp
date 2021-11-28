#include <iostream>
#include <stdlib.h>
using namespace std;

void nhapMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap a[" << i << "] = ";
    cin >> *(a + i);
  }
}

void xuatMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << *(a + i) << " ";
  }
}

void hoanVi(int& a, int& b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

// Trả về true nếu như a > b
bool lonHon(int a, int b) {
  return a > b;
}

// Trả về true nếu như a < b
bool nhoHon(int a, int b) {
  return a < b;
}

// Sắp xếp tăng hoặc giảm.
void sapXep(int* a, int n, bool (*soSanh)(int, int)) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (soSanh(a[i], a[j]) == true) {
        hoanVi(a[i], a[j]);
      }
    }
  }
}

// Min or Max
int timPhanTuThoaYeuCau(int* a, int n, bool (*soSanh)(int, int)) {
  int x = a[0]; // Gán x là phần tử đầu tiên của mảng.

  for (int i = 1; i < n; i++) {
    if (soSanh(a[i], x) == true) {
      x = a[i];
    }
  }
  return x;
}

int main() {
  int n = 5;

  int* a = (int*)malloc(n * sizeof(int));

  nhapMang(a, n);
  xuatMang(a, n);

  cout << "\nSap xep mang tang dan: ";
  sapXep(a, n, lonHon);
  xuatMang(a, n);

  cout << "\nSap xep mang giam dan: ";
  sapXep(a, n, nhoHon);
  xuatMang(a, n);

  int max = timPhanTuThoaYeuCau(a, n, lonHon);
  cout << "\nMax = " << max;

  int min = timPhanTuThoaYeuCau(a, n, nhoHon);
  cout << "\nMin = " << min;

  free(a);
  cout << endl;
  return 0;
}
