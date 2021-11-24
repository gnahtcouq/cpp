#include <iostream>
using namespace std;

int tinhTong_DeQuy(int n) {
    // Dieu kien dung
    if(n == 1)
        return 1;

    // Buoc de quy
    return tinhTong_DeQuy(n - 1) + n; // O day buoc goi lai ham no chua phai la hanh dong cuoi cung -> khong phai de quy duoi
}

// Dung de quy duoi
int tinhTong_DeQuyDuoi(int n, int x = 0) { // De mac dinh x = 0
    // Dieu kien dung
    if(n == 1)
        return n + x;

    // Buoc de quy
    return tinhTong_DeQuyDuoi(n - 1, n + x); // Loi goi ham la hanh dong cuoi cung
}

int tinhTong_KhuDeQuy(int n) {
    int tong = 0;
    for (int i = 0; i <= n; i++)
        tong += i;
    return tong;    
}

int main(){

    int n = 5;
    cout << "\ntinhTong_DeQuy(" << n << ") = " << tinhTong_DeQuy(n);

    cout << "\ntinhTong_DeQuyDuoi(" << n << ") = " << tinhTong_DeQuyDuoi(n);

    cout << "\ttinhTong_KhuDeQuy(" << n << ") = " << tinhTong_KhuDeQuy(n);


    cout << endl;
    system("pause");
    return 0;
}

/* 
    Cach chay nhu sau:
    VD: Ta nhap vao n = 5 tuc la tinh S(5)

    5 + S(4)
    ma S(4) = 4 + S(3)
    ma S(3) = 3 + S(2)
    ma S(2) = 2 + S(1)
    ma S(1) = 1

        Khi da co S(1) = 1 roi thi tra gia tri len de
    tinh ra duoc S(2) = 3
        Khi da co S(2) = 3 roi thi tra gia tri len de
    tinh ra duoc S(3) = 6
        Khi da co S(3) = 6 roi thi tra gia tri len de
    tinh ra duoc S(4) = 10
        Khi da co S(4) = 10 roi thi tra gia tri len de
    tinh ra duoc S(5) = 15
        => S(5) la ket qua cuoi cung tim duoc

    Ta thay duoc de quy no phai chay 2 lan
    -> Lam cham chuong trinh so voi khi dung vong lap

    Khac phuc: Dung de quy duoi
    Chay tay:
    S(5) = 5 + x (ma x ban dau ta mac dinh la 0)
    -> x = 5;
    Sau do S(4) = 4 + x (ma o lan nay x dang la 5)
    -> x = 4 + 5 = 9
    Sau do S(3) = 3 + x = 3 + 9 = 12
    Sau do S(2) = 2 + x = 2 + 12 = 14
    Sau do S(1) = 1 + x = 1 + 14 = 15

    hoac ta co the dung cach khu de quy
    ----

        DE QUY NHI PHAN
    De bai: Tinh day Fibonancy
    F(0) = F(1) = 1
    F(n) = F(n - 1) + F(n - 2) voi n > 1

    -> Dieu kien dung:  F(0) = F(1) = 1
    -> Cong thuc de quy: F(n) = F(n - 1) + F(n - 2) voi n > 1
*/