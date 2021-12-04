#include <iostream>
#include <cstdio> // Su dung gets();
using namespace std;

int main() {
  float diem;
  cout << "\nNhap vao diem cua ban: ";
  cin >> diem;

  // fflush(stdin); // Xoa trong bo nho dem
  cin.ignore();

  // Luu y o buoc nhap chuoi thi truoc tien phai xoa het bo nho dem di = fflush(stdin); hoac cin.ignore();

  char ten[30];
  cout << "\nNhap vao ten cua ban: ";
  gets(ten);

  cout << "\nChao " << ten << ", ban duoc " << diem << " diem";

  cout << endl;
  return 0;
}