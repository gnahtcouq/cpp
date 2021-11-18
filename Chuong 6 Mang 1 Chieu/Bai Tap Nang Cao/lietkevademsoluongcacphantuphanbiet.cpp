#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define MAX 100
void xuatMang(int a[], int n);
void lietKeVaDemPhanBiet(int a[], int n);
int demPhanBiet(int a[], int n);
void hoanVi(int &a, int &b);
void interChangeSort_Giam(int a[], int n);
void lietKeVaoMangB(int a[], int n, int b[], int &m);
void xuatPhanTuLonThuK(int b[], int m, int k);
void demSoLanXuatHien(int a[], int n, int b[], int m);
int main(){
    int a[MAX], n;
    int b[MAX], m;
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

        // random trong doan -20 -> 50
        a[i] = -20 + rand() % (71);
    }
    cout << "\nMang sau khi random: ";
    xuatMang(a,n);
    lietKeVaDemPhanBiet(a,n);
    cout << "\nMang b chua cac gia tri phan biet chua sap xep: ";
    lietKeVaoMangB(a,n,b,m);
    xuatMang(b,m);
    // cout << "\nMang b sau khi sap xep giam dan: ";
    // interChangeSort_Giam(b,m);
    // xuatMang(b,m);
    // int k;
    // xuatPhanTuLonThuK(b,m,k);
    demSoLanXuatHien(a,n,b,m);
    cout << endl;
    return 0;
}
void xuatMang(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
/*
Bai tap: Liet ke va dem so luong cac phan tu phan biet co trong mang
vd: mang la: 1 2 1 4 5 3 2 2 6 8 6
=> mang phan biet la: 1 2 4 5 3 6 8
=> co 7 phan tu phan biet
*/

void lietKeVaDemPhanBiet(int a[], int n){
    cout << "\nCac phan tu phan biet la: ";
    int dem = 0;
    for(int i=0;i<n;i++){
        int check = 1; // true
        // tu vi tri i se lui ve cac vi tri truoc de de xet
        for(int j=i-1;j>=0;j--){
            if(a[i] == a[j]){
                // da bi trung
                check = 0; // false
                break;
            }
        }
        if(check==1){
            cout << a[i] << " ";
            dem++;
        }
    }
    cout << "\nCo " << dem <<" phan tu phan biet";
}

int demPhanBiet(int a[], int n){
    int dem = 0;
    for(int i=0;i<n;i++){
        int check = 1; // true
        // tu vi tri i se lui ve cac vi tri truoc de de xet
        for(int j=i-1;j>=0;j--){
            if(a[i] == a[j]){
                // da bi trung
                check = 0; // false
                break;
            }
        }
        if(check==1){
            dem++;
        }
    }
    return dem;
}
void hoanVi(int &a, int &b){
    a = a - b;
    b = a + b;// b = a
    a = b - a; // a = b
}
void interChangeSort_Giam(int a[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] < a[j])
                hoanVi(a[i],a[j]);
        }
    }
}
void lietKeVaoMangB(int a[], int n, int b[], int &m){
    m=0;
    for(int i=0;i<n;i++){
        int check = 1; // true
        // tu vi tri i se lui ve cac vi tri truoc de de xet
        for(int j=i-1;j>=0;j--){
            if(a[i] == a[j]){
                // da bi trung
                check = 0; // false
                break;
            }
        }
        if(check==1){
            b[m++] = a[i];
        }
    }
}
void xuatPhanTuLonThuK(int b[], int m, int k){
    int soluongphanbiet = demPhanBiet(b,m);
    do{
        cout << "\nNhap k = ";
        cin >> k;
        if(1>k || k>soluongphanbiet)
            cout << "\nNhap sai. Vui long nhap lai";
    }while(1>k || k>soluongphanbiet);
    int phantulonthuk;
    for(int i=0;i<m;i++){
        phantulonthuk = b[k-1];
    }
    cout << "Phan tu lon thu " << k << " la: " << phantulonthuk;
}