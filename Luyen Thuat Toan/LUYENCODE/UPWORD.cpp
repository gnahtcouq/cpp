#include <iostream>
#include <string.h>
using namespace std;


int main() {
  char s[1000000];
  cin >> s;

  int length = strlen(s), dem = 0;
  for (int i = 0; i < length; i++) {
    if (i != length - 1)
      if ((s[i] >= 'A' && s[i] <= 'Z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
        dem++;
    if (i == length - 1)
      if (s[length - 1] >= 'A' && s[length - 1] <= 'Z')
        dem++;
  }
  cout << dem;

  return 0;
}