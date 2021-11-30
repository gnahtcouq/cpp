#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> arr; // khai bao mang vector chua kieu so nguyen

  // Cach 1:
  // int n = 5;
  // arr.resize(n);// cap phat san ra n o

  // // gan phan tu
  // arr[0] = 1;
  // arr[1] = 2;
  // arr[2] = 3;
  // arr[3] = 4;
  // arr[4] = 5;

  // Cach 2: push_back: Them vao cuoi
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);

  arr.pop_back();


  // arr.insert(arr.begin() + 3, 69); // them so 69 vao vi tri 3
  // arr.insert(arr.begin() + 3, 5, 70); // them 5 so 70 vao vi tri 3
  
  // arr.erase(arr.begin() + 2); // xoa vi tri 2

  // xuat vector

  // lay ra so luong phan tu hien tai vector dang chua
  int sophantu = arr.size();

  for(int i = 0; i < sophantu; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}