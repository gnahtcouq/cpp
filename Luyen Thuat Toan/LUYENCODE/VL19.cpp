#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int arr[100000], m = 0, count = 0;
  if (a <= b) {
    for (int i = a; i < b; i++) {
      if (i % 3 == 0 && (a < i && i < b)) {
        arr[m++] = i;
        count++;
      }
    }
  }
  if (count == 0)
    cout << "NOT FOUND";

  for (int i = m - 1; i >= 0; i--)
    cout << arr[i] << " ";

  return 0;
}