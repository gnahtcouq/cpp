#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define MAX 100
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void xuatChan(int a[], int n);
void xuatViTriAm(int a[], int n);
int timMax(int a[],int n);
int timGiaTriDuongDauTien(int a[], int n);
int timSoChanCuoiCung(int a[], int n);
int timViTriMin(int a[], int n);
int timViTriChanDauTien(int a[], int n);
int timViTriSoHoanThienCuoiCung(int a[], int n);
int timViTriAmDauTien(int a[], int n);
int timGiaTriAmLonNhat(int a[], int n);
double timGiaTriXaNhat(int a[], int n, double x);
int timGiaTriDauTienTrongKhoang(int a[], int n, int x, int y);
int timViTriThoaDieuKien(int a[], int n);
// double timGiaTriGanNhat(int a[], int n, double x);
int kiemTra(int x, int a);
int timGiaTriDauTien(int a[], int n);
int kiemTraToanChuSoLe(int x);
int timSoToanChuSoLeLonNhat(int a[], int n);
int timMin(int a[], int n);
int kiemTraChiaHetChoX(int a[], int n, int x);
int timUCLNCuaMang(int a[], int n);
int kiemTraXChiaHet(int a[], int n, int x);
int timBCNNCuaMang(int a[], int n);

int main(){
    int a[MAX], n;
    int b[10];
    do{
        cout << "\nNhap so luong phan tu cua mang: ";
        cin >> n;
        if (n < 0 || n > MAX)
            cout << "\nBan nhap khong dung. Xin hay nhap lai";
    } while (n < 0 || n > MAX);

    // //random mang
    // srand(time(0));
    // for (int i = 0; i < n; i++){
    //     // stdlib.h & time.h
    //     // srand(time(0));
    //     // a+rand() % (b-a+1)

    //     // random trong doan -20 -> 30
    //     a[i] = -20 + rand() % (51);
    // }
    nhapMang(a, n);
    xuatMang(a, n);

    xuatChan(a, n);
    xuatViTriAm(a, n);
    cout << "\nGia tri lon nhat co trong mang la: " << timMax(a, n);
    cout << "\nGia tri duong dau tien co trong mang la: " << timGiaTriDuongDauTien(a,n);
    cout << "\nGia tri chan cuoi cung co trong mang la: " << timSoChanCuoiCung(a,n);
    cout << "\nVi tri Min co gia tri nho nhat trong mang la: " << timViTriMin(a,n);
    cout << "\nVi tri chan dau tien trong mang la: " << timViTriChanDauTien(a,n);
    cout << "\nGia tri am lon nhat trong mang la: " << timGiaTriAmLonNhat(a,n);
    // double x;
    // cout << "\nNhap x = ";
    // cin >> x;
    // cout << "\nGia tri xa X nhat trong mang la: " << timGiaTriXaNhat(a,n,x);
    // // cout << "\nGia tri gan X nhat trong mang la: " << timGiaTriGanNhat(a,n,x);

    // int x,y;
    // cout << "\nNhap x = ";
    // cin >> x;
    // cout << "\nNhap y = ";
    // cin >> y;
    // cout << "\nGia tri dau tien nam trong khoang ("<<x<<","<<y<<") = " << timGiaTriDauTienTrongKhoang(a,n,x,y);

    cout << "\nVi tri thoa dieu kien la: " << timViTriThoaDieuKien(a,n);
    cout << "\nGia tri dau tien trong mang co dang 2^k la: " << timGiaTriDauTien(a,n);
    cout << "\nGia tri toan chu so le lon nhat co trong mang la: " << timSoToanChuSoLeLonNhat(a,n);
    cout << "\nUCLN cua mang: "<< timUCLNCuaMang(a,n);
    cout << "\nBCNN cua mang: "<< timBCNNCuaMang(a,n);
    cout << endl;
    return 0;
}

void nhapMang(int a[], int n){
    for(int i=0; i<n; i++){
        cout << "\na[" << i << "]= ";
        cin >> a[i];
    }
}
void xuatMang(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void xuatChan(int a[], int n){
    cout << "\nCac gia tri chan trong mang: ";
    for (int i=0;i<n;i++){
        if(a[i]%2==0)
            cout << a[i] << " ";
    }
}
void xuatViTriAm(int a[], int n){
    cout << "\nVi tri ma gia tri tai do la gia tri am trong mang la: ";
    for(int i=0;i<n;i++){
        if(a[i]<0)
            cout << i << " ";
    }
}
int timMax(int a[],int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
int timGiaTriDuongDauTien(int a[], int n){
    for(int i=0;i<n;i++){
        if(a[i]>=0)
            return a[i];
    }
    return -1;
}
int timSoChanCuoiCung(int a[], int n){
    for(int i=n-1;i>=0;i--){
        if(a[i]%2==0)
            return a[i];
    }
    return -1;
}
int timViTriMin(int a[], int n){
    int min = a[0];
    int vitri = 0;
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min = a[i];
            vitri = i;
        }
    }
    return vitri;
}
int timViTriChanDauTien(int a[], int n){
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            return i;
        }
    }
    return -1;
}
int kiemTraHoanThien(int x){
    int tong = 0;
    for(int i=1;i<=x/2;i++){
        if(x%i==0)
            tong+=i;
    }
    return tong==x;
}
int timViTriSoHoanThienCuoiCung(int a[], int n){
    for(int i=n-1;i>=0;i--){
        if(kiemTraHoanThien(a[i])==1)
            return i;
    }
    return -1;
}
int timViTriAmDauTien(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] < 0)
            return i;
    }
    return -1;
}
int timGiaTriAmLonNhat(int a[], int n){
    int vitri = timViTriAmDauTien(a, n);
    int amMax = a[vitri];
    for (int i = vitri + 1; i < n; i++){
        if (a[i] < 0 && a[i] > amMax){
            amMax = a[i];
        }
    }
    return amMax;
}
double timGiaTriXaNhat(int a[], int n, double x){
    double max = fabs(a[0]-x);
    int vitri = 0;
    for(int i=1;i<n;i++){
        if(fabs(a[i]-x)>max){
            max=fabs(a[i]-x);
            vitri=i;
        }
    }
    return a[vitri];
}
// double timGiaTriGanNhat(int a[], int n, double x){
//     double min = fabs(a[0]-x);
//     int vitri = 0;
//     for(int i=1;i<n;i++){
//         if(fabs(a[i]-x)<min){
//             min=fabs(a[i]-x);
//             vitri=i;
//         }
//     }
//     return a[vitri];
// }
int timGiaTriDauTienTrongKhoang(int a[], int n, int x, int y){
    for(int i=0; i<n; i++){
        if(a[i]>x && a[i]<y)
            return a[i];
    }
    return x;
}
int timViTriThoaDieuKien(int a[], int n){
    for(int i=1;i<n-1;i++){
        if(a[i-1]*a[i+1]==a[i])
            return i;
    }
    return -1;
}

// Y tuong: 3567 co 4 chu so
// 3567 / (10^3) = 3
// Vay thi xet 1 so bat ky, lay so do chia cho 10^(so chu so - 1) thi se ra duoc chu so dau tien
// int timGiaTriDauTienThoa(int a[], int n){
//     for(int i=0;i<n;i++){
//         int sochuso = log10((double)a[i])+1;
//         if((a[i] / pow(10.0,sochuso -1)) %2 !=0)
//             return a[i];
//     }
//     return 0;
// }

// Ham kiem tra 1 so x co dang a^k hay khong voi a la so bat ky
// Kiem tra so x co dang a^k hay khong ?
int kiemTra(int x, int a){
    double ketqua = log10((double)x)/log10((double)a);
    return ketqua == (int)ketqua;
}
int timGiaTriDauTien(int a[], int n){
    for(int i=0;i<n;i++){
        // Kiem tra a[i] co dang 2^k
        if(kiemTra(a[i],2)==1)
            return a[i];
    }
    return 0;
}

// vd: mang la: 12 35 678 357 69
// => gia tri thoa la: 357

int kiemTraToanChuSoLe(int x){
    while(x!=0){
        int chuso=x%10;
        x /= 10;
        if(chuso%2 == 0)
            return 0;
    }
    return 1;
}
int timSoToanChuSoLeLonNhat(int a[], int n){
    int max = 0;
    for(int i=0;i<n;i++){
        if(kiemTraToanChuSoLe(a[i])==1 && a[i]>max)
            max = a[i];
    }
    return max;
}
int timMin(int a[], int n){
    int min = a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}
// Kiem tra tat ca moi phan tu trong mang co chia het cho X hay khong
int kiemTraChiaHetChoX(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(a[i]%x!=0)
            return 0; // sai
    }
    return 1; // dung
}
int timUCLNCuaMang(int a[], int n){
    int min = timMin(a,n);
    int check = kiemTraChiaHetChoX(a,n,min);
    if(check==0){ // khong chia het
        for(int i=min/2;i>=1;i--){
            if(kiemTraChiaHetChoX(a,n,i)==1)
                return i;
        }
    }
    return min; // neu nhu tat ca mang deu chia het cho min thi min chinh la UCLN
}
// Tim BCNN cua tat ca phan tu trong mang
// Y tuong: tim ra so lon nhat trong mang roi lan luot lay so lon nhat nhan cho 1,2,3... moi lan nhan kiem tra ket qua vua tim duoc co chia het cho toan bo cac so trong mang hay khong? Neu thoa thi so do chinh la BCNN
int kiemTraXChiaHet(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(x%a[i]!=0)
            return 0; // sai
    }
    return 1;
}
int timBCNNCuaMang(int a[], int n){
    int max = timMax(a,n);
    // vong lap chay vo tan va chi dung lai khi tim duoc so thoa
    int dem = 1;
    while(1){
        int bcnn = dem*max;
        dem++;
        if(kiemTraXChiaHet(a,n,bcnn)==1)
            return bcnn;
    }
    return -1;
}
// Ngoai ra ta co cong thuc: BCNN(a,b)=(a*b)/UCLN(a,b)
