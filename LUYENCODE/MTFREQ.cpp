// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//   int a[100000], b[100000], n;
//   cin >> n;
//   for (int i = 0; i < n; i++)
//     cin >> a[i];

//   b[0] = a[0];
//   int x = 1;
//   for (int i = 1; i < n; i++) {
//     int dem = 0;
//     for (int j = 0; j < x; j++)
//       if (a[i] == a[j])
//         dem++;
//     if (dem == 0)
//       b[x++] = a[i];
//   }
//   cout << x << endl;
//   for (int j = 0; j < x; j++) {
//     int dem = 0;
//     for (int i = 0; i < n; i++)
//       if (a[i] == b[j])
//         dem++;
//     cout << b[j] << " " << dem << endl;
//   }

//   return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
  int n, x;
  std::cin >> n;
  std::vector<long long> v(n);
  std::unordered_map<long long, int> freg;

  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    freg[v[i]]++;
  }
  std::cout << freg.size() << "\n";
  for (int i = 0; i < n; i++) {
    if (freg[v[i]] != 0) {
      std::cout << v[i] << " " << freg[v[i]] << "\n";
      freg.erase(v[i]);
    }
  }

  return 0;
}