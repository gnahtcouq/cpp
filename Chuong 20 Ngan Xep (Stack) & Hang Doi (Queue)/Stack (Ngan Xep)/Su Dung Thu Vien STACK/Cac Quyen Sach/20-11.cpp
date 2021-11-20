#include <iostream>
#include <stack>
using namespace std;

// "Nam Son" => noS maN
struct Sach {
    char tenSach[30];
    char nhaXuatBan[30];
    int giaBan;
};
typedef struct Sach SACH;

void nhapSach(SACH &sach){
    fflush(stdin);
    cout << "\nNhap vao ten sach: ";
    gets(sach.tenSach);
    fflush(stdin);
    cout << "Nhap vao ten nha xuat ban: ";
    gets(sach.nhaXuatBan);

    do{
        cout << "Nhap vao gia ban: ";
        cin >> sach.giaBan;
        if(sach.giaBan <= 0)
            cout << "\nNhap sai. Hay nhap lai";
    }
    while(sach.giaBan <= 0);
}

void xuatSach(SACH sach){
    cout << "\nTen sach: " << sach.tenSach;
    cout << "\nNha xuat ban: " << sach.nhaXuatBan;
    cout << "\nGia ban: " << sach.giaBan;
}

void inPut(stack<SACH> &s){
    SACH a, b;
    nhapSach(a);
    nhapSach(b);

    s.push(a);
    s.push(b);
}

void outPut(stack<SACH> &s){
    while(!s.empty()){
        SACH x = s.top();
        xuatSach(x);
        s.pop();
    }
}

int main(){
    stack<SACH> s;
    inPut(s);
    outPut(s);



    cout << endl;
    system("pause");
    return 0;
}