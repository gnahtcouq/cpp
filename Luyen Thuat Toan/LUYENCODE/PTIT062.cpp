#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> s;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    if (s.size() < 3)
      cout << "Khong the tim duoc!\n";
    else {
      set<int>::iterator it1 = s.begin();
      advance(it1, s.size() - 3);
      vector<int>::iterator it2 = find(a.begin(), a.end(), *it1);
      cout << *it1 << " " << (it2 - a.begin() + 1) << "\n";
    }
  }

  return 0;
}