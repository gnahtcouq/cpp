#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int check = 1;
  if (n < 2)
    check = 0;
  else if (n > 2) {
    if (n % 2 == 0)
      check = 0;
    for (int i = 3;i <= (int)sqrt((double)n);i += 2) {
      if (n % i == 0)
        check = 0;
    }
  }
  if (check == 1)
    cout << "YES";
  else
    cout << "NO";


  return 0;
}