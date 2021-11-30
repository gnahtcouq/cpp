/* CON TRỎ CHỈ VỊ Ở TRÊN FILE

INPUT.TXT
31/@@#10/1994

BẢN CHẤT TRONG FILE CHỈ LÀ CÁC BYTE DỮ LIỆU

Con trỏ chỉ vị giúp cho ta đứng tại 1 vị trí bất kỳ trong file và có thể tăng/giảm biên độ dịch chuyển byte

+ Nếu là tăng => đi tới
+ Nếu là giảm => lùi về

Lưu ý: Nếu đi vào 1 vùng byte không xác định thì sẽ bị lỗi.

Vị trí con trỏ được xác định như sau:
+ SEEK_SET (hay là số 0): Vị trí con trỏ tính từ đầu file
+ SEEK_CUR (hay là số 1): Vị trí con trỏ tính từ hiện tại
+ SEEK_END (hay là số 2): Vị trí con trỏ tính từ cuối file

Biên độ dịch chuyển byte:
+ Nếu là số dương: Dịch lên
+ Nếu là số âm: Dịch lùi

BÀI TẬP ỨNG DỤNG
Thông tin của 1 sinh viên được lưu trữ trong file TXT như sau:
Nguyen Viet Nam Son - 31/10/1994 - 7 - 8 - 9

Tên - Ngày Sinh - Toán - Lý - Hóa

Yêu cầu: Đọc thông tin của sinh viên đó vào và tính điểm trung bình. */

// Nguyen Viet Nam Son

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
  FILE *FileIn;
  FileIn = fopen("INPUT.txt", "r");

  if(!FileIn) {
    cout << "\nKhong tim thay tap tin. Hay kiem tra lai";
    return 0;
  }

  // Xu ly
  char str1[30], str2[30];
  fseek(FileIn, 7, SEEK_SET);
  fgets(str1, 5, FileIn); // Viet

  // fseek(FileIn, 5, SEEK_CUR);
  // fgets(str2, 4, FileIn); // Son

  fseek(FileIn, -3, SEEK_END);
  fgets(str2, 4, FileIn); // Son

  fclose(FileIn);

  printf("%s\n%s", str1, str2);

  cout << endl;
  return 0;
}