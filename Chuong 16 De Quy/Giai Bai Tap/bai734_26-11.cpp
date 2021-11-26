#include <iostream>
#include <time.h>
using namespace std;

// Bai 734
// 1 + 1/3 + 1/5 + ... + 1/(2n+1)



float khuDeQuy(int n) {
  float tong = 1;
  for (int i = 1; i <= n; i++)
    tong += 1.0 / (2 * i + 1);
  return tong;
}



int main() {

  int n = 2;

  cout << "\nTong khuDeQuy(" << n << ") = " << khuDeQuy(n);

  cout << endl;
  return 0;
}