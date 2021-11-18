#include <iostream>
using namespace std;
#define MAX 100
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void hoanVi(int &a, int &b);
void sapXepDuongTang(int a[], int n);
void sapXepDuongAm(int a[], int n);
void lietKe(int a[], int n);
void lietKe2(int a[], int n);

int main(){
    int a[MAX], n;
    do{
        cout << "\nNhap so luong phan tu cua mang: ";
        cin >> n;
        if(n<0 || n>MAX)
            cout << "\nNhap sai. Hay nhap lai";
    }while(n<0 || n>MAX);
    nhapMang(a,n);
    xuatMang(a,n);
    
    // cout << "\nMang sau khi da sap xep la: ";
    // sapXepDuongTang(a,n);
    // xuatMang(a,n);


    // cout << "\nMang sau khi da sap xep la: ";
    // sapXepDuongAm(a,n);
    // xuatMang(a,n);

    lietKe(a,n);
    lietKe2(a,n);

    cout << endl;
    return 0;
}

void nhapMang(int a[], int n){
    for(int i=0;i<n;i++){
        cout << "\na["<<i<<"]= ";
        cin >> a[i];
    }
}
void xuatMang(int a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
void hoanVi(int &a, int &b){
    //cach 1
    int temp = a;
    a = b;
    b = temp;
    // //cach 2
    // b = a+b;
    // a = b-a;// a = b
    // b = b-a; // b = a
}
void sapXepDuongTang(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j] && a[i]>=0 && a[j]>=0)
                hoanVi(a[i],a[j]);
        }
    }
}
void sapXepDuongAm(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>=0 && a[j]>=0){
                if(a[i]>a[j]) // sap xep duong tang dan
                    hoanVi(a[i],a[j]);
            }
            if(a[i]<0 && a[j]<0){
                if(a[i]<a[j]) // sap xep am giam dan
                    hoanVi(a[i],a[j]);
            }
        }
    }
}
void lietKe(int a[], int n){
    cout << "\nNhung so thoa dieu kien la: ";
    for(int i=0;i<n-1;i++){
        if(a[i]>abs(a[i+1]))
            cout << a[i] << " ";
    }
}
void lietKe2(int a[], int n){
    cout << "\nNhung so thoa dieu kien la: ";
    for(int i=1;i<n-1;i++){
        // cach 1
        // if(a[i]<abs(a[i+1]) && a[i]>a[i-1])
        //     cout << a[i] << " ";
        // cach 2: chay tot hon
        // if(a[i]>=abs(a[i+1]))
        //     continue;
        // if(a[i]<a[i-1])
        //     cout << a[i] << " ";
        // cach 3
        if(a[i]>=abs(a[i+1]) || a[i]<=a[i-1])
            continue;
        cout << a[i] << " ";
    }
}