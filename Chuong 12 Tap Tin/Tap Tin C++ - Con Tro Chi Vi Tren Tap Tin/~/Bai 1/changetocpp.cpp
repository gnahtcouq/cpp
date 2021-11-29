#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // B1: Mo file
  // FILE *FileIn; // Khai bao con tro File
  ifstream FileIn;
  
  // Cho con tro toi toi vung nho chua file INPUT.txt
  // FileIn = fopen("INPUT.txt", "r");
  FileIn.open("INPUT.txt", ios_base::in);

  // Kiem tra xep tap tin co ton tai hay khong
  if(!FileIn) {
    cout << "\nKhong tim thay tap tin. Hay kiem tra lai";
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
  // fscanf(FileIn, "%d%d", &a, &b);
  FileIn >> a >> b;

  // B3: Dong tap tin
  // fclose(FileIn);
  FileIn.close();

  cout << "\n a = " << a;
  cout << "\n b = " << b;

  // Tim Max
  int max = a > b ? a : b;

  /* GHI DU LIEU VAO OUTPUT.txt */

  // B1: Mo file
  // FILE *FileOut;
  ofstream FileOut;
  // FileOut = fopen("OUTPUT.txt", "w"); // Tu dong tao ra moi neu chua co
  FileOut.open("OUTPUT.txt", ios_base::out);

  // B2: Ghi file
  // fprintf(FileOut, "\nMax = %d", max);
  FileOut << "\nMax = " << max;

  // B3: Dong file
  // fclose(FileOut);
  FileOut.close();




  cout << endl;
  return 0;
}