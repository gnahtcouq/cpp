

//         // TONG HOP

// // Bai 741: s(n) = x + x^2 + x^3 + ... x^n

// float deQuy(float x, int n) {
//   if (n == 1)
//     return x;
//   return deQuy(x, n - 1) + pow(x, n);
// }

// float deQuyDuoi(float x, int n, float y = 0) {
//   if (n == 0)
//     return y;
//   return deQuyDuoi(x, n - 1, y + pow(x, n));
// }

// float khuDeQuy(float x, int n) {
//   float tong = x;
//   for(int i = 2; i <= n; i++) {
//     tong += pow(x, i);
//   }
//   return tong;
// }

// // Bai 744: s(n) = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n)

// float deQuy(int n) {
//   if (n == 1)
//     return 1;
//   float tong = 1;
//   for(int i = 2; i <= n; i++) {
//     tong += i;
//   }
//   return deQuy(n - 1) + 1;
// }

// float deQuyDuoi(int n, float y = 1) {
//   if (n == 1)
//     return y;
//   float tong = 1;
//   for(int i = 2; i <= n; i++) {
//     tong += i;
//   }
//   return deQuyDuoi(n - 1, y + 1.0 / tong);
// }

// float khuDeQuy(int n) {
//   float tong = 1;
//   for(int i = 2; i <= n; i++) {
//     float tong2 = 1;
//     for(int j = 2; j <= i; j++) {
//       tong2 += j;
//     }
//     tong += 1.0 / tong2;
//   }
//   return tong;
// }

// // Bai 747: Tim uoc so le lon nhat cua so nguyen duong n.
// // Vi du n = 100 uoc le lon nhat cua 100 la 25

// int deQuy(int n) {
//   if (n % 2 != 0)
//     return n;
//   return deQuy(n / 2); // Vi no khong bao gio chia het cho 1 so nam trong doan tu n/2 + 1 cho toi n - 1 => ta khong xet
// }

// // Bai 748:
// #include <math.h>
// float deQuy(int n) {
//   if (n == 1)
//     return sqrt(2.0);
//   return sqrt(2 + deQuy(n - 1));
// }

// float deQuyDuoi(int n, float x = sqrt(2.0)) {
//   if (n == 1)
//     return x;
//   return deQuyDuoi(n - 1, x + sqrt(2.0 + x));
// }

// // Bai 751:

// float deQuy(int n) {
//   if (n == 1)
//     return 0.5;
//   return 1.0 / (1 + deQuy(n - 1));
// }

// float deQuyDuoi(int n, float x = 0.5) {
//   if (n == 1)
//     return x;
//   return deQuyDuoi(n - 1, 1.0 / (1 + x));
// }

// float khuDeQuy(int n) {
//   float tong = 0.5;
//   for(int i = 2; i <= n; i++) {
//     tong = 1.0 / (1 + tong);
//   }
//   return tong;
// }

// // Bai 752: Hay dem so luong chu so cua 1 so nguyen duong n

// int deQuy(int n) {
//   if (n == 0)
//     return 0;
//   return deQuy(n / 10) + 1;
// }

// int deQuyDuoi(int n, int x = 0) {
//   if (n == 0)
//     return x;
//   return deQuyDuoi(n / 10, x + 1);
// }

// int khuDeQuy(int n) {
//   int dem = 0;
//   while(n != 0) {
//     n /= 10;
//     dem++;
//   }
//   return dem;
// }

// // Bai 753: Hay tinh tong cac chu so cua so nguyen duong n

// int deQuy(int n) {
//   if(n == 0)
//     return 0;
//   return deQuy(n / 10) + n % 10;
// }

// int deQuyDuoi(int n, int x = 0) {
//   if(n == 0)
//     return x;
//   return deQuyDuoi(n / 10, x + n % 10);
// }

// int khuDeQuy(int n) {
//   int tong = 0;
//   while(n != 0) {
//     tong += n%10;
//     n /= 10;
//   }
//   return tong;
// }

// // Bai 758: Hay tim chu so dau tien cua n

// int deQuy(int n) {
//   if(n < 10)
//     return n;
//   return deQuy(n / 10);
// }

// // Bai 759: Hay tim chu so dao nguoc cua so nguyen duong n

// int tong = 0;
// int deQuy(int n) {
//   if(n == 0)
//     return 0;
//     tong = tong * 10 + n % 10;
//   return deQuy(n / 10);
// }

// int deQuyDuoi(int n, float tong = 0) {
//   if(n == 0)
//     return tong;
//   return deQuyDuoi(n / 10, tong * 10 + n % 10);
// }

// int khuDeQuy(int n) {
//   int tong = 0;
//   while(n != 0) {
//     tong = tong * 10 + n % 10;
//     n /= 10;
//   }
//   return tong;
// }

// // Bai 760: Tim chu so lon nhat

// int deQuyDuoi(int n, int max = 0) {
//   if(n == 0)
//     return max;
//   return deQuyDuoi(n / 10, Max > n % 10 ? MAX : n % 10);
// }

// int khuDeQuy(int n) {
//   int max = 0;
//   while(n != 0) {
//     int chuso = n % 10;
//     n /= 10;
//     if(chuso > max)
//       max = chuso;
//   }
//   return max;
// }

// // Bai 762: Kiem tra toan chu so le

// bool deQuy(int n) {
//   if(n == 0)
//     return true; // toan le
//   if((n%10) % 2 == 0)
//     return false; // sai do da phat hien ra co 1 chu so chan
//   return deQuy(n / 10); // bo di 1 chu so
// }

