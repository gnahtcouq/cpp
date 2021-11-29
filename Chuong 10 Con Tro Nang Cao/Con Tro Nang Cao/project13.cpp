#include <iostream>
using namespace std;

template <class ThangDepTrai>
void NhapMang(ThangDepTrai* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap vao a[" << i << "] = ";
    cin >> a[i];
  }
}

template <class ThangDepTrai>
void XuatMang(ThangDepTrai* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  int n = 5;
  float* a = new float[n];

  NhapMang<float>(a, n);
  XuatMang<float>(a, n);

  delete[] a;

  system("pause");
  return 0;
}