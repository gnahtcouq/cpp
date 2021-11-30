/* Đề bài 1: Đọc 2 số nguyên từ file INPUT.TXT vào chương trình, mỗi số cách nhau bởi 1 khoảng trắng. Tính tổng 2 số nguyên đó. Kết quả lưu vào file OUTPUT.TXT */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream FileIn("INPUT.txt");
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }

  int a, b;
  FileIn >> a >> b;
  FileIn.close();

  ofstream FileOut("OUTPUT.txt");
  int tong = a + b;
  FileOut << tong;
  FileOut.close();

  cout << endl;
  system("pause");
  return 0;
}