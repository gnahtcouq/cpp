#include <iostream>
using namespace std;

void NhapMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap a[" << i << "] = ";
    cin >> a[i];
  }
}

void XuatMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  int n;

  do {
    cout << "\nNhap vao so luong phan tu cua mang: ";
    cin >> n;

    if (n < 0)
      cout << "\nSo luong phai >= 0. Xin kiem tra lai !";
  } while (n < 0);

  int* a = new int[n]; // Cấp phát bộ nhớ cần sử dụng.

  NhapMang(a, n);
  XuatMang(a, n);

  delete[] a; // Giải phóng bộ nhớ.

  cout << endl;
  return 0;
}