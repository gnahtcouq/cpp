#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int toanChan(int a[], int n);
int laSNT(int n);
int kiemtraSNT(int n);
int kiemtraMangToanNguyenTo(int a[], int n);
int kiemTra_C1(int a[], int n);
int kiemTra_C2(int a[], int n);
int kiemTra_C3(int a[], int n);
int kiemtraTangDan(int a[], int n);
int chiaHet(int a[], int n);
int tongSNT(int a[], int n);
int vitriCuoiCung(int a[], int n, int x);
int vitriCuoiCung2(int a[], int n, int x);
int vitriSNTDauTien(int a[], int n);
int timMin(int a[], int n);
int timDuongMin(int a[], int n);

int main(){
    int a[MAX];
    int n;
    do{
        cout << "\nNhap so luong phan tu cua mang: ";
        cin >> n;
        if(n<0 || n>MAX)
            cout << "\nBan nhap khong dung. Xin hay nhap lai";
    }while(n<0 || n>MAX);
    nhapMang(a, n);
    xuatMang(a, n);
    int check = toanChan(a, n);
    if(check==1)
        cout << "\nMang da nhap toan chan";
    else
        cout << "\nMang khong phai toan chan";

    int check2 = kiemtraMangToanNguyenTo(a, n);
    if(check2==1)
        cout << "\nMang toan SNT";
    else
        cout << "\nMang khong phai toan SNT";

    int kiemtraSNT = kiemTra_C3(a, n);
    if(kiemtraSNT == 1)
        cout << "\nToan SNT" << endl;
    else
        cout << "\nKhong toan SNT" << endl;


    int check3 = kiemtraTangDan(a, n);
    if(check3 == 1)
        cout << "\nMang tang dan" << endl;
    else
        cout << "\nMang khong tang dan" << endl;

    int dem = chiaHet(a, n);
    cout << "\nCo " << dem << " so chia het cho 4 nhung khong chia het cho 5" << endl;

    int tong = tongSNT(a, n);
    cout << "\nTong so nguyen to co trong mang la: " << tong << endl;

    int x;
    cout << "\nNhap phan tu x = ";
    cin >> x;
    cout << "\nVi tri cuoi cung cua " << x << " co trong mang la: " << vitriCuoiCung2(a,n,x);

    cout << "\nVi tri SNT dau tien la: " << vitriSNTDauTien(a,n);
    cout << "\nMin = " << timMin(a,n);
    cout << "\nSo duong nho nhat trong mang la: " << timDuongMin(a,n);

    return 0;
}

void nhapMang(int a[], int n){
    for(int i=0; i<n; i++){
        cout << "\na[" << i << "]= ";
        cin >> a[i];
    }
}
void xuatMang(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}
int toanChan(int a[], int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(a[i]%2 != 0)
            return 0;
    }
    return 1;
}
int laSNT(int n){
    int dem=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            dem++;
    }
    if(dem==2)
        return 1;
    return 0;
}
int kiemtraSNT(int n){
    if(n<2)
        return 0; // Khong thoa
    else if(n>2){
        if(n%2==0)
            return 0; // Khong thoa
        for(int i=3;i<=(int)sqrt((double)n);i+=2){
            if(n%i==0)
                return 0; // Khong thoa
        }
    }
    return 1; // Thoa
}
int kiemtraMangToanNguyenTo(int a[], int n){
    for(int i=0;i<n;i++){
        if(kiemtraSNT(a[i])==0)
            return 0;
    }
    return 1;
}
// Cach1: Dem so luong so nguyen to cua mang. Neu so luong nay bang dung n thi mang toan nguyen to
int kiemTra_C1(int a[], int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(laSNT(a[i])==1) // co the bo == 1
            dem++;
    }
    if(dem==n)
        return 1;
    return 0;
}

// Cach2: Dem so luong so khong phai nguyen to cua mang. Neu so luong nay bang 0 thi mang toan nguyen to
int kiemTra_C2(int a[], int n){
    int dem=0;
    for(int i=0; i<n; i++){
        if(laSNT(a[i])==0)
            dem++;
    }
    if(dem==0)
        return 1;
    return 0;
}

// Cach 3: Tim xem co phan tu nao khong phai so nguyen to khong. Neu co thi mang khong toan so nguyen to
int kiemTra_C3(int a[], int n){
    for(int i=0; i<n; i++){
        if(laSNT(a[i])==0)
            return 0;
    }
    return 1;
}

int kiemtraTangDan(int a[], int n){
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1])
            return 0; // Khong thoa
    }
    return 1; // Thoa
}

int chiaHet(int a[], int n){
    int dem=0;
    for(int i=0;i<n;i++){
        if(a[i]%4 == 0 && a[i]%5 != 0)
            dem++;
    }
    return dem;
}

int tongSNT(int a[], int n){
    int tong = 0;
    for(int i=0;i<n;i++){
        if(laSNT(a[i])==1)
            tong+=a[i];
    }
    return tong;
}

int vitriCuoiCung(int a[], int n, int x){
    int temp = 0;
    for(int i=0;i<n;i++){
        if(a[i]==x)
            temp=i;
    }
    return temp;
}
int vitriCuoiCung2(int a[], int n, int x){
    // int temp = 0;
    // for(int i=n;i>=0;i--){
    //     if(a[i]==x){
    //         temp=i;
    //         break;
    //     }
    // }
    // return temp;
    for(int i=n;i>=0;i--){
        if(a[i]==x){
            return i;
        }
    }
    return -1; // khong tim thay x trong mang
}
int vitriSNTDauTien(int a[], int n){
    for(int i=0;i<n;i++){
        if(laSNT(a[i]))
            return i;
    }
    return -1;
}
int timMin(int a[], int n){
    int min = a[0];
    for(int i=0;i<n;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}
int timDuongMin(int a[], int n){
    int check = -1;
    int vitriduongdautien = -1;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            vitriduongdautien=i;
            break;
        }
    }
    if(vitriduongdautien==-1)
        return vitriduongdautien;
    int min = a[vitriduongdautien];
    for(int i=vitriduongdautien+1;i<n;i++){
        if(a[i]>=0){
            check = 1;
            if(a[i]<min){
                min=a[i];
            }
        }
    }
    if(check==0)
        return -1;
    return min;
}