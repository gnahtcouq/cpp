#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      vec.push_back(a);
    }

    vector<int> vec1;
    for (int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      vec1.push_back(b);
    }

    for (int i = 0; i < n; ++i)
      if (vec1[i] > vec[i])
        swap(vec[i], vec1[i]);

    int max1 = *max_element(vec.begin(), vec.end());
    int max2 = *max_element(vec1.begin(), vec1.end());

    cout << max1 * max2 << endl;
  }

  return 0;
}