#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  cin >> n;

  printf("%02d:%02d:%02d", n / 3600, (n % 3600) / 60, (n % 3600) % 60);

  return 0;
}