#include <iostream>
#include <math.h>
using namespace std;

// Tra ve vi tri con trai cua Node co index la idx
int left(int idx) {
  int ketqua = 2 * idx + 1;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}


// Tra ve vi tri con phai cua Node co index la idx
int right(int idx) {
  int ketqua = 2 * idx + 2;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}

int timCha(int idx) {
  int ketqua;
  if (idx % 2 == 0)
    ketqua = idx / 2 - 1;
  else
    ketqua = idx / 2;
  if (ketqua < 0 || ketqua > 14)
    return -1; // Khong hop le
  return ketqua;
}

int main() {
  char a[] = "ABCDEFGHI?JK??L";

  // char a[15];
  // a[0] = 'A';
  // a[1] = 'B';
  // a[2] = 'C';
  // a[3] = 'D';
  // a[4] = 'E';
  // a[5] = 'F';
  // a[6] = 'G';
  // a[7] = 'H';
  // a[8] = 'I';
  // a[9] = '?';
  // a[10] = 'J';
  // a[11] = 'K';
  // a[12] = '?';
  // a[13] = '?';
  // a[14] = 'L';

  // cout << "\nroot = " << a[0];
  // cout << "\nroot->left = " << a[left(0)];
  // cout << "\nroot->right = " << a[right(0)];

  // cout << "\nroot->left->left = " << a[left(left(0))];
  // cout << "\nroot->left->right = " << a[right(left(0))];

  // cout << "\nroot->left->right->right = " << a[right(right(left(0)))];
  // if (a[left(right(left(0)))] != '?')
  //   cout << "\nroot->left->right->left = " << a[left(right(left(0)))];

  // cout << "\nroot->left->left->left = " << a[left(left(left(0)))];

  // cout << "\nroot->left->right->right = ";
  // if (right(right(left(0))) == -1 || (right(right(left(0))) != -1 && a[right(right(left(0)))] == '?'))
  //   cout << "Khong co con o vi tri nay";
  // else
  //   cout << a[right(right(left(0)))];

  int idx = 0;
  if (timCha(idx) == -1)
    cout << "\nNode " << a[idx] << " khong co cha";
  else
    cout << "\nCha cua Node " << a[idx] << " la " << a[timCha(idx)];


  system("pause");
  return 0;
}