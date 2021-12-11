#include <iostream>
using namespace std;

void xuatMang(int a[], int n) {
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) { // Vi tri day hien hanh de tim Min bat dau tu i
    int vitriMin = i; // Bat dau xet tu phan tu dau day hien hanh la i
    for (int j = i + 1; j < n; j++) { // Xet cac phan tu ke tiep de tim Min
      if (a[j] < a[vitriMin]) { // Neu phan tu nao nho hon -> cap nhat lai vi tri Min
        vitriMin = j; // Cap nhat lai vi tri min
      }
    }
    swap(a[i], a[vitriMin]); // Dua phan tu tai vi tri Min do ve dau day hien hanh (tuc la tai vi tri i hien tai)
  }
}

// n * (n - 1) / 2

int main() {
  int a[] = {15, 2, 8, 7, 3, 6, 9, 17};
  int n = sizeof(a) / sizeof(a[0]);
  xuatMang(a, n);
  selectionSort(a, n);
  cout << endl;
  xuatMang(a, n);

  system("pause");
  return 0;
}
