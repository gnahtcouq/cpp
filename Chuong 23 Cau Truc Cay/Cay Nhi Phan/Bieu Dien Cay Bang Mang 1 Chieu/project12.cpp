#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

// Tra ve vi tri con trai cua Node co index la idx
int left(int idx) {
  int ketqua = 2 * idx + 1;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}


// Tra ve vi tri con phai cua Node co index la idx
int right(int idx) {
  int ketqua = 2 * idx + 2;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}

int timCha(int idx) {
  int ketqua;
  if (idx % 2 == 0)
    ketqua = idx/2 -1;
  else
    ketqua = idx/2;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}

void taoCay(char *&a) {
  int k;
  cout << "\nNhap vao do cao cua cay k = ";
  cin >> k;

  int soNode = pow(2.0, k);
  a = new char[soNode];

  for (int i = 0; i < soNode - 1; ++i) {
    a[i] = '?'; // Khoi tao ban dau tat ca la ?. Sau do neu Node nao co ton tai thi cap nhat lai index o vi tri tuong ung trong mang 1 chieu
  }
  a[soNode - 1] = '\0'; // Ket thuc chuoi

  queue<int> q; // Chua index cua cac Node con
  char x;
  fflush(stdin);
  cout << "\nNhap vao node goc: ";
  cin >> x;
  q.push(0);
  a[0] = x;

  while (!q.empty()) {
    int idx = q.front();
    q.pop();
    int soCon;
    do {
      cout << "\nNhap vao so luong con cua Node " << a[idx] << " (0 hay 1 hay 2): ";
      cin >> soCon;
      if (soCon < 0 || soCon > 2)
        cout << "\nSo luong con chi co the la 0 hay 1 hay 2. Xin kiem tra va nhap lai";
    } while (soCon < 0 || soCon > 2);

    if (soCon == 1) {
      char loaiCon;
      do {
        fflush(stdin);
        cout << "\nBan muon con cua Node " << a[idx] << " la con trai hay con phai?. Neu la con trai nhap L - Neu la con phai nhap R: ";
        cin >> loaiCon;
        if (loaiCon != 'L' && loaiCon != 'R' && loaiCon != 'l' && loaiCon != 'r')
          cout << "\nNeu la con trai thi nhap L - Neu la con phai thi nhap R. Khong duoc nhap khac ky tu quy dinh";
      } while (loaiCon != 'L' && loaiCon != 'R' && loaiCon != 'l' && loaiCon != 'r');

      char x;
      if (loaiCon == 'L' || loaiCon == 'l') { // La con trai
        fflush(stdin);
        cout << "\nNhap vao node con trai cua Node " << a[idx] << ": ";
        cin >> x;
        a[2 * idx + 1] = x;
        q.push(2 * idx + 1);
      }
      else { // La con phai
        fflush(stdin);
        cout << "\nNhap vao node con phai cua Node " << a[idx] << ": ";
        cin >> x;
        a[2 * idx + 2] = x;
        q.push(2 * idx + 2);
      }
    }
    else if (soCon == 2) {
      char l, r;
      fflush(stdin);
      cout << "\nNhap vao node con trai cua Node " << a[idx] << ": ";
      cin >> l;
      a[2 * idx + 1] = l;
      q.push(2 * idx + 1);

      fflush(stdin);
      cout << "\nNhap vao node con phai cua Node " << a[idx] << ": ";
      cin >> r;
      a[2 * idx + 2] = r;
      q.push(2 * idx + 2);
    }
  }
}

int main() {
  char *a;
  taoCay(a);

  cout << a;


  system("pause");
  return 0;
}