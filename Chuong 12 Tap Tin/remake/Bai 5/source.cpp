/*

Bài 5: File INPUT.TXT có cấu trúc như sau
- Dòng đầu tiên có số n tượng trưng cho số lượng các số trong dãy số
- Các dòng tiếp theo là các số, mỗi số cách nhau bởi 1 khoảng trắng

Yêu cầu:
- Đọc dữ liệu từ file vào chương trình và đi sắp xếp dãy số tăng dần. Kết quả ghi vào tập tin OUTPUT.TXT

vd:
INPUT.TXT
5
2 1 4 5 3

OUTPUT.TXT
1 2 3 4 5

DÙNG MẢNG ĐỘNG CON TRỎ

*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void sapXep(int *a, int n, char phanloai) {
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

  // cap phat bo nho cho con tro
  int *a = (int *)malloc(n * sizeof(int));

  // Duyet het mang
  for(int i = 0; i < n; i++) {
    // Doc vao mang tung phan tu
    fscanf(FileIn, "%d", &a[i]);
  }

  // B3: Dong tap tin
  fclose(FileIn);

  // Sap xep danh sach tang dan
  sapXep(a, n, 't');

  /* GHI DU LIEU VAO OUTPUT.txt */

  // B1: Mo file
  FILE *FileOut;
  FileOut = fopen("OUTPUT.txt", "w"); // Tu dong tao ra moi neu chua co

  // B2: Ghi file
  for(int i = 0; i < n; i++) {
    fprintf(FileOut, "%4d", a[i]);
  }

  // B3: Dong file
  fclose(FileOut);

  free(a); // giai phong con tro


  cout << endl;
  return 0;
}