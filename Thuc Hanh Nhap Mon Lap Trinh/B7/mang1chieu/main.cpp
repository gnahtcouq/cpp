#include<iostream>
#include<math.h>
using namespace std;

int tong_Ptuduong(int arr[1000], int n);
int tim_Min(int arr[1000],int n);
int dem_so_PtuAm(int arr[1000], int n);
int sochiahet3(int arr[1000], int n);
void so_Chan(int arr[1000], int n);
int tong_BoiSo7(int arr[1000], int n);
float tbc(int arr[1000], int n);

void nhapMang(int arr[1000], int n);
void xuatMang(int arr[1000], int n);
int kt_SoNguyenTo(int arr[1000], int n);
void xuat_SoNguyenTo(int arr[1000], int n);
int tong_SoNguyenTo(int arr[1000], int n);
void soAm(int arr[1000], int n);
void soLe(int arr[1000], int n);
void nhohon20(int arr[1000], int n);
void soCP(int arr[1000], int n);

int main(){
    int arr[1000];
    int n;
    do{
        cout << "\nNhap n: ";
        cin >> n;
    }while(n<0);
    nhapMang(arr,n);
    xuatMang(arr,n);
    // cout << tong_Ptuduong(arr,n);
    // cout << tim_Min(arr,n);
    // cout << dem_so_PtuAm(arr,n);
    // cout << sochiahet3(arr,n);
    // so_Chan(arr,n);
    // cout << tong_BoiSo7(arr,n);
    // cout << tbc(arr,n);

    // xuat_SoNguyenTo(arr,n);
    // cout << "Tong cac so nguyen to trong mang: "<<tong_SoNguyenTo(arr,n);

    // soAm(arr,n); // FLOAT
    // soLe(arr,n);
    // nhohon20(arr,n);
    // soCP(arr,n);

    return 0;
}

void nhapMang(int arr[1000], int n){
    for(int i=0;i<n;i++){
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void xuatMang(int arr[1000], int n){
    cout << "Mang da nhap: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n" << "---" << "\n";
}


int tong_Ptuduong(int arr[1000], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0) sum+=arr[i];
    }
    return sum;
}

int tim_Min(int arr[1000],int n){
    int min=arr[0];
    for(int i=0;i<n;i++){
            if(arr[i]<=min){
                arr[i]=min;
            }
    }
    return min;
}

int dem_so_PtuAm(int arr[1000], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0) count++;
    }
    return count;
}

int sochiahet3(int arr[1000], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%3==0) count++;
    }
    return count;
}

void so_Chan(int arr[1000], int n){
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            cout << arr[i] << " ";
        }
    }
}

int tong_BoiSo7(int arr[1000], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i]%7==0) sum+=arr[i];
    }
    return sum;
}

float tbc(int arr[1000], int n){
    float tbc=0;
    for(int i=0;i<n;i++){
        tbc+=(float)arr[i]/n;
    }
    return tbc;
}

int kt_SoNguyenTo(int n) {
	if (n < 2) return 0;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return 0;
			}
		}
		return 1;
	}
}

void xuat_SoNguyenTo(int arr[1000], int n){
    cout << "So nguyen to trong mang: ";
    for(int i=0;i<n;i++){
        if(kt_SoNguyenTo(arr[i])){
            cout << arr[i] << " ";
        }
    }
}

int tong_SoNguyenTo(int arr[1000], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(kt_SoNguyenTo(arr[i])){
            sum+=arr[i];
        }
    }
    return sum;
}

void soAm(int arr[1000], int n){
    for(int i=0;i<n;i++){
        if(arr[i]<=0) cout << arr[i] << " ";
    }
}

void soLe(int arr[1000], int n){
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0) cout << arr[i] << " ";
    }
}

void nhohon20(int arr[1000], int n){
    for(int i=0;i<n;i++){
        if(arr[i]%2==0 && arr[i]<20){
            cout << arr[i] << " ";
        }
    }
}

void soCP(int arr[1000], int n){
    int index=0;
    for(int i=0;i<n;i++){
        if(i%2!=0 && sqrt(arr[i])*sqrt(arr[i])==arr[i]) cout << arr[i] << " ";
    }
}
