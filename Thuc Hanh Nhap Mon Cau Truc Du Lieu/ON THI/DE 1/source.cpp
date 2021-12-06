#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define MAX 100

struct CuaHang {
  char maCH[5];
  char tenCH[30];
  int soNha;
  char tenDuong[30];
  char phuong[30];
  char quan[10];
  char thanhPho[30];
};
typedef struct CuaHang CUAHANG;
struct DaySo {
  int soLuong;
  CuaHang data[MAX];
};
typedef struct DaySo DAYSO;

struct Node {
  CUAHANG data;
  Node* pNext;
};
typedef struct Node NODE;
struct List {
  NODE* pHead;
  NODE* pTail;
};
typedef struct List LIST;


void nhapCuaHang(CUAHANG& ch);
void xuatCuaHang(CUAHANG ch);
void nhapDanhSachCuaHang(DAYSO& ds);
void xuatDanhSachCuaHang(DAYSO ds);
int demSoLuongCuaHangChuaTen(DAYSO ds);

void khoiTao(LIST& l);
NODE* taoNode(CUAHANG data);
void themCuoi(LIST& l, NODE* p);
void nhap(LIST& l);
void xuat(LIST l);
void giaiPhong(LIST& l);
void them(LIST& l);

int main() {
  // CUAHANG ch;
  // DAYSO ds;
  // // nhapCuaHang(ch);
  // // xuatCuaHang(ch);
  // nhapDanhSachCuaHang(ds);
  // xuatDanhSachCuaHang(ds);

  // cout << "\nSo luong " << demSoLuongCuaHangChuaTen(ds);

  LIST l;
  nhap(l);
  xuat(l);
  cout << "\nNhap thong tin cua hang can them";
  them(l);
  cout << "\nDanh sach cac cua hang sau khi them" << endl;
  xuat(l);

  giaiPhong(l);

  return 0;
}

void nhapCuaHang(CUAHANG& ch) {
  cout << "\nNhap ma CH: ";
  cin >> ch.maCH;
  cout << "Nhap ten CH: ";
  cin.ignore();
  cin.getline(ch.tenCH, 30);
  cout << "Nhap so nha: ";
  cin >> ch.soNha;
  cout << "Nhap ten duong: ";
  cin.ignore();
  cin.getline(ch.tenDuong, 30);
  cout << "Nhap phuong: ";
  cin.getline(ch.phuong, 30);
  cout << "Nhap quan: ";
  cin.getline(ch.quan, 10);
  cout << "Nhap thanh pho: ";
  cin.getline(ch.thanhPho, 30);
  cout << endl;
}

void xuatCuaHang(CUAHANG ch) {
  cout << "\nMa CH: " << ch.maCH;
  cout << "\nTen CH: " << ch.tenCH;
  cout << "\nSo nha: " << ch.soNha;
  cout << "\nTen duong: " << ch.tenDuong;
  cout << "\nPhuong: " << ch.phuong;
  cout << "\nQuan: " << ch.quan;
  cout << "\nThanh pho: " << ch.thanhPho;
  cout << endl;
}

void nhapDanhSachCuaHang(DAYSO& ds) {
  cout << "\nNhap so luong CH: ";
  cin >> ds.soLuong;
  cout << "\nNhap thong tin tung CH: ";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n------- Thong Tin Cua Hang Thu " << i << " -------\n";
    nhapCuaHang(ds.data[i]);
  }
}

void xuatDanhSachCuaHang(DAYSO ds) {
  cout << "\nDanh sach cac CH: " << endl;
  for (int i = 0; i < ds.soLuong; i++)
    xuatCuaHang(ds.data[i]);
}

// Cau b
int demSoLuongCuaHangChuaTen(DAYSO ds) {
  char str[] = "Tong Hop";
  int dem = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (strstr(ds.data[i].tenCH, str))
      dem++;
  }
  return dem;
}

// Cau 2
void khoiTao(LIST& l) {
  l.pHead = l.pTail = NULL;
}

NODE* taoNode(CUAHANG data) {
  NODE* p = new NODE;
  if (p == NULL) {
    return NULL;
  }
  p->data = data;
  p->pNext = NULL;
  return p;
}

void themCuoi(LIST& l, NODE* p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  }
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void nhap(LIST& l) {
  khoiTao(l);
  int n;
  cout << "\nNhap so luong CH: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    CUAHANG data;
    nhapCuaHang(data);
    NODE* p = taoNode(data);
    themCuoi(l, p);
  }
}

void xuat(LIST l) {
  int dem = 1;
  for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
    cout << "\n------- Thong Tin Cua Hang Thu " << dem++ << " -------\n";
    xuatCuaHang(p->data);
  }
}

void giaiPhong(LIST& l) {
  NODE* p;
  while (l.pHead != NULL) {
    p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
  }
}