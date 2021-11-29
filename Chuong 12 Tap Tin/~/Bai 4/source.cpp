/*

Bài 4: Giống như Bài 3 nhưng mà trong file INPUT.TXT không có dòng đầu tiên chứa số lượng mà chỉ có 1 dãy các số.

vd:
INPUT.TXT
1 8 3 4 2

OUTPUT.TXT
8

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

  // eof => end of line


  // Vong lap nay se lap lien tuc cho den cuoi file, neu chua den cuoi thi tiep tuc lap
  int max;
  fscanf(FileIn, "%d", &max); // doc so dau tien vao
  while(!feof(FileIn)) {
    int number;
    fscanf(FileIn, "%d", &number);
    
    if(number > max)
      max = number;
  }

  // B3: Dong tap tin
  fclose(FileIn);



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