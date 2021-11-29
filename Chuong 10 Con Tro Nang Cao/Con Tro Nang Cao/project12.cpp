#include <iostream>
#include <string>
using namespace std;

/* ========= TÙY BIẾN MÃ NGUỒN =========

template chỉ có ở C++

Có 2 loại:
1/ Function Template (Khuôn mẫu hàm)
2/ Class Template (Khuôn mẫu lớp) => lập trình hướng đối tượng.

*/

template <class ThangDepTrai>
void hoanVi(ThangDepTrai& a, ThangDepTrai& b) {
  ThangDepTrai temp = a;
  a = b;
  b = temp;
}

int main() {
  string a = "Nam", b = "Son";

  hoanVi<string>(a, b);

  cout << "\na = " << a << " & b = " << b;

  system("pause");
  return 0;
}