#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left, * right;
};
typedef struct Node NODE;

void init(NODE*& root);
NODE* getNode(int x);
void themNodeVaoCay_DeQuy(NODE*& root, int x);
void taoCayTuDaySo(NODE*& root, int a[], int n);
void NLR(NODE* root);
void LNR(NODE* root);
void LRN(NODE* root);

int main() {
  int a[] = { 30,20,35,10,25,32,40,38,34,28,22,15,5,18 };
  int n = sizeof(a) / sizeof(a[0]);
  cout << "\nSo luong phan tu cua mang = " << n;

  NODE* root;
  taoCayTuDaySo(root, a, n);

  cout << "\nNLR: ";
  NLR(root);
  cout << "\nLNR: ";
  LNR(root);
  cout << "\nRNL: ";
  LRN(root);

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

void themNodeVaoCay_DeQuy(NODE*& root, int x) {
  if (root != NULL) {
    if (x > root->data)
      themNodeVaoCay_DeQuy(root->right, x);
    else if (x < root->data)
      themNodeVaoCay_DeQuy(root->left, x);
  }
  else
    root = getNode(x);
}

void taoCayTuDaySo(NODE*& root, int a[], int n) {
  init(root);
  for (int i = 0; i < n; ++i)
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

void LRN(NODE* root) {
  if (root != NULL) {
    LRN(root->left);
    LRN(root->right);
    cout << " " << root->data;
  }
}