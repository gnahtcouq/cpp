#include <iostream>
using namespace std;

void xuatMang(int a[], int n);
void hoanVi(int &a, int &b);
void interChangeSort_Tang(int a[], int n);
void interChangeSort_Giam(int a[], int n);
void interChangeSort(int a[], int n, char phanbiet);

int main(){
    // Ky thuat sap xep
    // Interchange Sort
    int a[] = {2, 5, -5, 0, 100, 69};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "\nMang ban dau la: ";
    xuatMang(a, n);
    cout << "\nMang sau khi sap xep tang dan la: ";
    // interChangeSort_Tang(a, n);
    interChangeSort(a, n, 't');
    xuatMang(a, n);
    cout << "\nMang sau khi sap xep giam dan la: ";
    // interChangeSort_Giam(a, n);
    interChangeSort(a, n, 'g');
    xuatMang(a, n);
    return 0;
}

void xuatMang(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
void hoanVi(int &a, int &b){
    a = a - b;
    b = a + b;// b = a
    a = b - a; // a = b
}
void interChangeSort_Tang(int a[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j])
                hoanVi(a[i],a[j]);
        }
    }
}
void interChangeSort_Giam(int a[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] < a[j])
                hoanVi(a[i],a[j]);
        }
    }
}
void interChangeSort(int a[], int n, char phanbiet){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(phanbiet == 't'){ //tang dan
                if(a[i] > a[j])
                    hoanVi(a[i],a[j]);
            }
            else if(phanbiet == 'g'){ // giam dan
                if(a[i] < a[j])
                    hoanVi(a[i],a[j]);
            }
        }
    }
}