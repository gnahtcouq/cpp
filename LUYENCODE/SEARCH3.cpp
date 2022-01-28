#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
  int value;
  int index;
};

/* Hàm bổ trợ cho hàm sort để biết 2 thành phần trong mảng so sánh với nhau dựa theo thuộc tính value và đang đi sắp xếp tăng dần */

bool cmp(const Data& a, const Data& b) {
  return a.value < b.value;
}

int main() {
  /* int n, m;
  cin >> n >> m;
  int a[100000];
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  while (m--) {
    int x;
    cin >> x;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == x) {
        idx = i + 1;
        break;
      }
    }
    cout << idx << " ";
  } */

  int n, m;
  cin >> n >> m;
  Data a[100000];
  for (int i = 0; i < n; ++i) {
    cin >> a[i].value;
    a[i].index = i + 1;
  }
  /* Sắp xếp mảng tăng dần theo thuộc tính value nhờ vào hàm sort có sẵn trong STL có độ phức tạp tối ưu O(N * logN) */
  sort(a, a + n, cmp);
  /* Quá trình xử lý lọc ra các phần tử phân biệt đưa vào chính mảng a hiện tại mà không cần mảng phụ nhờ kỹ thuật 2 con trỏ (two pointer) */
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i].value != a[cnt - 1].value) {
      cnt++;
      a[cnt - 1] = a[i];
    }
    else {
      if (a[i].index < a[cnt - 1].index)
        a[cnt - 1].index = a[i].index;
    }
  }
  /* Phải nhớ cập nhật lại số lượng phần tử phân biệt */
  n = cnt;
  /* Quá trình tìm kiếm nhị phân */
  while (m--) {
    int x;
    cin >> x;
    int idx = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (a[mid].value < x)
        left = mid + 1;
      else if (a[mid].value > x)
        right = mid - 1;
      else {
        idx = a[mid].index;
        break;
      }
    }
    cout << idx << " ";
  }

  return 0;
}

/*
Ở quá trình đi tìm kiếm nhị phân ta tự cài đặt ở trên, bản chất trong STL cũng có hàm binary_search hỗ trợ tìm kiếm nhị phân tuy nhiên hàm này chỉ cho ta biết là có tìm thấy hay không còn ở đây ta muốn là nếu tìm thấy sẽ trả về vị trí index tìm thấy để từ đó ta gọi đến phần tử đó mà lấy ra giá trị index nó đang lưu trữ, vậy nên ta không áp dụng hàm đó được. Tuy nhiên nếu muốn lấy được vị trí index thì ta có 2 hàm lower_bound, upper_bound sẽ làm được điều này, các bạn có thể Google search tìm hiểu thêm về 2 hàm này nhé. Ví dụ mình làm mẫu nếu áp dụng hàm upper_bound thì sẽ thế này:
*/

/*
int main() {
  int n, m;
  cin >> n >> m;
  Data a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i].value;
    a[i].index = i + 1;
  }

  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i].value != a[cnt - 1].value) {
      cnt++;
      a[cnt - 1] = a[i];
    }
    else {
      if (a[i].index < a[cnt - 1].index) {
        a[cnt - 1].index = a[i].index;
      }
    }
  }

  n = cnt;
  while (m--) {
    Data x;
    cin >> x.value;
    int upper = upper_bound(a, a + n, x, cmp) - a;
    if (a[upper - 1].value != x.value) {
      cout << "0 ";
    }
    else {
      cout << a[upper - 1].index << " ";
    }
  }
  return 0;
} */

/*
Thì cấu trúc map bản chất nó cũng là cặp <key, value> nên bản thân nó đã là giải pháp để giải quyết vấn đề key chính là giá trị a[j] còn vale chính là vị trí index j ban đầu của nó. Và nó là cấu trúc cây đỏ đen nên bạn nào học sẽ biết là nó không lưu trữ trùng giá trị vì thế mặc định ban đầu value tại key tương ứng mang giá trị 0 thì ta xét nếu truyền key đó vào map mà giá trị value tại đó là 0 nghĩa là key đó chưa được đư vào thì ta sẽ đưa key đó vào và cập nhật value lại còn nếu value tại đó khác 0 nghĩa là key đó đ có trước đó nên ta không đưa vào. Sau cùng thì map lưu trữ các giá trị phân biệt (các key) và value của từng key chính là vị trí index ủa nó trong dãy ban đầu. Và khi tìm kiếm trên cấu trúc map thì độ phức tạp của nó là log(N) vì bản thân dữ liệu khi đưa vào nó là đã được sắp xếp và cân bằng cây nên các bước tìm kiếm sẽ rất khoẻ. Nói chung là dùng map thì độ phức tạp vẫn y như cách 2 nhưng bản thân trong cấu trúc của nó đã làm luôn cho ta bước sắp xếp và lọc trùng mà ta không phải mất công tự cài đặt, sẽ làm cho code được gọn hơn nhiều.
Source code để các bạn tham khảo thấy rõ những gì mình p hân tích ở trên:
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> a;
  int x;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (a[x] == 0) {
      a[x] = i;
    }
  }
  while (m--) {
    cin >> x;
    cout << a[x] << " ";
  }
  return 0;
} */