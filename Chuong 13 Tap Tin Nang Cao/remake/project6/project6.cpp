/* ==================== CON TRỎ CHỈ VỊ TRÊN FILE ============

CÚ PHÁP:
fseek(<Tên biến con trỏ file>, <Độ dịch tính theo byte>, <Vị trí bắt đầu tính>)

<Độ dịch tính theo yte>: 
- Nếu là số dương tức là dịch chuyển lên
- Nếu là số âm tức là dịch chuyển xuống
- Nếu là 0 tức là không dịch

<Vị trí bắt đầu tính>:
- Nếu muốn bắt đầu tính từ đầu file thì ta sẽ để là SEEK_SET hoặc ghi số 0
- Nếu muốn bắt đầu tính từ vị trí hiện tại con trỏ đang đứng thì ta sẽ để là SEEK_CUR hoặc ghi số 1
- Nếu muốn bắt đầu tính từ cuối file thì ta sẽ để là SEEK_END hoặc ghi số 2

vd:
fseek(FileIn, 2, SEEK_CUR); // Dịch lên 2 byte kể từ vị trí hiện tại con trỏ đang đứng.

fseek(FileIn, -5, 2); // Dịch lùi xuống 5 byte kể từ vị trí cuối file

fseek(FileIn, 3, 0); // Dịch lên 3 byte kể từ vị trí đầu file.

Lưu ý: Nếu phạm vi byte dịch chuyển bị rơi vào 1 vùng không hợp hợp lệ thì chương trình sẽ bị văng lỗi.


Bài 6: Cho cấu trúc file INPUT.TXT chứa thông tin 2 phân số, mỗi phân số nằm trên 1 dòng. Yêu cầu: Đọc thông tin 2 phân số vào và tính tổng/hiệu/tích/thương của 2 phân số đó (kết quả phải được rút gọn). Kết quả ghi vào file OUTPUT.TXT

vd:
INPUT.TXT
1/2
3/4

OUTPUT.TXT
Tong: 5/4
Hieu: -1/4
Tich: 3/8
Thuong: 2/3 */

#include <iostream>
using namespace std;

struct PhanSo {
  int tuSo, mauSo;
};
typedef struct PhanSo PHANSO;

void docFile(FILE*& FileIn, PHANSO& a, PHANSO& b) {
  FileIn = fopen("INPUT.txt", "r");
  if (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0);
  }
  fscanf(FileIn, "%d", &a.tuSo); // Doc vao tu so
  // Cach xu ly 1
  // char c;
  // fscanf(FileIn, "%c", &c);

  // Cach xu ly 2
  fseek(FileIn, 1, SEEK_CUR); // Dich 1 byte ke tu vi tri hien tai
  fscanf(FileIn, "%d", &a.mauSo); // Doc vao mau so

  fscanf(FileIn, "%d", &b.tuSo);
  fseek(FileIn, 1, SEEK_CUR);
  fscanf(FileIn, "%d", &b.mauSo);

  fclose(FileIn);
}

int timUCLN(int a, int b) {
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

void rutGon(PHANSO& x) {
  int ucln = timUCLN(x.tuSo, x.mauSo);
  x.tuSo /= ucln;
  x.mauSo /= ucln;
}

PHANSO operator +(PHANSO a, PHANSO b) {
  PHANSO tong;
  tong.tuSo = a.tuSo * b.mauSo + a.mauSo * b.tuSo;
  tong.mauSo = a.mauSo * b.mauSo;
  rutGon(tong);
  return tong;
}

PHANSO operator -(PHANSO a, PHANSO b) {
  PHANSO hieu;
  hieu.tuSo = a.tuSo * b.mauSo - a.mauSo * b.tuSo;
  hieu.mauSo = a.mauSo * b.mauSo;
  rutGon(hieu);
  return hieu;
}

PHANSO operator *(PHANSO a, PHANSO b) {
  PHANSO tich;
  tich.tuSo = a.tuSo * b.tuSo;
  tich.mauSo = a.mauSo * b.mauSo;
  rutGon(tich);
  return tich;
}

PHANSO operator /(PHANSO a, PHANSO b) {
  PHANSO nghichdao;
  nghichdao.tuSo = b.mauSo;
  nghichdao.mauSo = b.tuSo;
  PHANSO ketqua = a * nghichdao;
  return (ketqua);
  return ketqua;
}

void ghiFile(FILE*& FileOut, PHANSO a, PHANSO b) {
  FileOut = fopen("OUTPUT.txt", "w");

  PHANSO tong, hieu, tich, thuong;
  tong = a + b;
  hieu = a - b;
  tich = a * b;
  thuong = a / b;

  fprintf(FileOut, "Tong: %d/%d\n", tong.tuSo, tong.mauSo);
  fprintf(FileOut, "Hieu: %d/%d\n", hieu.tuSo, hieu.mauSo);
  fprintf(FileOut, "Tich: %d/%d\n", tich.tuSo, tich.mauSo);
  fprintf(FileOut, "Thuong: %d/%d\n", thuong.tuSo, thuong.mauSo);

}

int main() {
  PHANSO a, b;
  FILE* FileIn, * FileOut;
  docFile(FileIn, a, b);
  ghiFile(FileOut, a, b);

  system("pause");
  return 0;
}