#include<iostream>

using namespace std;

int main() {
    int arr[1000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int max=arr[0];
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
            index=i;
        }
    }
    cout << index;
    for (int i=index+1;i<n;i++){
        if(arr[i]==arr[index]){
            cout << i;
        }
    }
    return 0;
}
