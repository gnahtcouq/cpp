#include<iostream>

using namespace std;

int maxOfArray(int arr[1000], int n);


int main() {
    int arr[1000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxOfArray(arr,n);
    return 0;
}

int maxOfArray(int arr[1000], int n){
    int max=arr[0];
    int max2=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    for(int i=1;i<n;i++){
        if(arr[i]>max2 && arr[i]<max){
            max2=arr[i];
        }
    }
    cout << max << endl;
    return max2;
}