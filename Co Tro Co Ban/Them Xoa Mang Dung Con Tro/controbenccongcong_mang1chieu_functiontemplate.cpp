#include <iostream>
using namespace std;

template <typename thangdeptrai>
void nhapMang(thangdeptrai *a, int n){
    for(int i=0;i<n;i++){
        cout << "\nNhap vao a[" << i << "]= ";
        // cin >> a[i];
        cin >> *(a+i);
    }
}
template <typename thangdeptrai>
void xuatMang(thangdeptrai *a, int n){
    for(int i=0;i<n;i++){
        // cout << a[i] << " ";
        cout << " " << *(a+i);
    }
}
template <typename thangdeptrai>
// vua de gia tang, vua giam bot o nho
void realloc(thangdeptrai *&a, int oldSize, int newSize){
    // buoc 1: tao ra 1 mang moi la ban sao cua mang cu roi do du lieu tu mang cu sang
    thangdeptrai *tam = new thangdeptrai[oldSize];

    for(int i = 0; i<oldSize; i++){
        tam[i] = a[i];
    }

    // buoc 2: xoa mang cu di va cap moi lai
    delete[] a;
    a = new thangdeptrai[newSize];

    // buoc 3: do du lieu tu mang tam sang mang moi
    int min = oldSize < newSize ? oldSize : newSize;
    for(int i=0;i<min;i++){
        a[i] = tam[i];
    }

    // buoc 4: xoa mang tam di
    delete []tam;
}
template <typename thangdeptrai>
void themPhanTu(thangdeptrai *&a, int &n, int vitrithem, thangdeptrai phantuthem){
    realloc(a,n,n+1);
    for(int i = n-1; i>=vitrithem; i--){
        a[i+1] = a[i];
    }
    a[vitrithem]=phantuthem;
    n++;
}
template <typename thangdeptrai>
void xoaPhanTu(thangdeptrai *&a, int &n, int vitrixoa){
    for(int i=vitrixoa+1;i<n;i++){
        a[i-1] = a[i];
    }
    realloc(a,n,n-1);
    n--;
}

int main(){
    int n = 5;

    double *a = new double[n]; // cap phat bo nho cho con tro

    nhapMang(a,n);
    xuatMang(a,n);

/*     int vitrithem = 2;
    int phantuthem = 69;
    themPhanTu(a,n,vitrithem,phantuthem);
    cout << "\nMang sau khi them la: ";
    xuatMang(a,n); */

    int vitrixoa = 2;
    xoaPhanTu(a,n,vitrixoa);
    cout << "\nMang sau khi xoa la: ";
    xuatMang(a,n);

    cout << "\na[4]= " << a[4];

    // giai phong tat ca
    delete []a;

    cout << endl;
    system("pause");
    return 0;
}