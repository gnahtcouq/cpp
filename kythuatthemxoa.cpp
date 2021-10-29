#include <iostream>
using namespace std;
#define MAX 100
void xuatMang(int a[], int n);
void themPhanTu(int a[], int &n, int vitrithem, int phantuthem);
void xoaPhanTu(int a[], int &n, int vitrixoa);
void xoaTatCaSoChan(int a[], int &n);
void themSauTatCaSoLe(int a[], int &n);

int main(){
    int a[MAX] = {1,3,5,7,9};
    int n = 5;
    cout << "\nMang ban dau la: ";
    xuatMang(a, n);

    // cout << "\nMang sau khi them la: ";
    // themPhanTu(a, n, 2, 69);
    // xuatMang(a, n);

    // cout << "\nMang sau khi xoa la: ";
    // xoaPhanTu(a, n, 2);
    // xuatMang(a, n);

    // cout << "\nMang sau khi xoa tat ca so chan la: ";
    // xoaTatCaSoChan(a, n);
    // xuatMang(a, n);

    cout << "\nMang sau khi them so 0 dang sau tat ca cac so le la: ";
    themSauTatCaSoLe(a, n);
    xuatMang(a, n);


    return 0;
}

void themPhanTu(int a[], int &n, int vitrithem, int phantuthem){
    for(int i=n-1; i>=vitrithem; i--){
        a[i+1] = a[i];
    }
    a[vitrithem] = phantuthem;
    n++; // tang len 1
}
void xoaPhanTu(int a[], int &n, int vitrixoa){
    for(int i = vitrixoa+1; i<n; i++){
        a[i-1] = a[i];
    }
    n--; // giam di 1
}
void xuatMang(int a[], int n){
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}
void xoaTatCaSoChan(int a[], int &n){
    for(int i=0; i<n; i++){
        if(a[i]%2 == 0){
            xoaPhanTu(a, n, i); // hoac xoaPhanTu(a,n,i--);
            i--;
        }
    }
}

// them so 0 vao dang sau tat ca cac so le trong mang
void themSauTatCaSoLe(int a[], int &n){
    for(int i = 0; i<n; i++){
        if(a[i]%2 != 0){
            themPhanTu(a, n, i+1, 0);
            i++;
            }
    }
}