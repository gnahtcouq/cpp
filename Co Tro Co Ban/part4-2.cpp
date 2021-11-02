#include <iostream>
#include <stdlib.h> // cap phat bo nho con tro
using namespace std;

void nhapMang(int *a, int n){
    for(int i=0 ; i<n ; i++){
        cout << "\nNhap vao a[" << i << "]= ";
        cin >> a[i];
    }
}
void xuatMang(int *a, int n){
    for(int i=0 ; i<n ; i++){
        cout << " " << a[i];
    }
}

int main(){
    int n;
    do{
        cout << "\nNhap vao n = ";
        cin >> n;
        if(n<0){
            cout << "\nGia tri n khong hop le. Xin kiem tra lai";
        }
    }while(n<0);
    
    // cap phat con tro mang
    int *a; // khai bao

    // cap phat bo nho
    // a = (int *)malloc(n*sizeof(int));
    // a = (int *)calloc(n, sizeof(int));
    a = (int *)realloc(NULL, n*sizeof(int));

    // malloc neu nhu khong nhap ma xuat thi gia tri xuat ra se la gia tri rac
    // calloc neu nhu khong nhap ma xuat thi gia tri xuat ra se la so 0
    // boi vi chi can o dau tien trong mang co gia tri thi tu khac cac o con lai nhan gia tri 0 het
    // => tao ra 1 mang toan so 0
    // realloc la dai ca, no co 2 chuc nang:
    // 1/ tao moi 1 vung nho
    // 2/ tu 1 vung nho da co, co the gia tang them hoac giam bot bo nho cua no


    nhapMang(a,n);
    xuatMang(a,n);

    // // gia tang them 1 o nho
    // realloc(a, (n + 1)*sizeof(int));
    // // giam bot 1 o nho
    // realloc(a, (n - 1)*sizeof(int));
    
    // a[n] = 69;
    // cout << "\n" <<  a[n];

    free(a); // giai phong bo nho
    return 0;
}