/*

Bai 1:
Viết chương trình đếm số lần lặp lại của một từ trong một tập tin

INPUT.TXT
Nguyen Tuan
Nguyen Phuoc Vinh Hung
Doan Vuong Binh Tu

Nhập vào key: Nguyen
=> xuất ra kết quả vào tập tin OUTPUT.TXT: Có 2 từ Nguyen


PHÂN BIỆT GIỮA 2 LOẠI TẬP TIN Ở 2 NGÔN NGỮ

Bên C: Tập tin khai báo dù đọc hay ghi đều có chung 1 kiểu là con trỏ FILE
vd: FILE *FileIn, *FileOut

Bên C++: Tập tin khai báo phân biệt rõ ràng 2 kiểu khác nhau
ifstream => đọc
ofstream => ghi

*/

#include <iostream>
#include <fstream> // thu vien ho tro tap tin
#include <string.h>
using namespace std;

int main() {
  ifstream FileIn; // Khai bao tap tin de doc
  ofstream FileOut; // Khai bao tap tin de ghi

  // Mo tap tin de doc

  // open("INPUT.txt", "r");
  FileIn.open("INPUT.txt", ios_base::in);

  // Kiem tra tap tin co ton tai hay khong
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin";
    system("pause");
    return 0;
  }

  // Xu ly tap tin
  
/*   int a;
  fscanf(FileIn, "%d", &a); // Ben C
  cin >> a; // Tu ban phim ben C++
  FileIn >> a; // Tu file ben C++

  fprintf(FileOut, "%d", a); // Ben C
  cout << a; // Tu ban phim xuat ra man hinh
  FileOut << a; // Xuat ra file ben C++

  Doc chuoi ben C
  char str[30];
  Cach 1: fscanf(FileIn, "%s", &str);
  Cach 2: fgets(str, 30, FileIn);

  Gia su str la: "Tran Van Quoc Thang"
  Cach 1: Doc vao se duoc chuoi la: "Tran"
  Cach 2: Doc vao se duoc chuoi la: "Tran Van Quoc Thang"

  Doc chuoi ben C++
  string str;
  Cach 1: FileIn >> str;
  Cach 2: getline(FileIn, str);

  Gia su str la: "Tran Van Quoc Thang"
  Cach 1: Doc vao se duoc chuoi la: "Tran"
  Cach 2: Doc vao se duoc chuoi la: "Tran Van Quoc Thang" */

  string timkiem;
  cout << "\nBan muon tim kiem tu khoa nao: ";
  getline(cin, timkiem);

  int dem = 0;

  // Ben C: while(!feof(FileIn))
  while(!FileIn.eof()) { // Vong lap doc tu dong dau toi dong cuoi
    string str;
    // getline(FileIn, str); // doc nguyen 1 dong trong file va luu vao bien str
    FileIn >> str; // Doc tung tu
    // cout << str << endl;
    if(str == timkiem)
      dem++;
  }

  // Ben C: fclose(FileIn)
  FileIn.close(); // Dong file lai

  // Mo tap tin de ghi
  FileOut.open("OUTPUT.txt", ios_base::out);
  // Ghi tap tin
  FileOut << timkiem << " => " << dem << " lan";
  // Dong tap tin lai
  FileOut.close();

  return 0;
}