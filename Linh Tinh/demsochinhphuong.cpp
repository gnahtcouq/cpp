#include<iostream>
#include<math.h>

using namespace std;

void demSCP(long long arr[1000], long long n);
void lietkeSCP(long long arr[1000], long long n);

int main() {
    long long arr[1000];
    long long n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    demSCP(arr,n);
    lietkeSCP(arr,n);
    return 0;
}

void demSCP(long long arr[1000], long long n){
    int count = 0;
    for(int i=0;i<n;i++){
        if(sqrt(arr[i])==(int)sqrt(arr[i])){
            count++;
        }
    }
    cout << count << endl;
}

void lietkeSCP(long long arr[1000], long long n){
    for(int i=0;i<n;i++){
        if(sqrt(arr[i])==(int)sqrt(arr[i])){
            cout << arr[i] << " ";
        }
    }
} 
// 2147483647
// 1000000000000