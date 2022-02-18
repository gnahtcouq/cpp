//phung xuan doan
#include <stdio.h>
#include <conio.h>


typedef struct TNode {
  int info;
  TNode* pLeft;
  TNode* pRight;
}*tree;

//====================================================
void Init(tree& t) //Ham khoi tao BST
{
  t = NULL;
}
//====================================================
int IsEmpty(tree& t) {
  return (t == NULL);
}
//====================================================
TNode* CreateNode(int x) //Ham tao nut moi
{
  TNode* p = new TNode;
  if (p != NULL) {
    p->info = x;
    p->pLeft = p->pRight = NULL;
  }
  return p;
}
//====================================================
void Insert(tree& t, int x) {
  if (IsEmpty(t))	t = CreateNode(x);
  else {
    if (x < t->info) Insert(t->pLeft, x);
    if (x > t->info) Insert(t->pRight, x);
  }
}
//====================================================
void CreateSearchTree(tree& t, int a[], int  n) {
  for (int i = 0;i < n;i++) {
    Insert(t, a[i]);
  }
}
//====================================================
void NLR(tree t) {
  if (t != NULL) {
    printf("%6d", t->info);

    NLR(t->pLeft);

    NLR(t->pRight);
  }
}
void LNR(tree t) {
  if (t != NULL) {

    LNR(t->pLeft);
    printf("%6d", t->info);
    LNR(t->pRight);
  }
}
void LRN(tree t) {
  if (t != NULL) {

    LRN(t->pLeft);
    LRN(t->pRight);
    printf("%6d", t->info);
  }
}
//====================================================
int CountNode(tree t) {
  if (t == NULL)
    return 0;
  else
    return 1 + CountNode(t->pLeft) + CountNode(t->pRight);
}
//====================================================
int SumNode(tree t) {
  if (t != NULL) {
    int a = SumNode(t->pLeft);
    int b = SumNode(t->pRight);
    return t->info + a + b;
  }
  return 0;
}
//====================================================
int HighNode(tree t) {
  if (t == NULL)
    return 0;
  int a = HighNode(t->pLeft);
  int b = HighNode(t->pRight);
  if (a > b)
    return a + 1;
  else
    return b + 1;
}
//====================================================
//xoa node co gia tri y
int DelX(tree& t, int y) {
  if (t == NULL) return 0;
  else if (t->info > y) return DelX(t->pLeft, y);
  else if (t->info < y) return DelX(t->pRight, y);
  else // t->data == y
  {
    if (t->pLeft == NULL) t = t->pRight;    // Node chi co cay con phai
    else if (t->pRight == NULL) t = t->pLeft;   // Node chi co cay con trai
    else // Node co ca 2 con
    {
      TNode* Q = t->pLeft;
      while (Q->pRight != NULL) {
        Q = Q->pRight;
      }
      t->info = Q->info;
      DelX(t->pLeft, Q->info);
    }
  }
  return 1;
}
//====================================================
//Kiem tra  nut la
char IsLeaf(TNode* p) {
  return (p->pLeft == NULL) && (p->pRight == NULL);
}
//dem node la
int CountLeaf(tree t) {
  if (t == NULL)
    return 0;
  else
    if (IsLeaf(t))
      return 1;
    else
      return CountLeaf(t->pLeft) + CountLeaf(t->pRight);
}
//====================================================
// tim nut co gia tri x
TNode* SearchNode(tree t, int x) {
  if (t != NULL) {
    if (t->info == x) {
      TNode* p = t;
      return p;
    }
    if (t->info > x) return SearchNode(t->pLeft, x);
    if (t->info < x) return SearchNode(t->pRight, x);
  }
  return NULL;
}

//====================================================
//xuat cac node tang K
void OutPutK(tree t, int k) {
  if (t != NULL) {
    k--;
    if (t->pLeft != NULL)
      OutPutK(t->pLeft, k);
    if (k == 0)
      printf("%5d", t->data);
    if (t->pRight != NULL)
      OutPutK(t->pRight, k);
  }
}
//====================================================

//====================================================

//====================================================
int main() {
  int a[] = { 99,5,8,1,6,2,9,7,4 };
  int n = 9;
  int y, x, k;
  tree t;
  Init(t);
  TNode* p;
  CreateSearchTree(t, a, 9);
  printf("\n\n\t\t========= Duyet NLR =============\n\n");NLR(t);
  printf("\n\n\t\t========= Duyet LNR =============\n\n");LNR(t);
  printf("\n\n\t\t========= Duyet LRN =============\n\n");LRN(t);
  //====================================================

  printf("\n1.tong so node cay la %d", CountNode(t));
  printf("\n2.tong gia tri node cay la %d", SumNode(t));
  printf("\n4.chieu cao cua cay la %d", HighNode(t));
  //====================================================

  printf("\n6.Nhap y can xoa: ");
  scanf("%d", &y);
  if (DelX(t, y))
    printf("\nXoa thanh cong\n");
  else
    printf("\nKhong tim thay %d can xoa\n", y);
  printf("\n\n\t\t duyet cay sau khi xoa kieu NLR \n\n");
  printf("\n\t\t========= Duyet NLR =============\n");NLR(t);
  //====================================================

  printf("\n7. So Node La :%d", CountLeaf(t));
  //====================================================

  printf("\n\tNhap x can tim: ");
  scanf("%d", &x);
  p = SearchNode(t, x);
  if (p != NULL)
    printf("\n\tTim thay %d trong cay\n", p->info);
  else
    printf("\n\t%d khong co trong cay\n", x);

  //====================================================


  printf("\n\n\n\n\n");
  return 0;
}
