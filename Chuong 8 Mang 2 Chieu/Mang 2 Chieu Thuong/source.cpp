#include <iostream>
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

  system("pause");
  return 0;
}