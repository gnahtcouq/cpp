#include <iostream>
using namespace std;

/* Khai bao cau truc du lieu cay nhi phan */
struct Node {
  char data; // Du lieu trong Node la ky tu
  struct Node *left, *right; // con tro tro den lien ket Node trai va Node phai
};
typedef struct Node NODE;
// typedef NODE* Tree;

/* Khoi tao cay */
void khoiTao(NODE *&root) { // Tree &root
  root = NULL;
}

/* Tao Node */
// Ham nay se khoi tao ra 1 Node moi va dua x vao Data cua Node do sau do tra Node do ve
NODE* taoNode(char x) { // x la du lieu dua vao trong Node
  NODE *p = new NODE;
  
  // Truong hop may tinh het bo nho de cap phat
  if (p == NULL)
    return NULL;

  // Neu con chay duoc xuong duoi nay tuc la Node khong rong -> khoi tao thanh cong
  p->data = x; // x duoc cap nhat vo Data cua Node p
  p->left = p->right = NULL; // Khoi tao lien ket con trai va con phai cua Node p la NULL

  return p; // Tra ve Node p sau khi duoc tao ra va cap nhat du lieu
}

int main() {
  /* Nhap du lieu cho cay (Tao cay) */

  // Buoc 1: Tao ra bay nhieu Node tuong ung voi cac Node co trong cay
  NODE *A = taoNode('A');// Day chinh la Node goc
  NODE *B = taoNode('B');
  NODE *C = taoNode('C');
  NODE *D = taoNode('D');
  NODE *E = taoNode('E');
  NODE *F = taoNode('F');
  NODE *G = taoNode('G');
  NODE *H = taoNode('H');
  NODE *I = taoNode('I');
  NODE *J = taoNode('J');
  NODE *K = taoNode('K');
  NODE *L = taoNode('L');

  // Buoc 2: Tao ra cac moi lien ket giua cac Node voi nhau
  A->left = B;
  A->right = C;
  B->left = D;
  B->right = E;
  C->left = F;
  C->right = G;
  D->left = H;
  D->right = I;
  E->right = J;
  F->left = K;
  G->right = L;

  if(A->left->left->right->right == NULL)
    cout << "\nGia tri NULL nen khong xuat ra duoc";
  else // Khac NULL
    cout << A->left->left->right->right->data;

  system("pause");
  return 0;
}