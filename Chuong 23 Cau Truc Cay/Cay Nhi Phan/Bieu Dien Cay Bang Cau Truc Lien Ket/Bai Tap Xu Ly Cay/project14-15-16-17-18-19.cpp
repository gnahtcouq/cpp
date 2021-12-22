// 1. Dem so luong cac nut co tren cay
#include <iostream>
#include <queue>
#include <time.h>
#include <math.h>
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

void giaiPhong(NODE *&root) {
  if (root != NULL) {
    giaiPhong(root->left); // Xet tiep qua nhanh con trai cua Node hien tai
    giaiPhong(root->right); // Xet tiep qua nhanh con phai cua Node hien tai
    delete root; // Giai phong Node dang xet den. Luu y: Phai giai phong no sau cung (duyet sau) chu neu dung duyet truoc hay duyet giua thi sau khi giai phong thi lay gi ma tro? -> loi
    root = NULL; // Sau khi giai phong xong phai cap nhat cho Node go gia tri NULL neu khong se bi loi ngang neu sau khi giai phong xong nguoi dung co thao tac tiep gi do (vd: duyet cay)
  }
}

void demTongCacNodeTrenCay_DeQuyDuoi(NODE *root, int &dem) {
  if (root != NULL) {
    dem++; // Cu den 1 Node la tang bien dem len 1
    demTongCacNodeTrenCay_DeQuyDuoi(root->left, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demTongCacNodeTrenCay_DeQuyDuoi(root->right, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

int demSoLuongCacNodeTrenCay_DeQuyThuong(NODE *root) {
  // Dieu kien dung la khi nut do khong ton tai
  if (root == NULL)
    return 0;
  
  // Buoc de quy -> tuc la nut do co ton tai
  return 1 + demSoLuongCacNodeTrenCay_DeQuyThuong(root->left) + demSoLuongCacNodeTrenCay_DeQuyThuong(root->right);
}

int demSoLuongCacNodeTrenCay_KhongDeQuy(NODE *root) {
  queue<NODE *> q;
  // Phai co ton tai Node goc thi moi dua Node goc do vao hang doi
  if (root != NULL)
    q.push(root);

  int dem = 0;
  while (!q.empty()) { // Lap lien tuc khi hang doi con phan tu
    NODE *p = q.front();
    dem++;
    q.pop(); // Bo Node ra khoi hang doi

    if (p->left != NULL) // Co ton tai Node con trai cua p
      q.push(p->left); // Dua con trai vao hang doi
    if (p->right != NULL) // Co on tai Node con phai cua p
      q.push(p->right); // Dua con phai vao hang doi

  }
  return dem;
}

// Node la: la Node khong co con
int demSoLuongCacNodeLa_DeQuyThuong(NODE *root) {
  // Dieu kien dung la khi nut do khong ton tai
  if (root == NULL)
    return 0;

  int dem = 0;
  if (root->left == NULL && root->right == NULL) { // Root la node la -> cho dem = 1
    dem = 1;
    cout << root->data << " ";
  }
  
  // Buoc de quy -> tuc la nut do co ton tai
  return dem + demSoLuongCacNodeLa_DeQuyThuong(root->left) + demSoLuongCacNodeLa_DeQuyThuong(root->right);
}

// Node la: la Node khong co con
void demSoLuongCacNodeLa_DeQuyDuoi(NODE *root, int &dem) {
  if (root != NULL) {
    if (root->left == NULL && root->right == NULL) {
      dem++; // Cu den 1 Node la tang bien dem len 1
      cout << root->data << " ";
    }
    demSoLuongCacNodeLa_DeQuyDuoi(root->left, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demSoLuongCacNodeLa_DeQuyDuoi(root->right, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

int demSoLuongCacNodeCoDu2Con_DeQuyThuong(NODE *root) {
  // Dieu kien dung la khi nut do khong ton tai
  if (root == NULL)
    return 0;

  int dem = 0;
  if (root->left != NULL && root->right != NULL) { // Root la node la -> cho dem = 1
    dem = 1;
    cout << root->data << " ";
  }
  
  // Buoc de quy -> tuc la nut do co ton tai
  return dem + demSoLuongCacNodeCoDu2Con_DeQuyThuong(root->left) + demSoLuongCacNodeCoDu2Con_DeQuyThuong(root->right);
}

void demSoLuongCacNodeCoDu2Con_DeQuyDuoi(NODE *root, int &dem) {
  if (root != NULL) {
    if (root->left != NULL && root->right != NULL) {
      dem++; // Cu den 1 Node la tang bien dem len 1
      cout << root->data << " ";
    }
    demSoLuongCacNodeCoDu2Con_DeQuyDuoi(root->left, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demSoLuongCacNodeCoDu2Con_DeQuyDuoi(root->right, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

int demSoLuongCacNodeCo1Con_DeQuyThuong(NODE *root) {
  // Dieu kien dung la khi nut do khong ton tai
  if (root == NULL)
    return 0;

  int dem = 0;
  // if (root->left != NULL || root->right != NULL)
  if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL)) { // Root la node la -> cho dem = 1
    dem = 1;
    cout << root->data << " ";
  }
  
  // Buoc de quy -> tuc la nut do co ton tai
  return dem + demSoLuongCacNodeCo1Con_DeQuyThuong(root->left) + demSoLuongCacNodeCo1Con_DeQuyThuong(root->right);
}

void demSoLuongCacNodeCo1Con_DeQuyDuoi(NODE *root, int &dem) {
  if (root != NULL) {
    if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL)) {
      dem++; // Cu den 1 Node la tang bien dem len 1
      cout << root->data << " ";
    }
    demSoLuongCacNodeCo1Con_DeQuyDuoi(root->left, dem); // Xet tiep qua nhanh con trai cua Node hien tai
    demSoLuongCacNodeCo1Con_DeQuyDuoi(root->right, dem); // Xet tiep qua nhanh con phai cua Node hien tai
  }
}

int tinhBacCua1Node(NODE *x) {
  int demCon = 0;

  if (x->left != NULL)
    demCon++;
  if (x->right != NULL)
    demCon++;

  return demCon;
}

void tinhBacCuaCay(NODE *root, int &maxBac) {
  if (root != NULL) {
    cout << root->data << " ";
    // Xu ly
    int bac = tinhBacCua1Node(root);
    if (bac > maxBac) {
      maxBac = bac;
      if (maxBac == 2) // Nhan thay cay luon co bac toi da la 2 nen khi tim duoc 1 node co bac toi da la 2 roi thi dung lai khong goi de quy tiep nua
        return;
    }

    tinhBacCuaCay(root->left, maxBac);
    tinhBacCuaCay(root->right, maxBac);
  }
}

int tinhChieuCaoCuaCay_DeQuyThuong(NODE *root) {
  if (root == NULL)
    return 0;
  int left = tinhChieuCaoCuaCay_DeQuyThuong(root->left);
  int right = tinhChieuCaoCuaCay_DeQuyThuong(root->right);

  return left > right ? left + 1 : right + 1;
}

void tinhChieuCaoCuaCay_DeQuyDuoi(NODE *root, int &max, int level) {
  if (root != NULL) {
    // cout << "\nNode " << root->data << " nam o level" << level;
    if (level > max)
      max = level;
    level++;
    tinhChieuCaoCuaCay_DeQuyDuoi(root->left, max, level);
    tinhChieuCaoCuaCay_DeQuyDuoi(root->right, max, level);
  }
}

void timNodeX(NODE *root, bool &check, char x, int &dosau, int level) {
  if (root != NULL && check == false) { // Chi de quy khi Node co ton tai va trang thai tim kiem la chua co tim thay
    cout << root->data << " ";
    if (root->data == x) {
      // cout << "\nDa tim thay node co data la " << x;
      check = true;
      dosau = level;
      // system("pause");
      // exit(0);
      return; // Ket thuc tim kiem khi da tim thay
    }
    level++;
    timNodeX(root->left, check, x, dosau, level);
    timNodeX(root->right, check, x, dosau, level);
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

  // cout << "\nSo luong cac node la = " << demSoLuongCacNodeLa_DeQuyThuong(root);

  // int soLuongCacNodela = 0;
  // demSoLuongCacNodeLa_DeQuyDuoi(root, soLuongCacNodela);
  // cout << "\nSo luong cac node la " << soLuongCacNodela;

  // cout << "\nSo luong cac node co du 2 con la = " << demSoLuongCacNodeCoDu2Con_DeQuyThuong(root);

  // int soLuongCacNodeDu2Con = 0;
  // demSoLuongCacNodeCoDu2Con_DeQuyDuoi(root, soLuongCacNodeDu2Con);
  // cout << "\nSo luong cac node co du 2 con la = " << soLuongCacNodeDu2Con;

  // cout << "\nSo luong cac Node co duy nhat 1 con la = " << demSoLuongCacNodeCo1Con_DeQuyThuong(root);

  // int soLuongCacNodeCo1Con = 0;
  // demSoLuongCacNodeCo1Con_DeQuyDuoi(root, soLuongCacNodeCo1Con);
  // cout << "\nSo luong cac node duy nhat 1 con la = " << soLuongCacNodeCo1Con;

  // cout << "\nBac cua Node " << C->data << " = " << tinhBacCua1Node(C);
  // int bacCuaCay = 0;
  // tinhBacCuaCay(root, bacCuaCay);
  // cout << "\nCay co bac la " << bacCuaCay;

  // int chieuCaoCay = tinhChieuCaoCuaCay_DeQuyThuong(root);
  // cout << "\nCay co chieu cao la (dequythuong) " << chieuCaoCay;

  // int chieuCao = 0;
  // tinhChieuCaoCuaCay_DeQuyDuoi(root, chieuCao, 1);
  // cout << "\nCay co chieu cao la (dequyduoi) " << chieuCao;

  bool timThayX = false;
  char x = 'L';
  int doSauCuaNode;
  timNodeX(root, timThayX, x, doSauCuaNode, 1);
  if (timThayX == true)
    cout << "\nDa tim thay node co data la " << x << " => do sau cua node la " << doSauCuaNode;
  else
    cout << "\nKhong tim thay node co data la " << x;

  /* Tao ra 1 cay nhi phan day du co do cao la k */
  // int k = 15;
  // NODE *root = taoNode(1);
  // queue<NODE *> q;
  // q.push(root);

  // while (true) {
  //   NODE *p = q.front();
  //   q.pop();

  //   if (p->data == pow(2.0, k - 1))
  //     break;

  //   p->left = taoNode(2 * p->data);
  //   p->right = taoNode(2 * p->data + 1);
  //   q.push(p->left);
  //   q.push(p->right);
  // }

  // duyetTheoChieuRong(root);



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

  // cout << endl;

  // clock_t start1 = clock();
  // int soLuongCacNode = 0;
  // for (int i = 1; i <= 1000; ++i)
  //   demTongCacNodeTrenCay_DeQuyDuoi(root, soLuongCacNode);
  // // cout << "\nSo luong cac Node tren cay la (de quy duoi): " << soLuongCacNode;
  // clock_t end1 = clock();
  // cout << "\ndemTongCacNodeTrenCay_DeQuyDuoi chay mat " << (double)(end1 - start1) / CLOCKS_PER_SEC;

  // clock_t start2 = clock();
  // for (int i = 1; i <= 1000; ++i)
  //   demSoLuongCacNodeTrenCay_DeQuyThuong(root);
  // clock_t end2 = clock();
  // cout << "\ndemSoLuongCacNodeTrenCay_DeQuyThuong chay mat " << (double)(end2 - start2) / CLOCKS_PER_SEC;

  // // Cach lam tuy khong dung de quy nhung no lai phai udng queue va voi moi thao tac push pop phai mat qua nhieu thoigian de xu ly -> cham
  // clock_t start3 = clock();
  // for (int i = 1; i <= 1000; ++i)
  //   demSoLuongCacNodeTrenCay_KhongDeQuy(root);
  // clock_t end3 = clock();
  // cout << "\ndemSoLuongCacNodeTrenCay_KhongDeQuy chay mat " << (double)(end3 - start3) / CLOCKS_PER_SEC;

  // cout << "\ndemSoLuongCacNodeTrenCay_KhongDeQuy = " << demSoLuongCacNodeTrenCay_KhongDeQuy(root);

  cout << "\nGiai phong cay";
  giaiPhong(root); // Giai phong bo nho da cap phat cho cay;


  system("pause");
  return 0;
}