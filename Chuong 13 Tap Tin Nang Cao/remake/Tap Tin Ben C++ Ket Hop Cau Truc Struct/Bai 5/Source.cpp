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
#include <vector>
using namespace std;

struct SinhVien {
    string hoTen, soDienThoai;
    int ngay, thang, nam;
    float diemToan, diemLy, diemHoa;
};
typedef struct SinhVien SINHVIEN;
float tinhDiemTrungBinh(SINHVIEN x);
void nhapMotSinhVien(ifstream& FileIn, SINHVIEN& x) {
    getline(FileIn, x.hoTen, '-');
    x.hoTen.erase(x.hoTen.begin() + x.hoTen.length() - 1); // Xoa ki tu cuoi cung
    FileIn.seekg(1, FileIn.cur); // Bo di khoang trang
    FileIn >> x.soDienThoai;
    FileIn.seekg(3, FileIn.cur); // Dich qua 3 byte
    FileIn >> x.ngay;
    FileIn.seekg(1, FileIn.cur); // Bo di dau /
    FileIn >> x.thang;
    FileIn.seekg(1, FileIn.cur); // Bo di dau /
    FileIn >> x.nam;
    FileIn.seekg(3, FileIn.cur); // Dich qua 3 byte
    FileIn >> x.diemToan >> x.diemLy >> x.diemHoa;

    // Co bien nay de doc ky tu cuoi dong
    string temp;
    getline(FileIn, temp);
}

void xuatMotSinhVien(ofstream& FileOut, SINHVIEN x) {
    FileOut << "\nHo ten: " << x.hoTen;
    FileOut << "\nSo dien thoai: " << x.soDienThoai;
    FileOut << "\nSinh ngay " << x.ngay << " thang " << x.thang << " nam " << x.nam;
    FileOut << "\nDiem toan: " << x.diemToan;
    FileOut << "\nDiem ly: " << x.diemLy;
    FileOut << "\nDiem hoa: " << x.diemHoa;
    FileOut << "\nDiem trung binh: " << tinhDiemTrungBinh(x);
    FileOut << "\n----------------------------";
}

float tinhDiemTrungBinh(SINHVIEN x) {
    return (x.diemToan + x.diemLy + x.diemHoa) / 3;
}

void hoanVi(SINHVIEN& a, SINHVIEN& b) {
    SINHVIEN temp = a;
    a = b;
    b = temp;
}

void nhapMangSinhVien(ifstream& FileIn, vector<SINHVIEN>& arr) {
    while (!FileIn.eof()) {
        SINHVIEN x;
        nhapMotSinhVien(FileIn, x);
        arr.push_back(x);
    }
}

void xuatMangSinhVien(ofstream& FileOut, vector<SINHVIEN> arr) {
    for (int i = 0; i < arr.size(); i++) {
        xuatMotSinhVien(FileOut, arr[i]);
    }
}

void sapXepGiamDanTheoDiemTrungBinh(vector<SINHVIEN> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (tinhDiemTrungBinh(arr[i]) < tinhDiemTrungBinh(arr[j]))
                hoanVi(arr[i], arr[j]);
        }
    }
}

int main() {
    ifstream FileIn("INPUT.txt");
    vector<SINHVIEN> arr;
    nhapMangSinhVien(FileIn, arr);
    FileIn.close();

    ofstream FileOut("OUTPUT.txt");
    sapXepGiamDanTheoDiemTrungBinh(arr);
    xuatMangSinhVien(FileOut, arr);
    FileOut.close();

    system("pause");
    return 0;
}