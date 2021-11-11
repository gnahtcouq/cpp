#include<iostream>
#include <math.h>


using namespace std;

int main() {
    int arr[10000];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    bool check[10001];
      // Khởi tạo tất cả các số [2...N] đều là số nguyên tố
    for(int i=2;i<10000;i++){
        check[i]=true;
    }
    
  // Thuật toán sàng nguyên tố
  // Nếu một số là số nguyên tố, thì tất cả các bội của nó không phải số nguyên tố
    for (int i = 2; i <= 1000; i++) {
        if (check[i] == true){
            for (int j = 2 * i; j <= 10000; j += i){
                check[j] = false;
            }
        }
    }
    int dem[100000];
    for(int i=1;i<=n;i++){
        if(check[arr[i]]==true) dem[arr[i]]++;
    }
    for(int i=1; i<=10000; i++) {
        if(dem[i]>=1) cout<<i<<" ";
    }
    return 0;
}
