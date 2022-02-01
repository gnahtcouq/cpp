#include <iostream>
using namespace std;

int s = 0;
int baoThuoc(int n, int k) {
  if (n == 0) {
    if (s < k)
      return 0;
    n = s / k;
    s %= k;
    return baoThuoc(n, k);
  }
  s += n % k;
  return n + baoThuoc(n / k, k);
}

int main() {
  // n: bao thuoc
  // k: vo thuoc
  int n, k;
  cin >> n >> k;

  cout << baoThuoc(n, k);

  return 0;
}