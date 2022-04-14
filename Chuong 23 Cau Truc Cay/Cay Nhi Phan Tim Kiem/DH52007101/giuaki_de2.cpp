#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node* left, * right;
};
typedef struct Node NODE;

struct Avl {
  int data, thuTuDuyet;
  struct Avl* left, * right;
  struct Avl* cha;
};
typedef struct Avl AVL;

void init(NODE*& root);
NODE* getNode(int x);
void themNodeVaoCay(NODE*& root, int x);
void NLR(NODE* root);
// void LNR(NODE* root);
// void LRN(NODE* root);
void timPhanTuTheMang(NODE*& root, NODE*& p);
void xoaNodeTrongCay(NODE*& root, int x);
NODE* timKiemNode(NODE* root, int x);
int tinhChieuCaoCuaCay(NODE* root);
int tinhTongCacNutLe(NODE* root);
int kiemTraHoanThien(int x);
int demSoLuongSoHoanThien(NODE* root);

void init_AVL(AVL*& root);
AVL* getNode_AVL(int x);
void quayTrai_AVL_AVL(AVL*& root);
void quayPhai_AVL(AVL*& root);
int themNodeVaoCay_AVL(AVL*& root, int x);
int tinhChieuCaoCay_AVL(AVL* root);
int xetTinhCanBangVaCanBangLaiTai1Node_AVL(AVL*& root);
void NLR_AVL(AVL* root);

int main() {
  // Cau 1
  NODE* root;
  init(root);
  cout << "Cau 1.";
  int a[] = { 30,20,35,10,25,32,40,38,34,28,22,15,5,18 };
  int n = sizeof(a) / sizeof(a[0]);
  cout << "\na.";
  for (int i = 0; i < n; ++i)
    themNodeVaoCay(root, a[i]);
  cout << "\nb. NLR: ";
  NLR(root);
  xoaNodeTrongCay(root, 40);
  cout << "\nc. NLR: ";
  NLR(root);

  int chieuCaoCay = tinhChieuCaoCuaCay(root);
  cout << "\nf. Cay co chieu cao = " << chieuCaoCay;
  int tongNutLe = tinhTongCacNutLe(root);
  cout << "\ng. Tong cac nut le = " << tongNutLe;
  int demHoanThien = demSoLuongSoHoanThien(root);
  cout << "\nh. So luong so hoan thien = " << demHoanThien;


  // Cau 2
  AVL* rot;
  init_AVL(rot);
  cout << "\n\nCau 2.";
  int b[] = { 1,2,3,4,5,6,7,8,9 };
  int m = sizeof(b) / sizeof(b[0]);
  for (int i = 0; i < m; ++i)
    themNodeVaoCay_AVL(rot, b[i]);
  cout << "\nNLR: ";
  NLR_AVL(rot);


  return 0;
}

void init(NODE*& root) {
  root = NULL;
}

NODE* getNode(int x) {
  NODE* p = new NODE;
  if (p == NULL)
    return NULL;
  p->data = x;
  p->left = p->right = NULL;
  return p;
}

void themNodeVaoCay(NODE*& root, int x) {
  if (root != NULL) {
    if (x > root->data)
      themNodeVaoCay(root->right, x);
    else if (x < root->data)
      themNodeVaoCay(root->left, x);
  }
  else
    root = getNode(x);
}

void NLR(NODE* root) {
  if (root != NULL) {
    cout << " " << root->data;
    NLR(root->left);
    NLR(root->right);
  }
}

// void LNR(NODE* root) {
//   if (root != NULL) {
//     LNR(root->left);
//     cout << " " << root->data;
//     LNR(root->right);
//   }
// }

// void LRN(NODE* root) {
//   if (root != NULL) {
//     LRN(root->left);
//     LRN(root->right);
//     cout << " " << root->data;
//   }
// }

void timPhanTuTheMang(NODE*& root, NODE*& p) {
  if (root->right != NULL)
    timPhanTuTheMang(root->right, p);
  else {
    p->data = root->data;
    p = root;
    root = root->left;
  }
}

void xoaNodeTrongCay(NODE*& root, int x) {
  if (root == NULL)
    return;
  if (x > root->data)
    xoaNodeTrongCay(root->right, x);
  else if (x < root->data)
    xoaNodeTrongCay(root->left, x);
  else {
    NODE* p = root;
    if (p->left == NULL)
      root = p->right;
    else if (p->right == NULL)
      root = p->left;
    else
      timPhanTuTheMang(root->left, p);
    delete p;
  }
}

NODE* timKiemNode(NODE* root, int x) {
  if (root == NULL)
    return NULL;
  if (x > root->data)
    return timKiemNode(root->right, x);
  else if (x < root->data)
    return timKiemNode(root->left, x);
  else
    return root;
}

int tinhChieuCaoCuaCay(NODE* root) {
  if (root == NULL)
    return 0;
  int left = tinhChieuCaoCuaCay(root->left);
  int right = tinhChieuCaoCuaCay(root->right);

  return left > right ? left + 1 : right + 1;
}

int tinhTongCacNutLe(NODE* root) {
  queue<NODE*> q;
  if (root != NULL)
    q.push(root);
  int sum = 0;
  while (!q.empty()) {
    NODE* p = q.front();
    if (p->data % 2 != 0)
      sum += p->data;
    q.pop();
    if (p->left != NULL)
      q.push(p->left);
    if (p->right != NULL)
      q.push(p->right);
  }
  return sum;
}

int kiemTraHoanThien(int x) {
  int sum = 0;
  for (int i = 1; i <= x / 2; i++)
    if (x % i == 0)
      sum += i;
  return sum == x;
}

int demSoLuongSoHoanThien(NODE* root) {
  queue<NODE*> q;
  if (root != NULL)
    q.push(root);

  int count = 0;
  while (!q.empty()) {
    NODE* p = q.front();
    if (kiemTraHoanThien(p->data) == 1)
      count++;
    q.pop();
    if (p->left != NULL)
      q.push(p->left);
    if (p->right != NULL)
      q.push(p->right);
  }
  return count;
}

void init_AVL(AVL*& root) {
  root = NULL;
}

AVL* getNode_AVL(int x) {
  AVL* p = new AVL;
  if (p == NULL)
    return NULL;
  p->data = x;
  p->left = p->right = NULL;
  p->cha = NULL;
  p->thuTuDuyet = 0;
  return p;
}

void quayTrai_AVL(AVL*& root) {
  AVL* cha = root->cha;
  AVL* pivot = root->right;
  root->right = pivot->left;
  if (pivot->left != NULL)
    pivot->left->cha = root;
  pivot->left = root;
  root->cha = pivot;
  root = pivot;
  root->cha = cha;
}

void quayPhai_AVL(AVL*& root) {
  AVL* cha = root->cha;
  AVL* pivot = root->left;
  root->left = pivot->right;
  if (pivot->right != NULL)
    pivot->right->cha = root;
  pivot->right = root;
  root->cha = pivot;
  root = pivot;
  root->cha = cha;
}

int themNodeVaoCay_AVL(AVL*& root, int x) {
  int ketqua;
  if (root != NULL) {
    if (x > root->data)
      ketqua = themNodeVaoCay_AVL(root->right, x);
    else if (x < root->data)
      ketqua = themNodeVaoCay_AVL(root->left, x);
    else
      return 0;
  }
  else {
    AVL* con = getNode_AVL(x);
    if (con == NULL)
      return -1;
    root = con;
    return 1;
  }

  if (ketqua == 1) {
    int kq = xetTinhCanBangVaCanBangLaiTai1Node_AVL(root);
    if (kq == 1)
      return 2;
    else if (kq == 0)
      return 1;
  }
}

int tinhChieuCaoCay_AVL(AVL* root) {
  if (root == NULL)
    return 0;
  int left = tinhChieuCaoCay_AVL(root->left);
  int right = tinhChieuCaoCay_AVL(root->right);
  return left > right ? left + 1 : right + 1;
}

int xetTinhCanBangVaCanBangLaiTai1Node_AVL(AVL*& root) {
  int chieucaocontrai = 0;
  int chieucaoconphai = 0;
  if (root->left != NULL)
    chieucaocontrai = tinhChieuCaoCay_AVL(root->left);
  if (root->right != NULL)
    chieucaoconphai = tinhChieuCaoCay_AVL(root->right);
  if (abs(chieucaocontrai - chieucaoconphai) > 1) {
    if (chieucaocontrai > chieucaoconphai) {
      int chieucaocontrai_2 = 0;
      int chieucaoconphai_2 = 0;
      if (root->left->left != NULL)
        chieucaocontrai_2 = tinhChieuCaoCay_AVL(root->left->left);
      if (root->left->right != NULL)
        chieucaoconphai_2 = tinhChieuCaoCay_AVL(root->left->right);
      if (chieucaocontrai_2 >= chieucaoconphai_2)
        quayPhai_AVL(root);
      else {
        quayTrai_AVL(root->left);
        quayPhai_AVL(root);
      }
    }
    else {
      int chieucaocontrai_2 = 0;
      int chieucaoconphai_2 = 0;
      if (root->right->left != NULL)
        chieucaocontrai_2 = tinhChieuCaoCay_AVL(root->right->left);
      if (root->right->right != NULL)
        chieucaoconphai_2 = tinhChieuCaoCay_AVL(root->right->right);
      if (chieucaoconphai_2 >= chieucaocontrai_2)
        quayTrai_AVL(root);
      else {
        quayPhai_AVL(root->right);
        quayTrai_AVL(root);
      }
    }
    return 1;
  }
  return 0;
}

void NLR_AVL(AVL* root) {
  if (root != NULL) {
    cout << " " << root->data;
    NLR_AVL(root->left);
    NLR_AVL(root->right);
  }
}