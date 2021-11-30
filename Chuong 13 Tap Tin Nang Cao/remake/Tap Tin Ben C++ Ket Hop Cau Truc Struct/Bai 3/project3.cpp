/* Đề bài 3: Đọc 1 dãy số nguyên từ file INPUT.TXT vào chương trình, biết cấu trúc file như sau:
- Một dòng duy nhất chứa các số đó, mỗi số cách nhau bởi 1 khoảng trắng.

Đọc dãy số vào chương trình, tìm ra Max và ghi vào file OUTPUT.TXT */

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