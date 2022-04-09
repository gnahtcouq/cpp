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
    if (x > root->data)
      themNodeVaoCay_DeQuy(root->right, x);
    else if (x < root->data)
      themNodeVaoCay_DeQuy(root->left, x);
  }
  else // root == NULL
    root = getNode(x);
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

int main() {
  int a[] = { 40,5,35,45,15,56,48,13,16,49,47 };
  int n = sizeof(a) / sizeof(a[0]);
  cout << "\nSo luong phan tu cua mang = " << n;

  NODE* root;
  taoCayTuDaySo(root, a, n);

  cout << "\nNLR: ";
  NLR(root);
  cout << "\nLNR: ";
  LNR(root);
  cout << "\nRNL: ";
  RNL(root);
  cout << "\nLRN: ";
  LRN(root);

  return 0;
}