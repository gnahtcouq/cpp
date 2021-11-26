#include <iostream>
using namespace std;

// Tinh s(n) = 1 + 1.2 + 1.2.3 + ... + 1.2.3...n
int deQuyPhiTuyen(int n) {
  if (n == 1)
    return 1;
  int tich = 1;
  for (int i = 1; i <= n; i++) {
    tich *= i;
  }
  return deQuyPhiTuyen(n - 1) + tich;
}

// Cach 2
int tinhGiaiThua(int n) {
  if (n == 1)
    return 1;
  return tinhGiaiThua(n - 1) * n;
}

int deQuy(int n) {
  if (n == 1)
    return 1;
  return deQuy(n - 1) + tinhGiaiThua(n);
}

int main() {
  int n = 3;
  
  cout << "\nDe quy(" << n << ") = " << deQuy(n);
  cout << "\nDe quy phi tuyen(" << n << ") = " << deQuyPhiTuyen(n);

  cout << endl;
  return 0;
}