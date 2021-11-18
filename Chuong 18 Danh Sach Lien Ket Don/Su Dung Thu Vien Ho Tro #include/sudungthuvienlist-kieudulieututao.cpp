/* 
nhap xuat danh sach cac hoc sinh trong lop
va tim ra hoc sinh co diem trung binh lon nhat lop

biet thong tin moi hoc sinh gom
- ma so
- ho ten
- diem toan, ly, hoa
 */

#include <iostream>
#include <string>
#include <list>
using namespace std;

struct HocSinh{
    string maSo, hoTen;
    double diemToan, diemLy, diemHoa;
};
typedef struct HocSinh HOCSINH;

void nhapHocSinh(HOCSINH &hs){

    cout << "\nNhap ho ten: ";
    getline(cin, hs.hoTen);

    cout << "\nNhap diem toan: ";
    cin >> hs.diemToan;
    cout << "\nNhap diem ly: ";
    cin >> hs.diemLy;
    cout << "\nNhap diem hoa: ";
    cin >> hs.diemHoa;

}

void xuatHocSinh(HOCSINH hs){
    cout << "\nMa so: " << hs.maSo;
    cout << "\nHo ten: " << hs.hoTen;
    cout << "\nDiem toan = " << hs.diemToan;
    cout << "\nDiem ly = " << hs.diemLy;
    cout << "\nDiem hoa = " << hs.diemHoa;
}

double tinhDiemTrungBinh(HOCSINH hs){
    return (hs.diemToan + hs.diemLy + hs.diemHoa) / 3;
}

double timDiemTrungBinhMax(list<HOCSINH> l){
    list<HOCSINH>::iterator it;
    it = l.begin();
    double max = tinhDiemTrungBinh(*it);
    for(it++; it != l.end(); ++it){
        double diem = tinhDiemTrungBinh(*it);
        if(diem > max)
            max = diem;
    }
    return max;
}

void lietKeTatCaHocSinhDiemCaoNhatLop(list<HOCSINH> l){
    double max = timDiemTrungBinhMax(l);
    for(list<HOCSINH>::iterator it = l.begin(); it != l.end(); ++it){
        if(tinhDiemTrungBinh(*it) == max){
            xuatHocSinh(*it);
            cout << "\n\n";
        }
    }
}

void nhapDanhSach(list<HOCSINH> &l, int n){
    for(int i = 1; i <= n; i++){
        HOCSINH hs;
        
        bool check;
        do{
            check = true;
            fflush(stdin); // xoa bo nho dem
            cout << "\nNhap ma so: ";
            getline(cin, hs.maSo);

            // kiem tra xem truoc do co bi trung hay khong?
            for(list<HOCSINH>::iterator it = l.begin(); it != l.end(); ++it){
                // bi trung
                if((*it).maSo == hs.maSo){
                    check = false;
                    break;
                }
            }
            if(check == false)
                cout << "\nMa so da bi trung. Kiem tra lai";
        }while(check == false);


        nhapHocSinh(hs); // nhap hoc sinh

        l.push_back(hs); // dua hoc sinh vao ds
    }
}

void xuatDanhSach(list<HOCSINH> l){
    int dem = 1;
    for(list<HOCSINH>::iterator it = l.begin(); it != l.end(); ++it){
        cout << "\nThong tin hoc sinh thu " << dem++;
        xuatHocSinh(*it);
    }
}

int main(){
    int n;
    cout << "\nNhap vao so luong hoc sinh: ";
    cin >> n;

    list<HOCSINH> l;
    nhapDanhSach(l, n);
    xuatDanhSach(l);

    double diemMax = timDiemTrungBinhMax(l);
    cout << "\nDiem Max = " << diemMax;

    cout << "\nDanh sach cac hoc sinh co diem lon nhat lop la: ";
    lietKeTatCaHocSinhDiemCaoNhatLop(l);

    cout << endl;
    system("pause");
    return 0;
}