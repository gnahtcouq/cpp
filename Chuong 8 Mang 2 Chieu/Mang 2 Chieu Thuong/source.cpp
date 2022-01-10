#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

// Phai biet truoc co bao nhieu cot
void nhapMang(int a[][MAX], int dong, int cot) {
  for (int i = 0; i < dong; i++) {
    for (int j = 0; j < cot; j++) {
      cout << "\nNhap vao a[" << i << "][" << j << "] = "; 
      cin >> a[i][j];
    }
  }
}

void xuatMang(int a[][MAX], int dong, int cot) {
  for (int i = 0; i < dong; i++) {
    for (int j = 0; j < cot; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

int tinhTong(int a[][MAX], int dong, int cot) {
  int tong = 0;
  for (int i = 0; i < dong; i++)
    for (int j = 0; j < cot; j++)
      tong += a[i][j];
  return tong;
}

int demSoLuongSoChan(int a[][MAX], int dong, int cot) {
  int dem = 0;
  for (int i = 0; i < dong; i++)
    for (int j = 0; j < cot; j++)
      if (a[i][j] % 2 == 0)
        dem++;
  return dem;
}

int kiemTraChinhPhuong(int x) {
  // if (sqrt((double)x) == (int)sqrt((double)x))
  //   return 1; // la so CP
  // return 0;
  return sqrt((double)x) == (int)sqrt((double)x);
}

void lietKeChinhPhuong(int a[][MAX], int dong, int cot) {
  cout << "\nCac so chinh phuong la: ";
  for (int i = 0; i < dong; i++)
    for (int j = 0; j < cot; j++)
      if (kiemTraChinhPhuong(a[i][j]) == 1)
        cout << a[i][j] << " ";
}

int main() {
  // // Khai bao truc tiep mang
  // int a[5] = {1, 2, 3, 4, 5};
  // int b[2][3] = {{1, 2, 3}, {4, 5, 6}};

  // for (int i = 0; i < 2; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << " " << b[i][j];
  //   }
  //   cout << endl;
  // }

  int a[MAX][MAX];
  int dong, cot;

  do {
    cout << "\nNhap vao so dong = ";
    cin >> dong;
    if (dong < 1 || dong > MAX)
      cout << "\nSo dong khong hop le. Xin kiem tra lai";
  } while (dong < 1 || dong > MAX);

  do {
    cout << "\nNhap vao so cot = ";
    cin >> cot;
    if (cot < 1 || cot > MAX)
      cout << "\nSo cot khong hop le. Xin kiem tra lai";
  } while (cot < 1 || cot > MAX);


  nhapMang(a, dong, cot);
  xuatMang(a, dong, cot);


  int tong = tinhTong(a, dong, cot);
  cout << "\nTong = " << tong;

  int demChan = demSoLuongSoChan(a, dong, cot);
  cout << "\nSo luong cac so chan = " << demChan;


  lietKeChinhPhuong(a, dong, cot);

  system("pause");
  return 0;
}