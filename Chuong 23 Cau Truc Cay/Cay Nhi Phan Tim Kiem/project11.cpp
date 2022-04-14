#include <iostream>
using namespace std;

/* ----- 1/ Khai báo cấu trúc dữ liệu cây nhị phân tìm kiếm ----- */
struct Node {
  int data; // cây nhị phân tìm kiếm chứa các số nguyên
  Node* left, * right; // trỏ tới các Node là cây con trái và cây con phải
};
typedef struct Node NODE;
// typedef NODE* Tree; // Tree t; -> t là 1 Node (NODE *)

/* ----- 2/ Khởi tạo cây ----- */
void init(NODE*& root) {
  root = NULL;
}

/* ----- 3/ Tạo Node ----- */
// Tạo 1 Node mới chứa dữ liệu x và trả về địa chỉ của Node đó sau khi tạo xong
NODE* getNode(int x) { // x là dữ liệu mà sẽ đưa nó vào trong Node
  NODE* p = new NODE;
  if (p == NULL)
    return NULL; // Không tạo thành công do thiếu vùng nhớ để cấp phát tạo ra Node

  // Nếu vẫn còn chạy được xuống đây tức là không thỏa cái if -> Node được tạo thành công
  p->data = x; // đưa dữ liệu x vào trong Node p
  p->left = p->right = NULL; // cập nhật con trỏ left, right là NULL
  return p; // trả về Node p đã được tạo
}

void themNodeVaoCay_DeQuy(NODE*& root, int x) { // thêm giá trị x vào cây
  if (root != NULL) {
    // Điều kiện đệ quy
    if (x > root->data)
      themNodeVaoCay_DeQuy(root->right, x);
    else if (x < root->data)
      themNodeVaoCay_DeQuy(root->left, x);
  }
  else // root == NULL
    root = getNode(x); // Dừng đệ quy -> Tạo Node chứa giá trị cần thêm vào
}

void taoCayTuDaySo(NODE*& root, int a[], int n) { // dãy số chứa trong mảng a và có n là số lượng phận tử của dãy
  init(root); // khởi tạo ra cây rồi từ đó mới có thể thêm các node vào trong cây
  for (int i = 0; i < n; ++i) // vòng lặp duyệt qua danh sách dãy số chứa trong mảng a để từ đó thêm vào cây
    themNodeVaoCay_DeQuy(root, a[i]);
}

void NLR(NODE* root) {
  if (root != NULL) {
    cout << " " << root->data;
    NLR(root->left);
    NLR(root->right);
  }
}

void LNR(NODE* root) {
  if (root != NULL) {
    LNR(root->left);
    cout << " " << root->data;
    LNR(root->right);
  }
}

void RNL(NODE* root) {
  if (root != NULL) {
    RNL(root->right);
    cout << " " << root->data;
    RNL(root->left);
  }
}

void LRN(NODE* root) {
  if (root != NULL) {
    LRN(root->left);
    LRN(root->right);
    cout << " " << root->data;
  }
}

// Tìm giá trị x xem có tồn tại ở node nào đó trong cây không? Nếu có thì trả về node đó, nếu không có thì trả về NULL
NODE* timKiemNode_DeQuy(NODE* root, int x) {
  // Điều kiện dừng khi không tìm thấy
  if (root == NULL)
    return NULL;
  // Điều kiện đệ quy
  // if (root != NULL) { // Cũng không cần viết điều kiện này bởi vì chúng ta đã xét nếu Root == NULL ở đầu tiên của hàm nên nếu nó còn chạy được xuống dưới này tức là root != NULL
  if (x > root->data)
    return timKiemNode_DeQuy(root->right, x);
  else if (x < root->data)
    return timKiemNode_DeQuy(root->left, x);
  else // x == root->data
    return root; // Điều kiện dừng khi đã tìm thấy
  // }
}

// p là Node thế mạng sẽ xóa
void timPhanTuTheMang_DeQuy(NODE*& root, NODE*& p) {
  if (root->right != NULL)
    timPhanTuTheMang_DeQuy(root->right, p);
  else { // Lúc này root->right == NULL -> root là Node phải nhất -> đó là Node thế mạng
    p->data = root->data; // Gán giá trị của Node thế mạng (root) sang giá trị của Node cần xóa (p)
    p = root; // Cho con trỏ p trỏ tới Node thế mạng (root) để kết thúc hàm thì sẽ delete p; chính là delete root;
    root = root->left; // Mục đích: Giữ liên kết với các Node con của Node bị xóa. Vì root đang là Node phải nhất -> sẽ không có con phải. Chỉ có thể có con trái hoặc không có con -> cứ cho trỏ tới con trái
  }
}

// Tìm phần tử thế mạng trái nhất của cây con phải
void timPhanTuTheMang_DeQuy_2(NODE*& root, NODE*& p) {
  if (root->left != NULL)
    timPhanTuTheMang_DeQuy(root->left, p);
  else {
    p->data = root->data;
    p = root;
    root = root->right;
  }
}

void xoaNodeTrongCay_DeQuy(NODE*& root, int x) { // x là giá trị cần xóa ra khỏi cây
  // Điều kiện dừng
  if (root == NULL)
    return; // Kết thúc vì cây không có gì để xóa hoặc không tìm thấy Node cần xóa (giá trị cần xóa x không tồn tại trong cây)

    // Bước đệ quy
  if (x > root->data)
    xoaNodeTrongCay_DeQuy(root->right, x);
  else if (x < root->data)
    xoaNodeTrongCay_DeQuy(root->left, x);
  else { // Tìm thấy x trong cây tại Node root -> xóa
    NODE* p = root; // p là Node sẽ bị xóa
    // TH1: Node cần xóa là Node lá
    // TH2: Node cần xóa là Node có 1 con

    // Giữ liên kết với phần còn lại của Node bị xóa
    if (p->left == NULL)
      root = p->right;
    else if (p->right == NULL)
      root = p->left;
    else { // p->left != NULL && p->right != NULL -> TH3: Node cần xóa là Node có đủ 2 con
      timPhanTuTheMang_DeQuy(root->left, p);
    }


    // // Viết đầy đủ thì sẽ thế này
    // if (p->left == NULL && p->right == NULL) // TH1: Node cần xóa là Node lá
    //   root = NULL;
    // else if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL)) { // TH2: Node cần xóa là Node có 1 con
    //   if (p->left == NULL)
    //     root = p->right;
    //   else
    //     root->left;
    // }
    // else { // TH3: Node cần xóa là Node có đủ 2 con
    //   timPhanTuTheMang_DeQuy(root->left, p);
    // }


    delete p; // giải phóng p
  }
}

void xoaNodeTrongCay_DeQuy_2(NODE*& root, int x) {
  if (root == NULL)
    return;
  if (x > root->data)
    xoaNodeTrongCay_DeQuy_2(root->right, x);
  else if (x < root->data)
    xoaNodeTrongCay_DeQuy_2(root->left, x);
  else {
    NODE* p = root;
    if (p->left == NULL)
      root = p->right;
    else if (p->right == NULL)
      root = p->left;
    else
      timPhanTuTheMang_DeQuy_2(root->right, p);
    delete p;
  }
}

void taoCayNhapTuBanPhimBietTruocSoLuong(NODE*& root, int& n) {
  init(root); // Phải nhớ khởi tạo cho cây để tránh bị lỗi
  do {
    cout << "\nNhap vao so luong Node cua cay: ";
    cin >> n;
    if (n < 0)
      cout << "\nSo luong phai la so duong. Xin kiem tra lai";
  } while (n < 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cout << "\nNhap vao gia tri cua Node thu " << i << ": ";
    cin >> x;
    themNodeVaoCay_DeQuy(root, x);
  }
}

// Ví dụ như gặp số âm là dừng lại
void TaoCayNhapTuBanPhimKhongBietTruocSoLuong(NODE*& root) {
  init(root);
  int i = 1;
  while (true) { // lặp vô tận đến khi nào gặp điều kiện dừng thì dừng lại
    int x;
    cout << "\nNhap vao gia tri cua Node thu (nhap so am de ket thuc) " << i++ << ": ";
    cin >> x;
    if (x < 0)
      break; // thoát khỏi vòng lặp -> dừng lại
    themNodeVaoCay_DeQuy(root, x);
  }
}

int main() {
  int a[] = { 40,5,35,45,15,56,35,35,35,48,13,16,49,47 };
  // int a[] = { 50,100,30,20,40,35,37,45 };
  int n = sizeof(a) / sizeof(a[0]);
  cout << "\nSo luong phan tu cua mang = " << n;

  NODE* root;
  // taoCayTuDaySo(root, a, n);
  taoCayNhapTuBanPhimBietTruocSoLuong(root, n);

  // cout << "\nNLR: ";
  // NLR(root);
  cout << "\nLNR: ";
  LNR(root);
  // cout << "\nRNL: ";
  // RNL(root);
  // cout << "\nLRN: ";
  // LRN(root);

  // int x = 17;
  // NODE* p = timKiemNode_DeQuy(root, x);
  // if (p == NULL)
  //   cout << "\nKhong tim thay Node trong cay co gia tri la " << x;
  // else
  //   cout << "\nDa tim thay Node trong cay co gia tri la " << x;

  // int y = 48;
  // cout << "\nXoa node co gia tri la: " << y;
  // xoaNodeTrongCay_DeQuy(root, y);
  // cout << "\nLNR: ";
  // LNR(root);

  int z = 5;
  cout << "\nXoa node co gia tri la: " << z;
  xoaNodeTrongCay_DeQuy(root, z);
  cout << "\nLNR: ";
  LNR(root);

  return 0;
}