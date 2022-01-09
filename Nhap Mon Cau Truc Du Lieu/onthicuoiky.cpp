#include <iostream>
using namespace std;

// // Câu 2
// const int MAX = 50;       // Chiều dài tối đa của danh sách đặc là 50
// struct DAYSO {
//   int n;                  // Số phần tử trong danh sách
//   int ds[MAX];
// };
//
//
//
// // Câu 9
// struct DAYSO {
//   int n;
//   int ds[20];
// };

// int timNhiPhan(DAYSO x, int a) {
//   int bottom = 0, top = x.n - 1; int mid;
//   do {
//     mid = (bottom + top) / 2;
//     if (x.ds[mid] == a) return mid;
//     else if (a < x.ds[mid])
//       top = mid - 1; // (1)
//     else
//       bottom = mid + 1; // (2)
//   } while (bottom <= top);
//   return -1;
// }
//
//
//
// // Câu 10
// struct DAYSO {
//   int n;
//   int ds[20];
// };

// int F(DAYSO x, int a) {
//   int vt = -1;
//   for (int i = 0; i < x.n; i++)
//     if (x.ds[i] == a) vt = i;
//   return vt;
// }
//
//
//
// // Câu 12
// typedef int TYPEDATA;
// struct NODE {
//   TYPEDATA data;
//   NODE* link;
// };
// typedef NODE* NODEPTR;
// NODEPTR taoNode(TYPEDATA a);

// void themDau(NODEPTR& list, TYPEDATA a) {
//   NODEPTR p = taoNode(a);
//   p->link = list;
//   list = p;
// }
//
//
//
// Câu 13
typedef int TYPEDATA;
struct NODE {
  TYPEDATA data;
  NODE* link;
};
typedef NODE* NODEPTR;

void khoiTao(NODEPTR& list) {
  list = NULL;
}
int isEmpty(NODEPTR list) {
  return (list == NULL ? 1 : 0);
}
NODEPTR tao_Node(TYPEDATA x) {
  NODEPTR p;
  p = new NODE;
  p->data = x;
  p->link = NULL;
  return p;
}

NODEPTR them_Cuoi(NODEPTR& list, TYPEDATA x) {
  NODEPTR p;
  p = tao_Node(x);
  if (list == NULL)
    list = p;
  else {
    NODEPTR q = list;
    while (q->link != NULL)
      q = q->link;
    q->link = p;
  }
  return p;
}

void nhap_DanhSach(NODEPTR& list) {
  khoiTao(list);
  int x;
  do {
    cout << "\n Nhap vao x = (thoat -99) ";
    cin >> x;
    if (x == -99)
      break;
    them_Cuoi(list, x);
  } while (1);
}
void xuat_DanhSach(NODEPTR list) {
  NODEPTR p = list;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

NODEPTR timPhanTuCuoi_A(NODEPTR list) {
  NODEPTR q = list;
  while (q != NULL && q->link != NULL) q = q->link;
  return q;
}

NODEPTR timPhanTuCuoi_D(NODEPTR list) {
  NODEPTR q = list;
  while (q->link != NULL) q = q->link;
  return q;
}

NODEPTR timMax(NODEPTR list) {
  NODEPTR p = list, max = list;
  while (p != NULL) {
    if (p->data > max->data)
      max->data = p->data;
    p = p->link;
  }
  return p;
}

int timViTri(NODEPTR list, TYPEDATA a) {
  int vt = -1;
  NODEPTR p = list;
  while (p != NULL) {
    vt++;
    if (p->data == a) break;
    p = p->link;
  }
  return vt;
}

void F(NODEPTR& list) {
  if (list != NULL) {
    NODEPTR p = list;
    list = list->link;
    delete p;
  }
}

struct QUEUE {
  NODEPTR front;
  NODEPTR rear;
};

void init_Queue(QUEUE &q) {
  q.front = NULL;
  q.rear = NULL;
}

int isEmpty_Queue(QUEUE q) {
  if (q.front == NULL)
    return 1;
  return 0;
}

NODEPTR taoNode_Queue(int x) {
  NODEPTR p;
  p = new NODE;
  p->data = x;
  p->link = NULL;
  return p;
}

void enQueue(QUEUE &q, int x) {
  NODEPTR p;
  p = taoNode_Queue(x);
  if (isEmpty_Queue(q)) {
    q.front = p;
    q.rear = p;
  }
  else {
    q.rear->link = p;
    q.rear = p;
  }
}

void setValue_Queue(QUEUE &q) {
  int x;
  while (1) {
    cout << "Nhap gia tri cho Queue (nhap -99 de dung): ";
    cin >> x;
    if (x == -99)
      break;
    enQueue(q, x);
  }
}

void print_Queue(QUEUE q) {
  NODEPTR p;
  p = q.front;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->link;
  }
}

int deQueue(QUEUE &q) {
  if (isEmpty_Queue(q))
    return -1;
  else {
    NODEPTR p = q.front;
    q.front = p->link;
    int t = p->data;
    delete p;
    return t;
  }
}

int K(QUEUE q, TYPEDATA& a) {
  if (!isEmpty_Queue(q)) {
    a = q.front->data;
    return 1;
  }
  return 0;
}

int main() {

  // Câu 1
  // Danh sách đặc là danh sách 
  // A. Các phần tử được lưu trữ kề nhau trong bộ nhớ
  //
  //
  //
  // Câu 2
  // C.
  //
  //
  //
  // Câu 3
  // Trong phép toán chèn 1 phần tử vào danh sách, vị trí chèn pos nào sau đây là hợp lệ
  // if (pos < 0 || pos > n)
  //   cout << "\n Vi tri khong hop le";
  // D. 0 < pos < n
  //
  //
  //
  // Câu 4
  // Trong phép toán loại bỏ 1 phần tử khỏi danh sách, vị trí pos nào sau đây là hợp lệ
  // if (pos < 0 || pos > n)
  //   cout << "\n Vi tri khong hop le";
  // D. 0 < pos < n
  //
  //
  //
  // Câu 5
  // Đối với thuật toán tìm kiếm nhị phân
  // Danh sách phải có thứ tự tăng dần (hoặc giảm dần)
  // A. Danh sách phải có thứ tự
  //
  //
  //
  // Câu 6
  // Đối với thuật toán tìm kiếm tuần tự
  // A. Danh sách không cần có thứ tự
  //
  //
  //
  // Câu 7
  // Các bước để chèn 1 phần tử a vào danh sách đặc tại vị trí pos là
  // A.
  // -- Kiểm tra danh sách còn chỗ và pos hợp lệ
  // -- Dịch các phần tử từ vị trí pos đên cuối danh sách sang phải 1 ô
  // -- Chèn a vào vị trí pos
  // -- Tăng độ dài danh sách lên 1
  //
  //
  //
  // Câu 8
  // Các bước để loại bỏ 1 phần tử khỏi danh sách đặc tại vị trí pos là
  // A.
  // -- Kiểm tra pos hợp lệ
  // -- Dịch các phần tử từ vị trí pos+1 đến cuối danh sách sang trái 1 ô
  // -- Giảm độ dài danh sách xuống 1.
  //
  //
  //
  // Câu 9
  // B.
  //
  //
  // Câu 10
  // A. Hàm tìm kiếm tuần tự trả về vị trí xuất hiện sau cùng của phần tử a nếu tìm thấy, trả về -1 nếu không tìm thấy.
  //
  //
  //
  // Câu 11
  // Danh sách liên kết là danh sách mà các phần tử
  // A. Có ít nhất 2 thành phần: dữ liệu, phần liên kết
  //
  //
  //
  // Câu 12
  // A.
  //
  //
  //
  // Câu 13
  // A hoặc D (chưa rõ)
  //
  //
  //
  // Câu 14
  // C.
  //
  //
  //
  // Câu 15
  // Để xóa 1 phần tử (không phải phần tử đầu) trong danh sách liên kết đơn, ta phải tìm
  // A. Phần tử đứng trước nó.
  //
  //
  // Câu 16
  // Phần liên kết của phần tử cuối trong danh sách liên kết vòng
  // A. Trỏ đến phần tử đầu.
  //
  //
  //
  // Câu 17
  // Cấu trúc một node của danh sách liên kết kép gồm
  // A. Phần dữ liệu, phần liên kết phần tử kề trước, phần liên kết phần tử kề sau.
  //
  //
  //
  // Câu 18
  // Cho cấu trúc danh sách liên kết kép như sau, Code cho hàm duyetToi là:
  // A.
  //
  //
  //
  // Câu 19
  // Cho cấu trúc danh sách liên kết kép như sau, Code cho hàm duyetLui là:
  // A.
  //
  //
  //
  // Câu 20
  // Cho cấu trúc danh sách liên kết kép như sau, Code cho hàm khoiTao là:
  // A.
  //
  //
  // Câu 21
  // Phép toán POP dùng trong stack để:
  // A. Lấy phần tử tại đỉnh ra khỏi stack.
  //
  //
  //
  // Câu 22
  // Phép toán PUSH dùng trong stack để:
  // A. Thêm một phần tử vào đỉnh stack.
  //
  //
  //
  // Câu 23
  // Stack là danh sách dạng
  // LIFO (Last in first out) // Vào sau ra trước
  //
  //
  //
  // Câu 24
  // Để lấy giá trị tại đỉnh của stack nhưng không loại bỏ phần tử ta dùng phép toán:
  // A. TOP
  //
  //
  //
  // Câu 25
  // Cho danh sách {1, 2, 4, 3, 11, 7, 8}, Top ở phần tử 8, sau khi thực hiện POP 3 lần,
  // stack còn lại là:
  // A. 1, 2, 4, 3
  //
  //
  //
  // Câu 26
  // Phép toán DeQueue dùng trong hàng đợi để:
  // A. Loại bỏ phần tử ở đầu hàng.
  //
  //
  //
  // Câu 27
  // Phép toán EnQueue dùng trong hàng đợi để:
  // A. Thêm một phần tử vào cuối hàng.
  //
  //
  //
  // Câu 28
  // Queue là danh sách dạng
  // A. FIFO (First in first out) // Vào trước ra trước
  //
  //
  //
  // Câu 29
  // Để lấy giá trị đầu hàng đợi nhưng không loại bỏ phần tử ta dùng phép toán:
  // A. FRONT
  //
  //
  //
  // Câu 30
  // Cho danh sách {1, 2, 5, 8}, Front ở phần tử 8, Rear ở phần tử 1, sau khi thực hiện
  // ENQUEUE(9) 2 lần, hàng có các phần tử là:
  // A. 9, 9, 1, 2, 5, 8
  //
  //
  //
  // Câu 31
  // A. (1) p = list; (2) list = list->link; (3) delete p;
  //
  //
  //
  // Câu 32
  // Cho cấu trúc danh sách liên kết đơn, và hàm tìm vị trí phần tử a
  // A. (1) vt++; (2) if (p->data == a) break; (3) p = p->link;
  //
  //
  //
  // Câu 33
  // Cho cấu trúc danh sách liên kết đơn, và hàm F
  // A. Hàm F dùng để xóa phần tử đầu danh sách
  //
  //
  // Câu 34
  // Cho cấu trúc Queue, và hàm K


  // NODEPTR list;
  // khoiTao(list);
  // nhap_DanhSach(list);
  // xuat_DanhSach(list);
  // cout << "\n\n\n";
  // F(list);
  // cout << "\n\n\n";
  // xuat_DanhSach(list);


  QUEUE q;
  init_Queue(q);
  setValue_Queue(q);
  print_Queue(q);
  int x = 2;
  K(q, x);
  cout << x;

  system("pause");
  return 0;
}