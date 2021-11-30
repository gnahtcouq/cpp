/*

Bài  
Cấu trúc file INPUT.TXT được tổ chức như sau:
- Dòng đầu tiên là họ tên của sinh viên
- Dòng tiếp theo lần lượt là điểm 3 môn toán, lý, hóa. Mỗi điểm cách nhau bởi một khoảng trắng

Yêu cầu: Đọc dữ liệu vào chương trình và tính điểm trung bình, xếp loại của sinh viên. Dữ liệu được ghi vào file OUTPUT.TXT

vd:
INPUT.TXT
Nguyen Viet Nam Son
7 8 9

OUTPUT.TXT
Nguyen Viet Nam Son
Diem trung binh: 8
Xep Loai: Gioi


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

float tinhDiemTrungBinh(float toan, float ly, float hoa) {
  return (toan + ly + hoa) / 3;
}

char* xepLoai(float dtb) {
  // 0 -> <2: Kem
  // 2 -> <5: Yeu
  // 5 -> <7: Trung binh
  // 7 -> <8: Kha
  // 8 -> <9: Gioi
  // 9 -> <10: Xuat sac

  if(dtb < 2)
    return "Kem";
  else if(dtb < 5)
    return "Yeu";
  else if(dtb < 7)
    return "Trung Binh";
  else if(dtb < 8)
    return "Kha";
  else if(dtb < 9)
    return "Gioi";
  return "Xuat Sac";
}

// Mo con tro thong qua 1 ham thi no phai truyen tham chieu
void moFile(FILE *&FileIn) { // truyen tham chieu
  FileIn = fopen("INPUT.txt", "r");

  // Kiem tra xem file co ton tai hay khong
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0); // ket thuc toan bo chuong trinh
  }
}

int main() {

  // Mo file INPUT.txt va doc du lieu
  // B1: Mo file
  FILE *FileIn;
  moFile(FileIn);

  // B2: Doc File
  char ten[30];
  float toan, ly, hoa;

  fgets(ten, 30, FileIn);
  fscanf(FileIn, "%f%f%f", &toan, &ly, &hoa);

  // B3: Dong file
  fclose(FileIn);

  // cout << "\nTen: " << ten;
  // cout << "\nToan = " << toan;
  // cout << "\nLy = " << ly;
  // cout << "\nHoa = " << hoa;


  FILE* FileOut = fopen("OUTPUT.txt", "w");

  fprintf(FileIn, "%s", ten);
  float dtb = tinhDiemTrungBinh(toan, ly, hoa);
  char xeploai[30];
  strcpy(xeploai, xepLoai(dtb));

  fprintf(FileOut, "\nDiem trung binh = %f", dtb);
  fprintf(FileOut, "\nXep loai: %s", xeploai);
  // cout << "\nDiem trung binh = " << dtb;
  // cout << "\nXep loai: " << xeploai;

  fclose(FileOut);

  cout << endl;
  return 0;
}