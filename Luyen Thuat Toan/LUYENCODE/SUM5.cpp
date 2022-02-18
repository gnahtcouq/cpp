#include <iostream>
#include <iomanip>
using namespace std;
#define N 100000

int main() {
  int t, n;
  double sum[N];
  cin >> t;
  sum[1] = 1;
  for (int i = 2; i <= N; ++i)
    sum[i] = sum[i - 1] + (double)1 / i;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cout << setprecision(5) << fixed << sum[n] << "\n";
  }

  return 0;
}