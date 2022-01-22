#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char x;
  cin >> x;
  if (x == 'z')
    x = 'a';
  else
    x += 1;

  cout << x;

  return 0;
}