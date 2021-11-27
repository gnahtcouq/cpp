#include <iostream>
using namespace std;

int main() {
  int* a = new int;
  *a = 1;
  int* Pointer = a; // Con trỏ Pointer trỏ tới con trỏ a.

  delete Pointer; // Giải phóng con trỏ Pointer => con trỏ a cũng bị giải phóng luôn.

  // printf("\n*a = %d", *a);
  // printf("\n*Pointer = %d", *Pointer);

  cout << "\n*a = " << *a;
  cout << "\n*Pointer = " << *Pointer;

  return 0;
}