#include <iostream>
#include <math.h>
using namespace std;

int check(int n) {
  int a = n;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      n /= 2;
    }
  }
  else {
    for (int i = 3; i <= sqrt(n); i++) {
      if (n % i == 0) {
        n /= i;
        break;
      }
    }
  }
  if (n == a)
    return 1;
  return n;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  // long long t;
  // cin >> t;

  // while (t--) {
  //   long long n;
  //   cin >> n;

  //   if (n > 1)
  //     for (int i = n - 1; i > 0; i--)
  //       if (i % 2 != 0 && n % i == 0) {
  //         cout << i << "\n";
  //         break;
  //       }
  // }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int uoc = check(n);
    cout << uoc << "\n";
  }

  return 0;
}