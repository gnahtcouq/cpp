#include <iostream>
using namespace std;

struct CAYBUT {
  int maCB; // ma so cua cay but
  char tenCB[30]; // ten cua cay but
  int soLuong; // so luong cua cay but trong kho
  float donGia; // don gia cua cay but
  char hangSX[30]; // hang san xuat
};

struct NODECAYBUT {
  CAYBUT data;
  NODECAYBUT *link;
};
typedef NODECAYBUT* Nodeptr;

int main() {
  system("pause");
  return 0;
}