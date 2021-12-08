#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char ten[] = "Thang Dep Trai Ooo"; //14

  int length = strlen(ten);
  cout << "Chuoi dai " << length << " ki tu" << endl;

  int dem = 0;
  for(int i = 0; i < length; i++) {
    // cout << "\nten[" << i << "] = " << ten[i];
    if (ten[i] == 'o')
      dem++;
  }
  cout << "\nSo ky tu 'o' la: " << dem;

  char ten2[30]; 
  // char ten2[7]; // neu do lon khong du chua -> loi tran bo nho
  // ten2 = ten; // gan ten sang ten2 -> sai
  strcpy(ten2, ten); // -> phai xac dinh truoc kinh thuoc
  cout << "\nten2 = " << ten2;

  char *ten3 = strdup(ten); // -> tao vua du
  cout << "\nten3 = " << ten3;

  strlwr(ten3);
  cout << "\nten3 = " << ten3;
  
  strupr(ten3);
  cout << "\nten3 = " << ten3;

  // "abc" -> "cba"
  strrev(ten3);
  cout << "\nten3 = " << ten3;

  // char s1[] = "thang";
  // char s2[] = "thua";

  // char s1[] = "thang";
  // char s2[] = "thangdeptrai";

  // char s1[] = "thange";
  // char s2[] = "thangdeptrai";

  char s1[] = "thangdeptrai";
  char s2[] = "thangDeptrai";
  int ketqua = strcmp(s1, s2);
  cout << "\nketqua = " << ketqua;
  ketqua = stricmp(s1, s2);
  cout << "\nketqua = " << ketqua;

  char ten4[30] = "thang";
  char ten5[30] = " dep trai";
  strcat(ten4, ten5);
  cout << "\nten4 = " << ten4;

  // strstr() -> kiemtra xem chuoi nay co nam trong chuoi kia hay khong
  char tenSach[100] = "day con lam giau";
  char timKiem[] = "lam giau";
  if (strstr(tenSach, timKiem))
    cout << "\nTim thay";
  else
    cout << "\nKhong tim thay";

  cout << endl;
  return 0;
}