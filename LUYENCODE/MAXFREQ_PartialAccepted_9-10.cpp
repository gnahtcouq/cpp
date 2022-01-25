#include <iostream>
#include <algorithm>
using namespace std;

int kiemTraBiTrung(int a[], int n, int vitridangxet) {
  for (int i = vitridangxet - 1; i >= 0; i--)
    if (a[i] == a[vitridangxet])
      return 1; // da bi trung
  return 0; // khong trung
}
// Ham tu vi tri hien tai xet lui xuong (ve cuoi mang) de dem xem phan tu do xuat hien bao nhieu lan?
int demSoLanXuatHien(int a[], int n, int vitridangxet) {
  int dem = 1; // do tinh luon vi tri dang xet
  for (int i = vitridangxet + 1; i < n; i++)
    if (a[i] == a[vitridangxet])
      dem++;
  return dem;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a[100000], b[100000], n, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    // i la vi tri dang xet
    int kiemtratrung = kiemTraBiTrung(a, n, i);
    if (kiemtratrung == 1)
      continue;
    // xuong duoi nay tuc la khong tri trung => xet qua phai
    int dem = demSoLanXuatHien(a, n, i);
    b[m++] = a[i];
    b[m++] = dem;
  }

  int max = b[1];
  for (int i = 0; i < m; i++)
    if (i % 2 != 0)
      if (b[i] > max)
        max = b[i];

  for (int i = 0; i < m; i++)
    if (i % 2 != 0)
      if (max == b[i]) {
        cout << b[i - 1] << " " << b[i];
        break;
      }

  return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.first > b.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n;
    vector<int> a;
    unordered_map<int, int>m;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (!m[t])
            a.push_back(t);
        m[t]++;
    }
    vector<pair<int, int>> f;
    for(int x : a) {
        f.push_back({m[x], x});
    }
    sort(f.begin(), f.end(), cmp);
    cout << f[0].second<<" " << f[0].first;
    return 0;
}


*/