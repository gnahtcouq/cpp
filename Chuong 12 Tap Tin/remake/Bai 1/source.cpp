/*

Bài 1: Đọc dữ liệu từ file INPUT.TXT vào chương trình biết trong file INPUT.TXT gồm có 2 số a, b cách nhau bởi khoảng trắng.

Yêu cầu: Đọc 2 số đó vào và tìm Max của chúng, kết quả xuất ra file OUTPUT.TXT

vd:
INPUT.TXT
1 2

OUTPUT.TXT
2 

*/

#include <iostream>
using namespace std;



int main() {
  // B1: Mo file
  FILE *FileIn; // Khai bao con tro File
  
  // Cho con tro toi toi vung nho chua file INPUT.txt
  FileIn = fopen("INPUT.txt", "r");

  // Kiem tra xep tap tin co ton tai hay khong
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin INPUT.txt . Hay kiem tra lai";
    return 0;
  }

  // B2: Doc du lieu tu tap tin vao chuong trinh

  // doc du lieu tu tap tin vao chuong trinh
  // <=> nhap du lieu tu ban phim vao chuong trinh

  // ghi du lieu tu chuong trinh ra tap tin
  // <=> xuat du lieu ra man hinh

  int a, b;

  // doc du lieu vao chuong trinh
  // scanf("%d%d", &a, &b);
  fscanf(FileIn, "%d%d", &a, &b);

  // B3: Dong tap tin
  fclose(FileIn);

  cout << "\n a = " << a;
  cout << "\n b = " << b;

  // Tim Max
  int max = a > b ? a : b;

  /* GHI DU LIEU VAO OUTPUT.txt */

  // B1: Mo file
  FILE *FileOut;
  FileOut = fopen("OUTPUT.txt", "w"); // Tu dong tao ra moi neu chua co

  // B2: Ghi file
  fprintf(FileOut, "\nMax = %d", max);

  // B3: Dong file
  fclose(FileOut);




  cout << endl;
  return 0;
}