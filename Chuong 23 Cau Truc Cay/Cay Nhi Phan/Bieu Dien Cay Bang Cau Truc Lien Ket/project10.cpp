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
 // 1: left->right, Khac 1: right->left
void duyetTheoChieuRong(NODE *root, int thutu = 1) {
  queue<NODE *> q;
  // Phai co ton tai Node goc thi moi dua Node goc do vao hang doi
  if (root != NULL)
    q.push(root);

  while (!q.empty()) { // Lap lien tuc khi hang doi con phan tu
    NODE *p = q.front();
    cout << p->data << " "; // Lay ra Node dau hang doi
    q.pop(); // Bo Node ra khoi hang doi

    if (thutu == 1) {
      if (p->left != NULL) // Co ton tai Node con trai cua p
        q.push(p->left); // Dua con trai vao hang doi
      if (p->right != NULL) // Co on tai Node con phai cua p
        q.push(p->right); // Dua con phai vao hang doi
    }
    else {
      if (p->right != NULL) // Co on tai Node con phai cua p
        q.push(p->right); // Dua con phai vao hang doi
      if (p->left != NULL) // Co ton tai Node con trai cua p
        q.push(p->left); // Dua con trai vao hang doi
    }
  }
}

// NODE - LEFT - RIGHT
void NLR(NODE *root) {
  if (root != NULL) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    cout << root->data << " "; // Duyet in ra N
    NLR(root->left);
    NLR(root->right);
  }
}
// NODE - LEFT - RIGHT
 // 1: left->right, Khac 1: right->left
void phepDuyetTruoc(NODE *root, int thutu = 1) {
  if (root != NULL) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    cout << root->data << " "; // Duyet in ra N
    if (thutu == 1) {
      phepDuyetTruoc(root->left, thutu);
      phepDuyetTruoc(root->right, thutu);
    }
    else {
      phepDuyetTruoc(root->right, thutu);
      phepDuyetTruoc(root->left, thutu);
    }
  }
}

// LEFT - NODE - RIGHT
 // 1: left->right, Khac 1: right->left
void phepDuyetGiua(NODE *root, int thutu = 1) {
  if (root != NULL) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    if (thutu == 1) {
      phepDuyetGiua(root->left, thutu);
      cout << root->data << " "; // Duyet in ra N
      phepDuyetGiua(root->right, thutu);
    }
    else {
      phepDuyetGiua(root->right, thutu);
      cout << root->data << " "; // Duyet in ra N
      phepDuyetGiua(root->left, thutu);
    }
  }
}

// LEFT - RIGHT - NODE
 // 1: left->right, Khac 1: right->left
void phepDuyetSau(NODE *root, int thutu = 1) {
  if (root != NULL) { // Dieu kien de duoc de quy -> Neu root == NULL thi khong de quy nua
    if (thutu == 1) {
      phepDuyetSau(root->left, thutu);
      phepDuyetSau(root->right, thutu);
      cout << root->data << " "; // Duyet in ra N
    }
    else {
      phepDuyetSau(root->right, thutu);
      phepDuyetSau(root->left, thutu);
      cout << root->data << " "; // Duyet in ra N
    }
  }
}

void demTongCacNodeTrenCay(NODE *root, int &dem) {
  if (root != NULL) {
    dem++; // Cu den 1 Node la tang bien dem len 1
    demTongCacNodeTrenCay(root->left, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demTongCacNodeTrenCay(root->right, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

void giaiPhong(NODE *&root) {
  if (root != NULL) {
    giaiPhong(root->left); // Xet tiep qua nhanh con trai cua Node hien tai
    giaiPhong(root->right); // Xet tiep qua nhanh con phai cua Node hien tai
    delete root; // Giai phong Node dang xet den. Luu y: Phai giai phong no sau cung (duyet sau) chu neu dung duyet truoc hay duyet giua thi sau khi giai phong thi lay gi ma tro? -> loi
    root = NULL; // Sau khi giai phong xong phai cap nhat cho Node go gia tri NULL neu khong se bi loi ngang neu sau khi giai phong xong nguoi dung co thao tac tiep gi do (vd: duyet cay)
  }
}

int main() {
  /* Nhap du lieu cho cay (Tao cay) */

  // Buoc 1: Tao ra bay nhieu Node tuong ung voi cac Node co trong cay
  NODE *root = taoNode('A');// Day chinh la Node goc
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
  root->left = B;
  root->right = C;
  B->left = D;
  B->right = E;
  C->left = F;
  C->right = G;
  D->left = H;
  D->right = I;
  E->right = J;
  F->left = K;
  G->right = L;

  cout << "\nDuyet theo chieu rong: "; 
  duyetTheoChieuRong(root);

  cout << endl;

  cout << "\nDuyet truoc (NLR): ";
  NLR(root);

  cout << "\nPhep duyet truoc (NLR) left->right: ";
  phepDuyetTruoc(root);
  cout << "\nPhep duyet truoc (NLR) right->left: ";
  phepDuyetTruoc(root, 2);
  
  cout << endl;

  cout << "\nPhep duyet giua (LNR) left->right: ";
  phepDuyetGiua(root);
  cout << "\nPhep duyet giua (LNR) right->left: ";
  phepDuyetGiua(root, 2);

  cout << endl;

  cout << "\nPhep duyet sau (LRN) left->right: ";
  phepDuyetSau(root);
  cout << "\nPhep duyet sau (LRN) right->left: ";
  phepDuyetSau(root, 2);

  cout << endl;

  int soLuongCacNode = 0;
  demTongCacNodeTrenCay(root, soLuongCacNode);
  cout << "\nSo luong cac Node tren cay la: " << soLuongCacNode;

  cout << "\nGiai phong cay";
  giaiPhong(root); // Giai phong bo nho da cap phat cho cay;

  // cout << endl;

  // cout << "\nDuyet theo chieu rong: "; 
  // duyetTheoChieuRong(root);

  // cout << endl;

  // cout << "\nDuyet truoc (NLR): ";
  // NLR(root);

  // cout << "\nPhep duyet truoc (NLR) left->right: ";
  // phepDuyetTruoc(root);
  // cout << "\nPhep duyet truoc (NLR) right->left: ";
  // phepDuyetTruoc(root, 2);
  
  // cout << endl;

  // cout << "\nPhep duyet giua (LNR) left->right: ";
  // phepDuyetGiua(root);
  // cout << "\nPhep duyet giua (LNR) right->left: ";
  // phepDuyetGiua(root, 2);

  // cout << endl;

  // cout << "\nPhep duyet sau (LRN) left->right: ";
  // phepDuyetSau(root);
  // cout << "\nPhep duyet sau (LRN) right->left: ";
  // phepDuyetSau(root, 2);


  // NODE *root;
  // taoCay(root);
  // cout << "\nroot: " << root->data;
  // cout << "\nroot->left: " << root->left->data;
  // // cout << "\nroot->right: " << root->right->data;
  // cout << "\nroot->left->left: " << root->left->left->data;
  // // cout << "\nroot->left->right: " << root->left->right->data;
  // cout << "\nroot->left->left->left: " << root->left->left->left->data;
  // cout << "\nroot->left->left->left->left: " << root->left->left->left->left->data;




  system("pause");
  return 0;
}