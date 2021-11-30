/* 
Tran Van Quoc Thang - 29/10/2002 - 7.5 - 8.7 - 9
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  // FILE *FileIn;
  // FileIn = fopen("VIDU.txt", "r");

  // ifstream FileIn;
  // FileIn.open("INPUT.txt", ios_base::in);

  ifstream FileIn("INPUT.txt");

  if(!FileIn) {
    cout << "\nKhong tim thay tap tin. Hay kiem tra lai";
    return 0;
  }

  // Xu ly
  string ten;
  int ngay, thang, nam;
  float toan, ly, hoa;

  // Doc toi ky tu '-' dung lai
  getline(FileIn, ten, '-');

  // Xoa khoang trang cuoi cung
  ten.erase(ten.begin() + ten.length() - 1);


  FileIn >> ngay;
  FileIn.seekg(1, FileIn.cur); // Bo dau '/'

  FileIn >> thang;
  FileIn.seekg(1, FileIn.cur); // Bo dau '/'

  FileIn >> nam;
  FileIn.seekg(1, FileIn.cur); // Bo dau '/'

  FileIn.seekg(2, FileIn.cur);
  FileIn >> toan;

  FileIn.seekg(2, FileIn.cur);
  FileIn >> ly;

  FileIn.seekg(2, FileIn.cur);
  FileIn >> hoa;

  FileIn.close(); // Dong tap tin 

  cout << "\nTen: " << ten;
  cout << "\nSinh ngay " << ngay << " thang " << thang << " nam " << nam;
  cout << "\nToan = " << toan;
  cout << "\nLy = " << ly;
  cout << "\nHoa = " << hoa;

  system("pause");
  return 0;
}