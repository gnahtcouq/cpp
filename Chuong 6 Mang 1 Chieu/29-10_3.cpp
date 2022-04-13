#include <iostream>
using namespace std;
#define MAX 100

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);

int main() {
  int a[MAX]; // Khai bao mang co toi da 100 phan tu
  int n;
  do {
    cout << "\nNhap vao so luong phan tu cua mang: ";
    cin >> n;
    if (n<0 || n>MAX)
      cout << "\nSo luong khong hop le. Xin kiem tra lai";
  } while (n<0 || n>MAX);

  nhapMang(a, n);
  xuatMang(a, n);

  // int b[MAX];
  // int m;
  // nhapMang(b, m);

  return 0;
}

void nhapMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap vao a[" << i << "]= ";
    cin >> a[i];
  }
}

void xuatMang(int a[], int n) {
  cout << "\nMang la: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}