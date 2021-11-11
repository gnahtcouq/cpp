#include<iostream>

using namespace std;

void sxArray(int arr[1000], int n);


int main() {
    int arr[1000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sxArray(arr,n);
}

void sxArray(int arr[1000], int n){
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}