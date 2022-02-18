//Pham Tran Vinh Tuong
#include <stdio.h>
#include <conio.h>
//19DTHC1
typedef struct TNode {
  int data;
  TNode* pLeft;
  TNode* pRight;
}*Tree;

//====================================================
void Init(Tree& t) 				//Ham khoi tao BST
{
  t = NULL;
}
//====================================================
int IsEmpty(Tree& t) {
  return (t == NULL);
}
//====================================================
TNode* CreateNode(int x)		 //Ham tao nut moi
{
  TNode* p = new TNode;
  if (p != NULL) {
    p->data = x;
    p->pLeft = p->pRight = NULL;
  }
  return p;
}
//====================================================
void Insert(Tree& t, int x) {
  if (IsEmpty(t))	t = CreateNode(x);
  else {
    if (x < t->data) Insert(t->pLeft, x);
    if (x > t->data) Insert(t->pRight, x);
  }
}
//====================================================
void CreateTree(Tree& t, int a[], int begin, int end) {
  if (begin > end) return;
  int i = (begin + end) / 2;
  t = CreateNode(a[i]);
  CreateTree(t->pLeft, a, begin, i - 1);
  CreateTree(t->pRight, a, i + 1, end);
}
//====================================================
void CreateBinarySearchTree(Tree& t, int a[], int n) {
  for (int i = 0; i < n; i++)
    Insert(t, a[i]);
}
//====================================================
void NLR(Tree t) {
  if (t != NULL) {
    printf("%6d", t->data);
    NLR(t->pLeft);
    NLR(t->pRight);
  }
}
//====================================================
void LNR(Tree t) {
  if (t != NULL) {
    LNR(t->pLeft);
    printf("%6d", t->data);
    LNR(t->pRight);
  }
}
//====================================================
void LRN(Tree t) {
  if (t != NULL) {
    LRN(t->pLeft);
    LRN(t->pRight);
    printf("%6d", t->data);
  }
}

//====================================================
int CountNode(Tree t) {				//Dem so nut
  if (t == NULL)
    return 0;
  else
    return 1 + CountNode(t->pLeft) + CountNode(t->pRight);
}

//====================================================
char IsLeaf(TNode* p)				//Kiem tra  nut la
{
  return (p->pLeft == NULL) && (p->pRight == NULL);
}

//====================================================
int CountLeaf(Tree t)				//Dem nut la 
{
  if (t == NULL)
    return 0;
  else
    if (IsLeaf(t))
      return 1;
    else
      return CountLeaf(t->pLeft) + CountLeaf(t->pRight);
}

//====================================================
int MaxNode(Tree t) 				//nut lon nhat trong cay
{
  if (t->pRight == NULL)
    return t->data;
  else
    return MaxNode(t->pRight);
}

//====================================================
int MinNode(Tree t) 			   //nut nho nhat trong cay
{
  if (t->pLeft == NULL)
    return t->data;
  else
    return MinNode(t->pLeft);
}

//====================================================
TNode* SearchX(Tree t, int x)     // tim nut co gia tri x
{
  if (t != NULL) {
    if (t->data == x) {
      TNode* p = t;
      return p;
    }
    if (t->data > x) return SearchX(t->pLeft, x);
    if (t->data < x) return SearchX(t->pRight, x);
  }
  return NULL;
}

//====================================================

//====================================================
int main() {
  int a[] = { 99,5,8,1,6,2,5,9,7,4 };
  int n = 10;
  int x, y;
  Tree t;
  Init(t);
  TNode* p;
  CreateBinarySearchTree(t, a, 10);
  printf("\n\n\tDuyet NLR:");	NLR(t);
  printf("\n\n\tDuyet LNR:");	LNR(t);
  printf("\n\n\tDuyet LRN:");	LRN(t);
  printf("\n\n\tChieu cao cua cay ne =  %d", CountNode(t));
  printf("\n\n\tSo node la cua cay ne =  %d", CountLeaf(t));
  printf("\n\n\tNode lon nhat cua cay ne =  %d", MaxNode(t));
  printf("\n\n\tNode nho nhat cua cay ne =  %d", MinNode(t));
  printf("\n\n\tNhap x can tim di : ");
  scanf("%d", &x);
  p = SearchX(t, x);
  if (p != NULL)
    printf("\n\n\tTim thay %d trong cay\n", p->data);
  else
    printf("\n\n\t%d khong co trong cay\n", x);
  return 0;
}

