/*

Bài 6: Cũng giống như bài 5 nhưng cấu trúc file INPUT.TXT sẽ không có dòng đầu chứa số lượng mà chỉ có dãy số thôi.

vd:
INPUT.TXT
2 1 4 5 3

OUTPUT.TXT
1 2 3 4 5

// vòng lặp duyệt từ đầu tới cuối file.
while(!feof(FileIn))

vector 
là 1 lớp thuộc thư viện STL
=> Chỉ có ở C++

vector<int> a;

Có 2 cách sử dụng
Cách 1:
a.resize(n); // cấp phát n phần tử

a[0] = 1;
a[1] = 2;
...
a[n - 1] = n;

Cách 2:
a.push_back(1);
a.push_back(2);
a.push_back(3);
a.push_back(4);
a.push_back(5);

=> tự động thêm các số vào trong mảng và size tự động tăng.


Trang web tham khảo vector và 1 số kiểu khác: http://www.cplusplus.com/reference/vector/vector

*/

#include <iostream>
#include <fstream> // thu vien ho tro file cua c++
#include <vector>
#include <stdlib.h>
using namespace std;

void sapXep(vector<int> &a, char phanloai) {
  int n = a.size();
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      if(phanloai == 't')
        if(a[i] > a[j])
          swap(a[i], a[j]);
      if(phanloai == 'g')
        if(a[i] < a[j])
          swap(a[i], a[j]);
    }
  }
}

void docFile(ifstream &FileIn) {
  FileIn.open("INPUT.txt", ios_base::in);

  // Kiem tra xep tap tin co ton tai hay khong
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin INPUT.txt . Hay kiem tra lai";
    system("pause");
    exit(0);
  }
}

int main() {
  // B1: Mo file
  ifstream FileIn; // Khai bao file
  docFile(FileIn);


  // B2: Doc du lieu tu tap tin vao chuong trinh

  // doc du lieu tu tap tin vao chuong trinh
  // <=> nhap du lieu tu ban phim vao chuong trinh

  // ghi du lieu tu chuong trinh ra tap tin
  // <=> xuat du lieu ra man hinh

  vector<int> arr;

  while(!FileIn.eof()) {
    int number;
    FileIn >> number; // doc du lieu tu file vao number

    arr.push_back(number); // them number vao vector
  }

  // B3: Dong tap tin
  FileIn.close();

  // Sap xep danh sach tang dan
  sapXep(arr, 't');

  /* GHI DU LIEU VAO OUTPUT.txt */

  // B1: Mo file
  ofstream FileOut;
  FileOut.open("OUTPUT.txt", ios_base::out); // Tu dong tao ra moi neu chua co

  // B2: Ghi file
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    FileOut << arr[i] << " ";
  }

  // B3: Dong file
  FileOut.close();

  cout << endl;
  return 0;
}