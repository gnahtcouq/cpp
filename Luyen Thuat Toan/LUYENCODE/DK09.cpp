#include <iostream>
using namespace std;

bool kiemTraNamNhuan(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 4 == 0 && year % 100 != 0)
    return true;
  return false;
}

int main() {
  int year;
  cin >> year;

  if (year <= 0 || year > 100000)
    cout << "INVALID";

  else {
    if (kiemTraNamNhuan(year))
      cout << "YES";
    else
      cout << "NO";
  }

  return 0;
}