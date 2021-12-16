#include <iostream>
#include <queue>
using namespace std;

/* Khai bao cau truc du lieu cay nhi phan */
struct Node {
  char data; // Du lieu trong Node la ky tu
  struct Node* left, * right; // con tro tro den lien ket Node trai va Node phai
};
typedef struct Node NODE;
// typedef NODE* Tree;

/* Khoi tao cay */
void khoiTao(NODE*& root) { // Tree &root
  root = NULL;
}

/* Tao Node */
// Ham nay se khoi tao ra 1 Node moi va dua x vao Data cua Node do sau do tra Node do ve
NODE* taoNode(char x) { // x la du lieu dua vao trong Node
  NODE* p = new NODE;

  // Truong hop may tinh het bo nho de cap phat
  if (p == NULL)
    return NULL;

  // Neu con chay duoc xuong duoi nay tuc la Node khong rong -> khoi tao thanh cong
  p->data = x; // x duoc cap nhat vo Data cua Node p
  p->left = p->right = NULL; // Khoi tao lien ket con trai va con phai cua Node p la NULL

  return p; // Tra ve Node p sau khi duoc tao ra va cap nhat du lieu
}

void nhapDuLieuMotNode(NODE*& k, char* s) {
  fflush(stdin);
  char x;
  do {
    cout << "\nNhap vao du lieu Node " << s << " la: ";
    cin >> x;
    if (x < 'A' || x > 'Z' && x < 'a' || x > 'z')
      cout << "\nDu lieu nhap cho Node phai la ky tu trong bang chu cai. Xin nhap lai";
  } while (x < 'A' || x > 'Z' && x < 'a' || x > 'z');
  k = taoNode(x);
}

void taoCay(NODE*& root) {
  // char x;
  // cout << "\nNhap du lieu cho Node goc: ";
  // cin >> x;
  // root = taoNode(x);

  nhapDuLieuMotNode(root, (char *)"goc");

  queue<NODE*> q;
  q.push(root);

  while (!q.empty()) { // Se lap lien tuc khi nao hang doi con khac rong
    NODE* p = q.front(); // Lay node dau tien dang cho duoc xu ly
    q.pop(); // Bo no ra khoi hang doi

    int soCon;
    do {
      cout << "\nNhap vao so luong con cua Node " << p->data << " (0 hay 1 hay 2): ";
      cin >> soCon;
      if (soCon < 0 || soCon > 2)
        cout << "\nSo luong con chi co the la 0 hay 1 hay 2. Xin kiem tra va nhap lai";
    } while (soCon < 0 || soCon > 2);

    if (soCon == 1) {
      char loaiCon;
      do {
        fflush(stdin);
        cout << "\nBan muon con cua Node " << p->data << " la con trai hay con phai?. Neu la con trai nhap L - Neu la con phai nhap R: ";
        cin >> loaiCon;
        if (loaiCon != 'L' && loaiCon != 'R' && loaiCon != 'l' && loaiCon != 'r')
          cout << "\nNeu la con trai thi nhap L - Neu la con phai thi nhap R. Khong duoc nhap khac ky tu quy dinh";
      } while (loaiCon != 'L' && loaiCon != 'R' && loaiCon != 'l' && loaiCon != 'r');


      NODE *k;
      if (loaiCon == 'L' || loaiCon == 'l') { // La con trai
        // char x;
        // cout << "\nNhap vao du lieu Node con trai: ";
        // cin >> x;
        // NODE* k = taoNode(x);
        // p->left = k; // k la con trai cua p

        // q.push(k);


        nhapDuLieuMotNode(k, (char *)"con trai");
        p->left = k;
      }
      else { // La con phai
        // char x;
        // cout << "\nNhap vao du lieu Node con phai: ";
        // cin >> x;
        // NODE* k = taoNode(x);
        // p->right = k; // k la con phai cua p

        // q.push(k);


        nhapDuLieuMotNode(k, (char *)"con phai");
        p->right = k;
      }
      q.push(k);
    }
    else if (soCon == 2) {
      NODE *l, *r;

      nhapDuLieuMotNode(l, (char *)"con trai");
      p->left = l;
      q.push(l);

      nhapDuLieuMotNode(r, (char *)"con phai");
      p->right = r;
      q.push(r);
    }
  }
}

int main() {
  // /* Nhap du lieu cho cay (Tao cay) */

  // // Buoc 1: Tao ra bay nhieu Node tuong ung voi cac Node co trong cay
  // NODE *A = taoNode('A');// Day chinh la Node goc
  // NODE *B = taoNode('B');
  // NODE *C = taoNode('C');
  // NODE *D = taoNode('D');
  // NODE *E = taoNode('E');
  // NODE *F = taoNode('F');
  // NODE *G = taoNode('G');
  // NODE *H = taoNode('H');
  // NODE *I = taoNode('I');
  // NODE *J = taoNode('J');
  // NODE *K = taoNode('K');
  // NODE *L = taoNode('L');

  // // Buoc 2: Tao ra cac moi lien ket giua cac Node voi nhau
  // A->left = B;
  // A->right = C;
  // B->left = D;
  // B->right = E;
  // C->left = F;
  // C->right = G;
  // D->left = H;
  // D->right = I;
  // E->right = J;
  // F->left = K;
  // G->right = L;

  // if(A->left->left->right->right == NULL)
  //   cout << "\nGia tri NULL nen khong xuat ra duoc";
  // else // Khac NULL
  //   cout << A->left->left->right->right->data;


  NODE *root;
  taoCay(root);
  cout << "\nroot: " << root->data;
  cout << "\nroot->left: " << root->left->data;
  // cout << "\nroot->right: " << root->right->data;
  cout << "\nroot->left->left: " << root->left->left->data;
  // cout << "\nroot->left->right: " << root->left->right->data;
  cout << "\nroot->left->left->left: " << root->left->left->left->data;
  cout << "\nroot->left->left->left->left: " << root->left->left->left->left->data;




  system("pause");
  return 0;
}