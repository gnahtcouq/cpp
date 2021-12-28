#include <iostream>
using namespace std;


/* --------- 1/ Khai bao cau truc du lieu cay nhi phan tim kiem --------- */
struct Node {
  int data; // Cay nhi phan tim kiem chua cac so nguyen
  Node* left, * right; // Tro toi cac node cay con trai va cay con phai
};
typedef struct Node NODE;

/* --------- 2/ Khoi tao cay --------- */
void init(NODE*& root) {
  root = NULL;
}

/* --------- 3/ Tao Node ---------*/
// Tao 1 node moi chua du lieu x va tra ve dia chi cua Node do sau khi tao xong
NODE* getNode(int x) { // x la du lieu ma se dua no vao trong node
  NODE* p = new NODE;
  if (p == NULL)
    return NULL; // Khong tao thanh cong do thieu vung nho de cap phat tao ra Node

  // Neu van con chay duoc xuong day tuc la khong thoa cai if -> Node duoc tao thanh cong
  p->data = x; // Dua du lieu x vao trong Node p
  p->left = p->right = NULL; // cap nhat con tro left, right la NULL
  return p; // Tra ve Node p da duoc tao
}

void themNodeVaoCay_DeQuy(NODE*& root, int x) { // them gia tri x vao cay
  if (root != NULL) {
    // Dieu kien de quy
    if (x > root->data)
      themNodeVaoCay_DeQuy(root->right, x);
    else if (x < root->data)
      themNodeVaoCay_DeQuy(root->left, x);
  }
  else // root == NULL
    root = getNode(x); // Dung de quy -> Tao Node chua gia tri can them vao
}

void themNodeVaoCay_KhuDeQuy(NODE*& root, int x, NODE *goc) {
  // Tu ban dau cay chua co gi -> tao node goc cho cay
  if (root == NULL)
    root = getNode(x);
  else { // Cay da co Node goc roi thi tien hanh them lan luot cac Node tiep theo vao va so sanh de tim vi tri thich hop de them
    NODE *p; // La node truoc khi root = NULL
    while (root != NULL) {
      p = root;
      if (x > root->data)
        root = root->right;
      else if (x < root->data)
        root = root->left;
      else if (x == root->data) {
        root = goc;
        return; // Ket thuc ham do cay nhi phan tim kiem khong co node trung nhau
      }
    }
    // Them Node moi vao
    if (x > p->data)
      p->right = getNode(x);
    else if (x < p->data)
      p->left = getNode(x);
    root = goc;
  }
}

void taoCayTuDaySo(NODE *&root, int a[], int n) { // Day so chua trong mang a va co n la so luong phan tu cua day
  init(root); // khoi tao ra cay roi tu do moi co the them cac node vao trong cay
  for (int i = 0; i < n; ++i) // vong lap duyet qua danh sach day so chua trong mang a de tu do them vao cay
    themNodeVaoCay_DeQuy(root, a[i]);
}

void taoCayTuDaySo_KhuDeQuy(NODE *&root, int a[], int n) { // Day so chua trong mang a va co n la so luong phan tu cua day
  init(root); // khoi tao ra cay roi tu do moi co the them cac node vao trong cay
  root = getNode(a[0]);
  NODE *goc = root;
  for (int i = 1; i < n; ++i) // vong lap duyet qua danh sach day so chua trong mang a de tu do them vao cay
    themNodeVaoCay_KhuDeQuy(root, a[i], goc);
}

void NLR(NODE *root) {
  if (root != NULL) {
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
  }
}

void LNR(NODE *root) {
  if (root != NULL) {
    LNR(root->left);
    cout << root->data << " ";
    LNR(root->right);
  }
}

void RNL(NODE *root) {
  if (root != NULL) {
    RNL(root->right);
    cout << root->data << " ";
    RNL(root->left);
  }
}

void LRN(NODE *root) {
  if (root != NULL) {
    LRN(root->left);
    LRN(root->right);
    cout << root->data << " ";
  }
}

int main() {
  int a[] = {40, 5, 35, 45, 15, 56, 35, 35, 35, 48, 13, 16, 49, 47};
  int n = sizeof(a) / sizeof(a[0]);

  NODE *root;
  taoCayTuDaySo(root, a, n);

  cout << "\nNLR: ";
  NLR(root);

  cout << "\nLNR: ";
  LNR(root);
  cout << "\nRNL: ";
  RNL(root);

  cout << "\nLRN: ";
  LRN(root);



  taoCayTuDaySo_KhuDeQuy(root, a, n);

  cout << "\nNLR: ";
  NLR(root);

  cout << "\nLNR: ";
  LNR(root);
  cout << "\nRNL: ";
  RNL(root);

  cout << "\nLRN: ";
  LRN(root);

  system("pause");
  return 0;
}

// phut 38