#include <iostream>
#include <math.h>
using namespace std;

int maxOfArray(int arr[1000], int n);
int minOfArray(int arr[1000], int n);

int main(){
    int arr[1000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxOfArray(arr, n) << endl;
    cout << minOfArray(arr, n) << endl;
    return 0;
}

int maxOfArray(int arr[1000], int n){
    int max=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
            index=i+1;
        }
    }
    cout << max << " ";
    return index;
}

int minOfArray(int arr[1000], int n){
    int min=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[i]<=min) {
            min=arr[i];
            index=i+1;
        }
    }
    cout << min << " ";
    return index;
}