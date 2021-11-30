/* ÁP DỤNG string trên file.

vd:
Trong file đang có chuỗi là: "Thang dep trai"
string str;
FileIn >> str; // str = "Thang"
getline(FileIn, str); // str = "Thang dep trai"

-------- STRUCT ---------

Đề bài: Cho danh sách các học sinh có trong lớp, biết thông tin 1 học sinh bao gồm: họ tên, số điện thoại, ngày sinh, điểm toán, lý hóa. Yêu cầu: Sắp xếp danh sách học sinh trong lớp giảm dần theo điểm trung bình biết công thức tính như sau:
Điểm trung bình = (toán + lý + hóa)/3

Dữ liệu đọc vào là từ file INPUT.TXT
Dữ liệu ghi ra là ghi ra file OUTPUT.TXT

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string hoTen, soDienThoai;
  int ngay, thang, nam;
  float diemToan, diemLy, diemHoa;

  ifstream FileIn("INPUT.txt");

  while (!FileIn.eof()) {
    getline(FileIn, hoTen, '-');
    hoTen.erase(hoTen.begin() + hoTen.length() - 1); // Xoa ki tu cuoi cung
    FileIn.seekg(1, FileIn.cur); // Bo di khoang trang
    FileIn >> soDienThoai;
    FileIn.seekg(2, FileIn.cur); // Dich qua 3 byte
    FileIn >> ngay;
    FileIn.seekg(1, FileIn.cur); // Bo di dau /
    FileIn >> thang;
    FileIn.seekg(1, FileIn.cur); // Bo di dau /
    FileIn >> nam;
    FileIn.seekg(2, FileIn.cur); // Dich qua 3 byte
    FileIn >> diemToan >> diemLy >> diemHoa;
    cout << "\nHo ten: " << hoTen;
    cout << "\nSo dien thoai: " << soDienThoai;
    cout << "\nSinh ngay " << ngay << " thang " << thang << " nam " << nam;
    cout << "\nDiem toan: " << diemToan;
    cout << "\nDiem ly: " << diemLy;
    cout << "\nDiem hoa: " << diemHoa;
  }
  FileIn.close();

  system("pause");
  return 0;
}