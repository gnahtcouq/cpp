#include <iostream>
#include <windows.h>
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

// // tra ve vi tri tim thay
// int STRSTR(char *s, char *key) {
//   int length_s = STRLEN(s);
//   int length_key = STRLEN(key);

//   // duyet chuoi dang chua chuoi can tim
//   for (int i = 0; i < length_s; i++) {
//     if (s[i] == key[0]) {
//       int k = 1;
//       int check = true;
//       for (int j = i + 1; j < length_key; j++) {
//         if (s[j] != key[k++]) {
//           check = false;
//           break;
//         }
//       }
//       if (check == true)
//         return i; // vi tri tim thay dau tien
//     }
//   }
//   return -1;
// }


// Ham to mau
void textcolor(int x) {
  HANDLE mau;
  mau = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(mau, x);
}

// tra ve vi tri tim thay
void STRSTR(char *s, char *key) {
  int arr[100];
  int idx = 0;
  int length_s = STRLEN(s);
  int length_key = STRLEN(key);

  // duyet chuoi dang chua chuoi can tim
  for (int i = 0; i < length_s; i++) {
    if (s[i] == key[0]) {
      int k = 1;
      int check = true;
      for (int j = i + 1; j < length_key; j++) {
        if (s[j] != key[k++]) {
          check = false;
          break;
        }
      }
      if (check == true) {
        // return i; // vi tri tim thay dau tien
        // i la start, i + length_ley - 1 la end
        // cout << "\nstart = " << i << " & end = " << i + length_key - 1;
        arr[idx++] = i;
      }
    }
  }
  idx = 0;
  // duyet lai chuoi ban dau
  for (int i = 0; i < length_s; i++) {
    // bat dau
    if (i == arr[idx]) {
      textcolor(14); // bat mau vang
    }
    // ket thuc
    if (i == arr[idx] + length_key) { // chuyen sang vi tri tiep theo
      textcolor(7); // bat mau trang
      idx++;
    }
    cout << s[i];
  }
}


int main() {
  char s1[] = "Thang dep trai hao hoa lang tu dep trai hihi dep trai";
  char key[] = "dep trai";

  // int vitri = STRSTR(s1, key);
  // if (vitri == -1)
  //   cout << "\nKhong tim thay key";
  // else
  //   cout << "\nTim thay tai vi tri " << vitri;

  STRSTR(s1, key);


  cout << endl;
  return 0;
}