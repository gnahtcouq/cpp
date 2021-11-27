/* BÀI TẬP VỀ NHÀ
- Viết chương trình nhập vào mảng các số nguyên và hiện ra 1 Menu như sau:

----- Menu -----
1. Them 1 phan tu vao mang.
2. Xoa 1 phan tu khoi mang.
3. Xuat mang.
0. Ket thuc.

LƯU Ý: DÙNG CON TRỎ ĐỂ LÀM.
- Ở lựa chọn 1 sẽ cho phép người dùng nhập vào phần tử thêm & vị trí thêm

- Ở lựa chọn 2 sẽ cho phép người dùng nhập vào vị trí cần xóa.
*/

#include <iostream>
using namespace std;

void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void realloc(int*& a, int sizecu, int sizemoi);
void themMotPhanTu(int*& a, int& n, int phantuthem, int vitrithem);
void xoaMotPhanTu(int*& a, int& n, int vitrixoa);
void xuatMenu(int& choose);

int main() {
  int n, choose, phantuthem, vitrithem, vitrixoa;

  do {
    cout << "\nNhap vao so luong phan tu cua mang: ";
    cin >> n;
    if (n < 0)
      cout << "\nSo luong phai >= 0. Xin kiem tra lai";
  } while (n < 0);

  int* a = new int[n];
  nhapMang(a, n);
  xuatMenu(choose);
  do {
    if (choose == 1) {
      cout << "OP 1. Nhap phan tu them: ";
      cin >> phantuthem;
      do {
        cout << "OP 1. Nhap vi tri them: ";
        cin >> vitrithem;
        if (vitrithem < 0 || vitrithem > n)
          cout << "OP 1. Vi tri them khong hop le. Hay nhap lai";
      } while (vitrithem < 0 || vitrithem > n);
      themMotPhanTu(a, n, phantuthem, vitrithem);
      xuatMenu(choose);
    }
    if (choose == 2) {
      do {
        cout << "OP 2. Nhap vi tri xoa: ";
        cin >> vitrixoa;
        if (vitrixoa < 0 || vitrixoa > n)
          cout << "OP 2. Vi tri xoa khong hop le. Hay nhap lai";
      } while (vitrixoa < 0 || vitrixoa > n);
      xoaMotPhanTu(a, n, vitrixoa);
      xuatMenu(choose);
    }
    if (choose == 3) {
      cout << "OP 3. Xuat mang: ";
      xuatMang(a, n);
      xuatMenu(choose);
    }
  } while (choose != 0);


  delete[] a;
  cout << endl;
  return 0;
}

void nhapMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nNhap a[" << i << "] = ";
    cin >> a[i];
  }
}

void xuatMang(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

void realloc(int*& a, int sizecu, int sizemoi) {
  int* b = new int[sizecu];
  for (int i = 0; i < sizecu; i++)
    b[i] = a[i];
  delete[] a;
  a = new int[sizemoi];
  for (int i = 0; i < sizecu; i++)
    a[i] = b[i];
  delete[] b;
}

void themMotPhanTu(int*& a, int& n, int phantuthem, int vitrithem) {

  realloc(a, n, n + 1);
  for (int i = n - 1; i >= vitrithem; i--) {
    a[i + 1] = a[i];
  }
  a[vitrithem] = phantuthem;
  n++;
}

void xoaMotPhanTu(int*& a, int& n, int vitrixoa) {
  for (int i = vitrixoa; i < n - 1; i++) {
    a[i] = a[i + 1];
  }
  n--;
  realloc(a, n, n);
}

void xuatMenu(int& choose) {
  cout << endl;
  cout << "\n* --------------- MENU --------------- *";
  cout << "\n| 1. Them 1 phan tu vao mang           |";
  cout << "\n| 2. Xoa 1 phan tu khoi mang           |";
  cout << "\n| 3. Xuat mang                         |";
  cout << "\n| 0. Ket thuc                          |";
  cout << "\n* ------------------------------------ *";
  cout << endl;
  do {
    cout << "\nNhap lua chon cua ban: ";
    cin >> choose;
    if (choose != 1 && choose != 2 && choose != 3 && choose != 0)
      cout << "\nLua chon cua ban khong co trong menu. Hay nhap lai";
  } while (choose != 1 && choose != 2 && choose != 3 && choose != 0);
}