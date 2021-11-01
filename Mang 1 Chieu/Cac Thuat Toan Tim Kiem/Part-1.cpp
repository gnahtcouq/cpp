/* CAC CHIEN LUOC TIM KIEM 
Tim kiem duoc chia lam 2 dang chinh nhu sau:
1. Tim kiem tuan tu (tim kiem tuyen tinh)
    1.1: Vet can
    1.2: Linh canh
2. Tim kiem nhi phan

---TIM KIEM TUAN TU VET CAN---

n = 7
a0 a1 a2 a3 a4 a5 a6
Nhu cau: tim phan tu X xem co nam trong mang hay khong?

---TIM KIEM TUAN TU LINH CANH---
n = 7
a0 a1 a2 a3 a4 a5 a6
Nhu cau: tim phan tu X xem co nam trong mang hay khong?
Neu nhu lam o cach tim kiem tuan tu vet can thi ta phai so sanh 2 lan
lan 1: i<n
lan 2: a[i] == x
tuy nhien ta co the bo di so sanh i<n bang cach dua truc tiep phan tu X can tim kiem vao dung o cuoi mang va cu the duyet vong lap dam bao chac chan 1 dieu dk so sanh a[i]==x se xay ra
tu do dua vao vi tri tim thay ta se biet x co ton tai hay khong

---TIM KIEM NHI PHAN---
Luu y: chi cai dat thuat toan nay trong dieu kien day so co thu tu (tang dan/giam dan)

500 1000 2000 5000 10.000 50.000 100.000 200.000 500.000

Y tuong:
Lay phan tu trung gian va so sanh phan tu can tim ma > trung gian
=> tim qua tay phai cua trung gian
Neu phan tu can tim ma < trung gian
=> tim qua tay trai cua trung gian

Thuat toan:

b1: Dat left = 0, right = n-1
b2: Trong khi left <= right
thi lay trung gian mid = (left+right)/2
So sanh neu x > a[mid] => left = mid + 1
So sanh neu x < a[mid] => right = mid - 1
So sanh neu x == a[mid] => mid la vi tri ton tai cua x

b3: neu left <= right thi lap lai B2,
con khong thi dung lai va ket luan khong tim thay

left-----(right) mid (left)-----right

*/
#include <iostream>
using namespace std;
#define MAX 100

int timKiemTuanTuVetCan(int a[], int n, int x);
int timKiemTuanTuLinhCanh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);

int main(){
    int a[MAX]={1,2,3,4,5,6,7};
    int n = 7;
    int x = 5;
    
    int vitri = timKiemNhiPhan(a,n,x);
    if(vitri==-1)
        cout << "\nKhong ton tai";
    else
        cout << "\nCo ton tai tai vi tri " << vitri;

    cout << endl;
    return 0;
}
int timKiemTuanTuVetCan(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}
int timKiemTuanTuLinhCanh(int a[], int n, int x){
    a[n]=x; // Dua x vao dung o cuoi mang
    for(int i=0; ;i++){
        if(a[i] == x)
            return i;
    }
}
int timKiemNhiPhan(int a[], int n, int x){
    int left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(x > a[mid])
            left = mid + 1;
        else if(x < a[mid])
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}