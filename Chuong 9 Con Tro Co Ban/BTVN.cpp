#include <iostream>
using namespace std;

void nhapMang(int *a, int n);
void xuatMang(int *a, int n);

int main(){
    //Bai 1
    // float pay;
    // float *ptr_pay;
    // pay = 2313.54;
    // ptr_pay = &pay;

    // cout << "\npay = " << pay;
    // cout << "\nptr_pay = " << *ptr_pay;
    // cout << "\n&pay = " << &pay;

    // int *x, y = 2;
    // //Sua loi thieu bo nho: x = new int; hoac x = (int *)malloc(sizeof(int *));
    // *x = y; // *x = 2 va y = 2
    // *x += y++; // *x = 4 va y = 3
    // cout << *x << " " << y;

    // int *pint;
    // float f;
    // char c;
    // double *pd;
    // // a. f = *pint; // gia tri = gia tri -> dung
    // // b. c = *pd; // gia tri = gia tri -> dung
    // // c. *pint = *pd; // gia tri = gia tri -> dung
    // // d. pd = f; // sai cau nay ne do: dia chi = gia tri 

    // Toan tu dung de xac dinh dia chi cua 1 bien -> toan tu dia chi: &
    // Toan tu dung de xac dinh gia tri cua bien do con tro tro den -> toan tu lay gia tri: *

    // Phep lay gia tri gian tiep la gi?
    // int a = 100;
    // int *b = &a; // cho con tro tro den dia chi cua bien a
    // -> *b cung chinh la a (lay gian tiep)

    // Cac phan tu trong mang duoc sap xep trong bo nho nhu the nao?
    // -> Cac phan tu trong mang duoc sap xep lien tuc nhau

    int n;
    do{
        cout << "\nNhap vao n = ";
        cin >> n;
        if(n<0)
            cout << "\nGia tri n khong hop le. Xin kiem tra lai";
    }while(n<0);

    int *a;
    a = new int;
    nhapMang(a,n);
    xuatMang(a,n);
    delete(a);

    return 0;
}
//Bai 1
// a. pay // gia tri cua pay = 2313.54
// b. *ptr_pay // gia tri cua pay (do con tro tro toi bien pay)
// c. *pay // Ko co => cu phap sai
// d. &pay // dia chi cua pay

void nhapMang(int *a, int n){
    for(int i=0; i<n; i++){
        cout << "\nNhap vao a[" << i << "]= ";
        cin >> a[i]; 
    }
}
void xuatMang(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}