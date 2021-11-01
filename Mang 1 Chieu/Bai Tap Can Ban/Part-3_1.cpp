#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 100

void xuatMang(int a[], int n);
void themPhanTu(int a[], int &n, int pos, int x);
void xoaPhanTu(int a[], int &n, int pos);
int kiemtraSNT(int n);
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

    cout << "\nMang sau khi them 0 vao sau so nguyen to la: ";
    chenVaoSauNguyenTo(a, n, 0);
    xuatMang(a, n);

    cout << "\nMang sau khi xoa tat ca so nguyen to la: ";
    xoaTatCaSoNguyenTo(a, n);
    xuatMang(a, n);

    cout << endl;
    return 0;
}

void xuatMang(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
// void themPhanTu(int a[], int &n, int vitrithem, int phantuthem){
//     for(int i=n-1;i>=vitrithem;i--){
//         a[i+1] = a[i];
//     }
//     a[vitrithem] = phantuthem;
//     n++;
// }
void themPhanTu(int a[], int &n, int pos, int x){
    for(int i=n-1;i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos]=x;
    n++;
}
// void xoaPhanTu(int a[], int &n, int vitrixoa){
//     for(int i=vitrixoa+1;i<n;i++){
//         a[i-1]=a[i];
//     }
//     n--;
// }
void xoaPhanTu(int a[], int &n, int pos){
    for(int i=pos+1;i<n;i++){
        a[i-1] = a[i];
    }
    n--;
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
void chenVaoSauNguyenTo(int a[], int &n, int socanchen){
    for(int i=0; i<n; i++){
        if(kiemtraSNT(a[i])==1){
            themPhanTu(a, n, i+1, socanchen);
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