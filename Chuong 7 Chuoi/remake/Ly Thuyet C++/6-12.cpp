#include <iostream>
#include <string>
using namespace std;

int STRLEN(char *s) {
  int dem = 0;
  // while (s[dem++] != '\0') {

  // }
  // return dem - 1;

  while (true) {
    if (s[dem] == '\0')
      return dem;
    dem++;
  }
}

int main() {
  // scanf -> gap khoang trang thi khong lay nua
  // gets -> lay het
  // printf -> nen dung
  // puts -> khong nen

  string str = "abcdefghi";
  // cin >> str; // giong scanf?
  // getline(cin, str); // giong gets?
  cout << str;

  // ngta goi la huong doi tuong khi str.


  int length = STRLEN((char*)str.c_str());
  cout << "\nlength = " << length;

  cout << endl;
  return 0;
}