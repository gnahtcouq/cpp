#include <iostream>
using namespace std;
#define MAX 100
void xuatMang(int a[], int n);
int kiemTraBiTrung(int a[], int n, int vitridangxet);
int demSoLanXuatHien(int a[], int n, int vitridangxet);
void ketHop2Ham(int a[], int n);
int main(){
    int a[MAX] = {1,2,5,2,3,10,4,2,2,5,10,4,3};
    int n = 13;
    xuatMang(a,n);
    ketHop2Ham(a,n);
    cout << endl;
    return 0;
}
void xuatMang(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
// Ham tu vi tri hien tai xet tien len (ve ban dau) de xet xem phan tu do co bi trung hay khong?
// Neu bi trung thi tra ve 1
// Neu khong trung thi tra ve 0
int kiemTraBiTrung(int a[], int n, int vitridangxet){
    for(int i=vitridangxet-1;i>=0;i--){
        if(a[i] == a[vitridangxet])
            return 1; // da bi trung
    }
    return 0; // khong trung
}
// Ham tu vi tri hien tai xet lui xuong (ve cuoi mang) de dem xem phan tu do xuat hien bao nhieu lan?
int demSoLanXuatHien(int a[], int n, int vitridangxet){
    int dem=1; // do tinh luon vi tri dang xet
    for(int i=vitridangxet+1;i<n;i++){
        if(a[i] == a[vitridangxet])
            dem++;
    }
    return dem;
}
void ketHop2Ham(int a[], int n){
    for(int i=0;i<n;i++){
        // i la vi tri dang xet
        int kiemtratrung = kiemTraBiTrung(a,n,i);
        if(kiemtratrung==1)
            continue;
        // xuong duoi nay tuc la khong tri trung => xet qua phai
        int dem = demSoLanXuatHien(a,n,i);
        cout << "\nPhan tu " << a[i] << " xuat hien " << dem << " lan";
    }
}