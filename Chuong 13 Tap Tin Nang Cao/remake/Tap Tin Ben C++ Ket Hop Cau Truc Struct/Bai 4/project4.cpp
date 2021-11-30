/* Đề bài 4: Đọc 1 dãy số nguyên từ file INPUT.TXT vào chương trình, biết cấu trúc file như sau:
- Một dòng duy nhất chứa các số đó, mỗi số cách nhau bởi 1 ký tự '/' */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream FileIn("INPUT.txt");
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    exit(0);
  }
  vector<int> arr;
  while (!FileIn.eof()) { // Vong lap de duyet het file
    int x;
    FileIn >> x;

    // Cach 1: Dung bien phu de luu ky tu vao
    // char y;
    // FileIn >> y;

    // Cach 2: Dich chuyen con tro chi vi tren file

    /*
    seekg(x, y);
    x la so byte biet can dich chuyen
    y la vi tri bat dau dich, co 3 thong so:
      + y = 0: dau file
      + y = 1: hien tai
      + y = 2: cuoi file
    */

    // Kiem tra neu chua den cuoi file thi moi duoc dich
    if(!FileIn.eof())
      FileIn.seekg(1, FileIn.cur); // Dich 1 byte tu vi tri hien tai

    arr.push_back(x); 
  }
  FileIn.close();


  ofstream FileOut("OUTPUT.txt");
  int max = arr[0];
  // arr.size() -> lay ra so luong phan tu trong arr
  for (int i = 1; i <= arr.size(); i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  FileOut << max;
  FileOut.close();

  cout << endl;
  system("pause");
  return 0;
}