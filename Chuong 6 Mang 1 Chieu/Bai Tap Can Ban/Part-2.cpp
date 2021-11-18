#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define MAX 100
void xuatMang(int a[], int n);
int kiemtraSNT(int n);
void tachSNT(int a[], int n, int b[], int &m);
void tachNguyenDuong(int a[], int n, int b[], int &m, int c[], int &l);
void hoanVi(int &a, int &b);
void interChangeSort(int a[], int n, char phanbiet);
void sapXepAmDuong(int a[], int n, int b[], int m, int c[], int l);
int main(){
    int a[MAX], n;
    int b[MAX], m;
    int c[MAX], l;
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
    cout << "\nMang b chua cac so nguyen to co trong mang a la: ";
    tachSNT(a, n, b, m);
    xuatMang(b, m);
    cout << "\nTach thanh 2 mang am duong";
    tachNguyenDuong(a, n, b, m, c, l);
    cout << "\nMang b chua cac so nguyen duong co trong mang a la: ";
    xuatMang(b, m);
    cout << "\nMang c chua cac so con lai co trong mang a la: ";
    xuatMang(c, l);

    cout << "\nSap xep mang tang dan: ";
    interChangeSort(a, n, 't');
    xuatMang(a, n);

    // //Sap xep mang duong giam dan
    // interChangeSort(b,m,'g');
    // //Sap xep mang am tang dan
    // interChangeSort(c,l,'t');

    cout << "\nDuong giam, Am Tang, 0 dung cuoi: ";
    sapXepAmDuong(a, n, b, m, c, l);
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

void tachSNT(int a[], int n, int b[], int &m){
    m = 0;
    for (int i = 0; i < n; i++){
        if (kiemtraSNT(a[i]) == 1)
            b[m++] = a[i];
    }
}

void tachNguyenDuong(int a[], int n, int b[], int &m, int c[], int &l){
    m = l = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > 0)
            b[m++] = a[i];
        else
            c[l++] = a[i];
    }
}

void hoanVi(int &a, int &b){
    // int temp = a;
    // a = b;
    // b = temp;
    b = a + b; //cho dai
    a = b - a; //a=b
    b = b - a; //b=a
}

//Sap xep InterChangeSort
void interChangeSort(int a[], int n, char phanbiet){
    // a - b - c - d
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (phanbiet == 't'){
                if (a[i] > a[j])
                    hoanVi(a[i], a[j]);
            }
            else if (phanbiet == 'g'){
                if (a[i] < a[j])
                    hoanVi(a[i], a[j]);
            }
        }
    }
}
void sapXepAmDuong(int a[], int n, int b[], int m, int c[], int l){
    //mang duong giam dan (khong co so 0)
    interChangeSort(b,m,'g');
    //mang am tang dan (co so 0)
    interChangeSort(c,l,'t');
    int i;
    for(i=0;i<m;i++){
        a[i]=b[i];
    }
    for(int j=0;j<l;j++){
        a[i++]=c[j];
    }
}