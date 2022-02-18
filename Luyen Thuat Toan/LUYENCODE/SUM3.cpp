#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;

  cout << setprecision(5) << fixed << (double)n / (n + 1);

  return 0;
}