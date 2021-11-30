/* Đề bài 2: Đọc 1 dãy số nguyên từ file INPUT.TXT vào chương trình, biết cấu trúc file như sau:
- Dòng đầu tiên chứa số lượng các số
- Dòng tiếp theo chứa các số đó, mỗi số cách nhau bởi 1 khoảng trắng.

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
  /*
  vector co 2 co che
  Co che 1: Neu biet truoc so luong phan tu se cap phat thi dung resize(<so luong>)

  Co che 2: Neu khong biet truoc so luong phan tu se cap phat thi dung push_back(<phan tu>)

  Loi khuyen ne: Dung cho che 2 nhe
  */
  int soluong;
  FileIn >> soluong;
  for (int i = 1; i <= soluong; i++) {
    int x; // Khoi tao 1 doi tuong x
    FileIn >> x; // Doc du lieu tu file vao x

    arr.push_back(x); // Dua x vao trong vector
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