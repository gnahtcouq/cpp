#include <iostream>
#include <string.h>
using namespace std;


int main() {
  char bd[100000];
  cin >> bd;

  for (int i = 0; i < strlen(bd); i++) {
    int check = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (bd[i] == bd[j]) {
        check = 0;
        break;
      }
    }
    if (check == 1)
      cout << bd[i];
  }

  return 0;
}