#include <iostream>
#include <string.h>
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
    ketqua = idx / 2 - 1;
  else
    ketqua = idx / 2;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}

void taoCay(char*& a) {
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

// 1: left->right, Khac 1: right->left
void duyetTheoChieuRong(char* a, int thutu = 1) {
  queue<int> q; // chua index cua cac Node theo thu tu duyet
  // Phai co ton tai Node goc thi moi dua Node goc do vao hang doi
  if (strlen(a) >= 1)
    q.push(0); // 0 chinh la index cua Node goc

  while (!q.empty()) { // Lap lien tuc khi hang doi con phan tu
    int i = q.front();
    if (a[i] != '?') // Khong xet nhung Node gia
      cout << a[i] << " "; // Lay ra index cua Node dau hang doi
    q.pop(); // Bo Node ra khoi hang doi

    if (thutu == 1) {
      if (2 * i + 1 >= 0 && 2 * i + 1 < strlen(a)) // Co ton tai Node con trai cua p
        q.push(2 * i + 1); // Dua con trai vao hang doi
      if (2 * i + 2 >= 0 && 2 * i + 2 < strlen(a)) // Co on tai Node con phai cua p
        q.push(2 * i + 2); // Dua con phai vao hang doi
    }
    else {
      if (2 * i + 2 >= 0 && 2 * i + 2 < strlen(a)) // Co ton tai Node con trai cua p
        q.push(2 * i + 2); // Dua con trai vao hang doi
      if (2 * i + 1 >= 0 && 2 * i + 12 < strlen(a)) // Co on tai Node con phai cua p
        q.push(2 * i + 1); // Dua con phai vao hang doi
    }
  }
}

// NODE - LEFT - RIGHT
 // 1: left->right, Khac 1: right->left
void phepDuyetTruoc(char* a, int idx, int thutu = 1) {
  if (idx >= 0 && idx < strlen(a)) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    if (a[idx] != '?')
      cout << a[idx] << " "; // Duyet in ra N
    if (thutu == 1) {
      phepDuyetTruoc(a, 2 * idx + 1, thutu); // LEFT
      phepDuyetTruoc(a, 2 * idx + 2, thutu); // RIGHT
    }
    else {
      phepDuyetTruoc(a, 2 * idx + 2, thutu); // RIGHT
      phepDuyetTruoc(a, 2 * idx + 1, thutu); // LEFT
    }
  }
}

// LEFT - NODE - RIGHT
 // 1: left->right, Khac 1: right->left
void phepDuyetGiua(char* a, int idx, int thutu = 1) {
  if (idx >= 0 && idx < strlen(a)) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    if (thutu == 1) {
      phepDuyetGiua(a, 2 * idx + 1, thutu); // LEFT
      if (a[idx] != '?')
        cout << a[idx] << " "; // Duyet in ra N
      phepDuyetGiua(a, 2 * idx + 2, thutu); // RIGHT
    }
    else {
      phepDuyetGiua(a, 2 * idx + 2, thutu); // RIGHT
      if (a[idx] != '?')
        cout << a[idx] << " "; // Duyet in ra N
      phepDuyetGiua(a, 2 * idx + 1, thutu); // LEFT
    }
  }
}

// // LEFT - RIGHT - NODE
//  // 1: left->right, Khac 1: right->left
void phepDuyetSau(char* a, int idx, int thutu = 1) {
  if (idx >= 0 && idx < strlen(a)) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    if (thutu == 1) {
      phepDuyetSau(a, 2 * idx + 1, thutu); // LEFT
      phepDuyetSau(a, 2 * idx + 2, thutu); // RIGHT
      if (a[idx] != '?')
        cout << a[idx] << " "; // Duyet in ra N
    }
    else {
      phepDuyetSau(a, 2 * idx + 2, thutu); // RIGHT
      phepDuyetSau(a, 2 * idx + 1, thutu); // LEFT
      if (a[idx] != '?')
        cout << a[idx] << " "; // Duyet in ra N
    }
  }
}

void demTongCacNodeTrenCay(char* a, int idx, int& dem) {
  if (idx >= 0 && idx < strlen(a)) {
    if (a[idx] != '?')
      dem++; // Cu den 1 Node la tang bien dem len 1
    demTongCacNodeTrenCay(a, 2 * idx + 1, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demTongCacNodeTrenCay(a, 2 * idx + 2, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

int main() {
  /* char *a;
  taoCay(a);

  cout << a; */

  char* a = new char[16];
  strcpy(a, "ABCDEFGHI?JK??L");

  cout << "\nDuyet theo chieu rong: ";
  duyetTheoChieuRong(a);

  cout << "\nPhep duyet truoc (NLR) left->right: ";
  phepDuyetTruoc(a, 0);
  cout << "\nPhep duyet truoc (NLR) right->left: ";
  phepDuyetTruoc(a, 0, 2);
  cout << endl;
  cout << "\nPhep duyet giua (LNR) left->right: ";
  phepDuyetGiua(a, 0);
  cout << "\nPhep duyet giua (LNR) right->left: ";
  phepDuyetGiua(a, 0, 2);
  cout << endl;
  cout << "\nPhep duyet sau (LRN) left->right: ";
  phepDuyetSau(a, 0);
  cout << "\nPhep duyet sau (LRN) right->left: ";
  phepDuyetSau(a, 0, 2);

  int soLuongCacNode = 0;
  demTongCacNodeTrenCay(a, 0, soLuongCacNode);
  cout << "\nSo luong cac Node tren cay la: " << soLuongCacNode;

  delete(a);

  system("pause");
  return 0;
}