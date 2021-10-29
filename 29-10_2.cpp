#include <iostream>
using namespace std;
#define MAX 100

int main(){
    int a[MAX]; // Khai bao mang co toi da 100 phan tu
    int n;
    do{
        cout << "\nNhap vao so luong phan tu cua mang: ";
        cin >> n;
        if(n<0 || n>MAX)
            cout << "\nSo luong khong hop le. Xin kiem tra lai";
    }while(n<0 || n>MAX);

    // nhap mang
    for(int i=0; i<n; i++){
        cout << "\nNhap vao a[" << i << "]= ";
        cin >> a[i];
    }

    // xuat mang
    cout << "\nMang la: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}