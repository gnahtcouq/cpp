#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  ifstream FileIn("input.txt");
  while (!FileIn) {
    cout << "\nKhong tim thay tap tin";
    exit(0);
  }

  FileIn >> n;
  cout << "\nSo luong: " << n;


  system("pause");
  return 0;
}