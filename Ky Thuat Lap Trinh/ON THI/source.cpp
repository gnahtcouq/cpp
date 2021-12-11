#include <iostream>
using namespace std;

#define KTM 100
struct Matrix {
  int data[KTM][KTM];
  int n;
};
void docMaTran(Matrix& a);
void xuatMaTran(Matrix a);
void inTamGiacDuoiBenTrai(Matrix a);
int timMax_TamGiacDuoiBenTrai(Matrix a);
int tinhTongDong(Matrix a, int x);
int soSanhTongDong(Matrix a, int x, int y);


#define MAX 100
struct MangSo {
  int n;
  double data[MAX];
};
bool kiemTraMangTang(MangSo a);

int main() {
  // Matrix a;
  // docMaTran(a);
  // xuatMaTran(a);

  // cout << "\nTam giac duoi ben trai" << endl;
  // inTamGiacDuoiBenTrai(a);
  // cout << "\nMax = " << timMax_TamGiacDuoiBenTrai(a);

  // int x, y;
  // cout << "\nNhap dong x: ";
  // cin >> x;
  // cout << "\nNhap dong y: ";
  // cin >> y;
  // int ketqua = soSanhTongDong(a, x, y);
  // if (ketqua == 1)
  //   cout << "\nTong dong x > Tong dong y";
  // else
  //   cout << "\nTong dong x < Tong dong y";
  // if (ketqua == 0)
  //   cout << "\nTong dong x = Tong dong y";

  // Tong dong 3 = 123
  // Tong dong 4 = 29

  MangSo a;
  a.n = 5;
  a.data[0] = 4;
  a.data[1] = 2;
  a.data[2] = 1;
  a.data[3] = 5;
  a.data[4] = 3;
  int ketqua = kiemTraMangTang(a);
  if (ketqua == false)
    cout << "\nMang khong tang";
  else
    cout << "\nMang tang dan";

  system("pause");
  return 0;
}

void docMaTran(Matrix& a) {
  FILE* f;
  f = fopen("a.txt", "r");
  if (f == NULL) {
    cout << "Loi mo file";
    exit(1);
  }
  fscanf(f, "%d", &a.n);
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      fscanf(f, "%d", &a.data[i][j]);
  fclose(f);
}
void xuatMaTran(Matrix a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      cout << a.data[i][j] << "\t";
    cout << endl;
  }
}

void inTamGiacDuoiBenTrai(Matrix a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (i >= j)
        cout << a.data[i][j] << "\t";
    cout << endl;
  }
}

int timMax_TamGiacDuoiBenTrai(Matrix a) {
  int max = a.data[0][0];
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (i >= j)
        if (a.data[i][j] > max)
          max = a.data[i][j];
  }
  return max;
}

int tinhTongDong(Matrix a, int x) {
  int tong = 0;
  for (int j = 0; j < a.n; j++) {
    tong += a.data[x][j];
  }
  return tong;
}

int soSanhTongDong(Matrix a, int x, int y) {
  if (tinhTongDong(a, x) > tinhTongDong(a, y))
    return 1;
  else
    return -1;
  return 0;
}

bool kiemTraMangTang(MangSo a) {
  for (int i = 0; i < a.n - 1; i++) {
    if (a.data[i] > a.data[i + 1])
      return false;
  }
  return true;
}