#include <iostream>
#include <queue>
#include <time.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

// struct Node {
//   char data;
//   struct Node* left, * right;
//   bool tinhTrangDuyet;
// };
// typedef struct Node NODE;

// void khoiTao(NODE*& root) {
//   root = NULL;
// }

// NODE* taoNode(char x) {
//   NODE* p = new NODE;
//   if (p == NULL)
//     return NULL;
//   p->data = x;
//   p->left = p->right = NULL;
//   p->tinhTrangDuyet = false; // Chua duoc duyet
//   return p;
// }








/* -------------- DO THOI GIAN ----------------- */
struct Node {
  int data;
  struct Node* left, * right;
  bool tinhTrangDuyet;
};
typedef struct Node NODE;

void khoiTao(NODE*& root) {
  root = NULL;
}

NODE* taoNode(int x) {
  NODE* p = new NODE;
  if (p == NULL)
    return NULL;
  p->data = x;
  p->left = p->right = NULL;
  p->tinhTrangDuyet = false; // Chua duoc duyet
  return p;
}
/* -------------- DO THOI GIAN ----------------- */










void giaiPhong(NODE *&root) {
  if (root != NULL) {
    giaiPhong(root->left);
    giaiPhong(root->right);
    delete root;
    root = NULL;
  }
}

// NODE - LEFT - RIGHT
 // 1: left->right, Khac 1: right->left
void phepDuyetTruoc(NODE *root, int thutu = 1) {
  if (root != NULL) {
    // cout << root->data << " "; // Duyet in ra N
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
      // cout << root->data << " "; // Duyet in ra N
      phepDuyetGiua(root->right, thutu);
    }
    else {
      phepDuyetGiua(root->right, thutu);
      // cout << root->data << " "; // Duyet in ra N
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
      // cout << root->data << " "; // Duyet in ra N
    }
    else {
      phepDuyetSau(root->right, thutu);
      phepDuyetSau(root->left, thutu);
      // cout << root->data << " "; // Duyet in ra N
    }
  }
}

/*-------- KHONG DE QUY --------*/





// Thu tu = 1 (left->right)
// Thu tu = 2 (right->left)
void NLR_KhuDeQuyDungStack(NODE *root, int thutu = 1) {
  stack<NODE *> s;
  s.push(root);
  // thutu == 1 ? cout << "\nNLR: " : cout << "\nNRL: ";
  while (!s.empty()) {
    NODE *p = s.top();
    s.pop();
    // cout << p->data << " ";

    if (thutu == 1) { // left->right
      if (p->right != NULL)
        s.push(p->right);
      if (p->left != NULL)
        s.push(p->left);
    }
    else { // right->left
      if (p->left != NULL)
        s.push(p->left);
      if (p->right != NULL)
        s.push(p->right);
    }
  }
}







// B1: Dua node goc cua cay can xet vao stack
// B2: Lay node o dinh stack ra xet
// + Neu node do co con phai va con phai do chua duoc them vao stack
// -> luu tam node o dinh stack vao 1 bien phu, sau do xoa di roi bo node con phai do vao stack va danh dau da duoc duyet sau do tra lai node o bien phu vao dau stack va xet lai bien o dau stack
// + Neu node do co con trai va con trai do phai chua duoc them vao stack -> them con trai vao dau stack phai danh dau node con do da duoc them vao stack
// + Neu node do ko co con trai va con phai hoac co con nhung da duoc duyet -> tuc la khong them vao node gi het -> in node do ra va bo ra khoi stack
// B3: Lap lai quy trinh o buoc 2 cho den khi stack rong

// Thu tu = 1 (left->right)
// Thu tu = 2 (right->left)
void LNR_KhuDeQuyDungStack(NODE *root, int thutu = 1) {
  stack<NODE *> s;
  s.push(root);
  root->tinhTrangDuyet = true;
  // thutu == 1 ? cout << "\nLNR: " : cout << "\nRNL: ";

  while (!s.empty()) {
    NODE *p = s.top();
    bool check = false;
    if (thutu == 1) {
      if (p->right != NULL && p->right->tinhTrangDuyet == false) { // Co ton tai con phai va con phai chua duoc duyet
        s.pop(); // xoa phan tu dau stack hien tai
        s.push(p->right); // dua con phai vao stack
        p->right->tinhTrangDuyet = true; // danh dau la da duoc duyet
        s.push(p); // tra lai phan tu dau stack truoc do
        check = true; // kiem tra co con duoc them vao
      }
      if (p->left != NULL && p->left->tinhTrangDuyet == false) { // Co ton tai con trai va con trai chua duoc duyet
        s.push(p->left); // dua con trai vao stack
        p->left->tinhTrangDuyet = true; // danh dau la da duoc duyet
        check = true; // kiem tra co con duoc them vao
      }
    }
    else {
      if (p->left != NULL && p->left->tinhTrangDuyet == false) { // Co ton tai con phai va con phai chua duoc duyet
        s.pop(); // xoa phan tu dau stack hien tai
        s.push(p->left); // dua con phai vao stack
        p->left->tinhTrangDuyet = true; // danh dau la da duoc duyet
        s.push(p); // tra lai phan tu dau stack truoc do
        check = true; // kiem tra co con duoc them vao
      }
      if (p->right != NULL && p->right->tinhTrangDuyet == false) { // Co ton tai con trai va con trai chua duoc duyet
        s.push(p->right); // dua con trai vao stack
        p->right->tinhTrangDuyet = true; // danh dau la da duoc duyet
        check = true; // kiem tra co con duoc them vao
      }
    }
    // Neu sau 1 qua trinh xet ma khong co con nao duoc them vao -> in ra node dau stack hien tai va bo di
    if (check == false) {
      // cout << p->data << " ";
      s.pop();
    }
  }
}





// Duyet sau (LRN)
// Do vao stack theo chieu nguoc lai (NRL)
// B1: Dua node goc vao stack
// B2: Lay phan tu dau stack ra xet. Neu no co con phai va con trai lan luot deu chua duoc them vao stack thi tien hanh them vao va danh dau la da duoc them
// B3: Xet lai phan tu dau stack va thay Neu node do khong co con hoac co nhung khong the them vao do da duoc them truoc do (tuc la noi chung la node do bay gio khong the them duoc gi vao stack) -> lay node do ra khoi stack va in ra
// B4: Lap lai qua trinh tu buoc 2 cho den khi stack rong khong con phan tu thi dung lai

// Thu tu = 1 (left->right)
// Thu tu = 2 (right->left)
void LRN_KhuDeQuyDungStack(NODE *root, int thutu = 1) {
  stack<NODE *> s;
  s.push(root);
  
  while (!s.empty()) {
    NODE *p = s.top();
    bool check = false; // bien co hieu muc dich de biet xem tu node hien tai dau stack co node con nao cua no hop le de duoc them vao tiep. Neu trai qua 2 cai if ma check  van la false tuc la khong co node con nao cua node dang xet duoc them vao stack -> in ra va lay node do ra khoi stack
    // Xet co con phai va chua duoc them vao stack

    if (thutu == 1) {
      if (p->right != NULL && p->right->tinhTrangDuyet == false) {
        s.push(p->right); // tien hanh them vao
        p->right->tinhTrangDuyet = true; // cap nhat tinh trang them
        check = true;
      }
      // Xet co con trai va chua duoc them vao stack
      if (p->left != NULL && p->left->tinhTrangDuyet == false) {
        s.push(p->left); // tien hanh them vao
        p->left->tinhTrangDuyet = true; // cap nhat tinh trang them
        check = true;
      }
    }
    else {
      // Xet co con trai va chua duoc them vao stack
      if (p->left != NULL && p->left->tinhTrangDuyet == false) {
        s.push(p->left); // tien hanh them vao
        p->left->tinhTrangDuyet = true; // cap nhat tinh trang them
        check = true;
      }
      if (p->right != NULL && p->right->tinhTrangDuyet == false) {
        s.push(p->right); // tien hanh them vao
        p->right->tinhTrangDuyet = true; // cap nhat tinh trang them
        check = true;
      }
    }
    if (check == false) {
      // cout << p->data << " ";
      s.pop(); // bo ra khoi stack
    }
  }
}

int main() {
  /* Nhap du lieu cho cay (Tao cay) */

  // // Buoc 1: Tao ra bay nhieu Node tuong ung voi cac Node co trong cay
  // NODE *root = taoNode('A');// Day chinh la Node goc
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
  // root->left = B;
  // root->right = C;
  // B->left = D;
  // B->right = E;
  // C->left = F;
  // C->right = G;
  // D->left = H;
  // D->right = I;
  // E->right = J;
  // F->left = K;
  // G->right = L;

  // NODE *M = taoNode('M');
  // E->left = M;
  // NODE *N = taoNode('N');
  // F->right = N;
  // NODE *O = taoNode('O');
  // G->left = O;








/* -------------- DO THOI GIAN ----------------- */
  /* Tao ra 1 cay nhi phan day du co do cao la k */
  int k = 25;
  NODE *root = taoNode(1);
  queue<NODE *> q;
  q.push(root);

  while (true) {
    NODE *p = q.front();
    q.pop();

    if (p->data == pow(2.0, k - 1))
      break;

    p->left = taoNode(2 * p->data);
    p->right = taoNode(2 * p->data + 1);
    q.push(p->left);
    q.push(p->right);
  }
/* -------------- DO THOI GIAN ----------------- */







  // clock_t start1 = clock();
  // phepDuyetTruoc(root);
  // clock_t end1 = clock();
  // cout << "\nphepDuyetTruoc chay mat " << (double)(end1 - start1) / CLOCKS_PER_SEC << " giay";
  // // phepDuyetTruoc(root, 2);

  // clock_t start2 = clock();
  // NLR_KhuDeQuyDungStack(root);
  // clock_t end2 = clock();
  // cout << "\nNLR_KhuDeQuyDungStack chay mat " << (double)(end2 - start2) / CLOCKS_PER_SEC << " giay";
  // // NLR_KhuDeQuyDungStack(root, 2);




  // clock_t start1 = clock();
  // phepDuyetGiua(root);
  // clock_t end1 = clock();
  // cout << "\nphepDuyetGiua chay mat " << (double)(end1 - start1) / CLOCKS_PER_SEC << " giay";
  // // phepDuyetGiua(root, 2);

  // clock_t start2 = clock();
  // LNR_KhuDeQuyDungStack(root);
  // clock_t end2 = clock();
  // cout << "\nLNR_KhuDeQuyDungStack chay mat " << (double)(end2 - start2) / CLOCKS_PER_SEC << " giay";
  // // LNR_KhuDeQuyDungStack(root, 2);




  clock_t start1 = clock();
  phepDuyetSau(root);
  clock_t end1 = clock();
  cout << "\nphepDuyetSau chay mat " << (double)(end1 - start1) / CLOCKS_PER_SEC << " giay";
  // phepDuyetSau(root, 2);

  clock_t start2 = clock();
  LRN_KhuDeQuyDungStack(root);
  clock_t end2 = clock();
  cout << "\nLRN_KhuDeQuyDungStack chay mat " << (double)(end2 - start2) / CLOCKS_PER_SEC << " giay";
  // LRN_KhuDeQuyDungStack(root, 2);



  cout << "\nGiai phong cay";
  giaiPhong(root);

  cout << endl;
  system("pause");
  return 0;
}