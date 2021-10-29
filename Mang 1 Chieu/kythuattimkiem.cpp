#include <iostream>
using namespace std;
#define MAX 40

void nhapMang(double a[], int n);
void xuatMang(double a[], int n);
double timDiemMax(double a[], int n);
int demSoLuongDiemLonNhat(double a[], int n, double Max);

int main(){
    // vong lap duyet nguoc:
    // for(int i=n-1; i>=0; i--)

    // vong lap duyet xuoi:
    // for(int i=0; i<n; i++)
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

    int soluong =  demSoLuongDiemLonNhat(a, n, Max);
    cout << "\nSo luong co diem lon nhat la: " << soluong;

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
int demSoLuongDiemLonNhat(double a[], int n, double Max){
    int dem = 0;
    for(int i=0; i<n; i++){
        if(a[i] == Max)
            dem++;
    }
    return dem; 
}