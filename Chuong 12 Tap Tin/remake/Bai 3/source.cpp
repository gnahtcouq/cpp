/*

Bài 3:
Thông tin file INPUT.TXT như sau:
- Dòng đầu tiên có số n tượng trưng cho số lượng các học sinh trong lớp
- Các dòng tiếp theo có n số cách nhau bởi khoảng trắng => tượng trưng cho điểm số của các học sinh trong lớp.

Yêu cầu: Đọc dữ liệu vào chương trình và tìm ra xem học sinh điểm cao nhất là bao nhiêu ? Kết quả ghi vào file OUTPUT.TXT

vd:
INPUT.TXT
5
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

  int n; // so luong
  fscanf(FileIn, "%d", &n);

  // max la so dau tien
  int max;
  fscanf(FileIn, "%d", &max);

  // cho vong lap chay n-1 lan, moi lan doc vao 1 so
  for(int i = 2; i <= n; i++) {
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