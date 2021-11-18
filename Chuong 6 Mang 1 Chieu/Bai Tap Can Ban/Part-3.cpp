#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define MAX 100
void xuatMang(int a[], int n);
int kiemtraSNT(int n);
void suaNguyenToThanhSo0(int a[], int n);
void themPhanTu(int a[], int &n, int vitrithem, int phantuthem);
void xoaPhanTu(int a[], int &n, int vitrixoa);
void chenVaoSauNguyenTo(int a[], int &n, int socanchen);
void xoaTatCaSoNguyenTo(int a[], int &n);
int main(){
    int a[MAX], n;
    do{
        cout << "\nNhap so luong phan tu cua mang: ";
        cin >> n;
        if (n < 0 || n > MAX)
            cout << "\nBan nhap khong dung. Xin hay nhap lai";
    } while (n < 0 || n > MAX);

    //random mang
    srand(time(0));
    for (int i = 0; i < n; i++){
        // stdlib.h & time.h
        // srand(time(0));
        // a+rand() % (b-a+1)

        // random trong doan -20 -> 30
        a[i] = -20 + rand() % (51);
    }
    xuatMang(a, n);

    // cout << "\nSua nguyen to thanh so 0: ";
    // suaNguyenToThanhSo0(a, n);
    // xuatMang(a, n);

    // Chen so 0 vao sau so nguyen to
    cout << "\nMang sau khi chen la: ";
    chenVaoSauNguyenTo(a, n, 0);
    xuatMang(a, n);

    cout << "\nMang sau khi xoa tat ca so nguyen to la: ";
    xoaTatCaSoNguyenTo(a, n);
    xuatMang(a, n);

    cout << endl;
    return 0;
}

void xuatMang(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int kiemtraSNT(int n){
    if (n < 2)
        return 0; // Khong thoa
    else if (n > 2){
        if (n % 2 == 0)
            return 0; // Khong thoa
        for (int i = 3; i <= (int)sqrt((double)n); i += 2){
            if (n % i == 0)
                return 0; // Khong thoa
        }
    }
    return 1; // Thoa
}
void suaNguyenToThanhSo0(int a[], int n){
    for(int i = 0; i < n; i++){
        if(kiemtraSNT(a[i]) == 1)
            a[i] = 0;
    }
}
void themPhanTu(int a[], int &n, int vitrithem, int phantuthem){
    for(int i=n-1;i>=vitrithem;i--){
        a[i+1]=a[i];
    }
    a[vitrithem] = phantuthem;
    n++;
}
void xoaPhanTu(int a[], int &n, int vitrixoa){
    for(int i=vitrixoa+1;i<n;i++){
        a[i-1]=a[i];
    }
    n--;
}
void chenVaoSauNguyenTo(int a[], int &n, int socanchen){
    for(int i=0;i<n;i++){
        if(kiemtraSNT(a[i])==1){
            themPhanTu(a,n,i+1,socanchen);
            i++; // de khong xet lai phan tu vua them
        }
    }
}
void xoaTatCaSoNguyenTo(int a[], int &n){
    for(int i=0;i<n;i++){
        if(kiemtraSNT(a[i])==1){
            xoaPhanTu(a,n,i);
            i--; // lui lai cap nhat vi tri
        }
    }
}