#include <iostream>
using namespace std;
#define MAX 40

void nhapMang(double a[], int n);
void xuatMang(double a[], int n);
double timDiemMax(double a[], int n);
double timDiemMin(double a[], int n);
double tinhTong(double a[], int n);

int main(){
    double a[MAX];
    int n;
    do{
        cout << "\nNhap vao so luong diem thi: ";
        cin >> n;
        if(n<0 || n>MAX)
            cout << "\nSo luong khong hop le. Xin kiem tra lai";
    }while(n<0 || n>MAX);
    nhapMang(a, n);
    xuatMang(a, n);

    double Max = timDiemMax(a, n);
    double Min = timDiemMin(a, n);
    cout << "\nMax = " << Max;
    cout << "\nMin = " << Min;

    double Tong = tinhTong(a, n);
    cout << "\nTong = " << Tong;
    return 0;
}

void nhapMang(double a[], int n){
    for(int i=0; i<n; i++){
        cout << "\nNhap vao diem thi thu " << i+1 << " la: ";
        cin >> a[i];
    }
}
void xuatMang(double a[], int n){
    for(int i=0; i<n; i++){
        cout << "\nDiem thi thu " << i+1 << " la: " << a[i];
    }
}
double timDiemMax(double a[], int n){
    double Max = a[0]; // gan phan tu dau
    for(int i=1; i<n; i++){
        if(a[i] > Max)
            Max = a[i];
    }
    return Max;
}
double timDiemMin(double a[], int n){
    double Min = a[0]; // gan phan tu dau
    for(int i=1; i<n; i++){
        if(a[i] < Min)
            Min = a[i];
    }
    return Min;
}
double tinhTong(double a[], int n){
    double Tong = 0;
    for(int i=0; i<n; i++)
        Tong += a[i];
    return Tong;
}
