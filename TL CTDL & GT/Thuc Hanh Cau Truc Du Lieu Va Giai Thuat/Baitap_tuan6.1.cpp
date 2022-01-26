#include <stdio.h>
#include <conio.h>
//Quach Quang Minh
typedef struct TNode {
  int data;
  TNode* pLeft;
  TNode* pRight;
}*Tree;

//====================================================
void Init(Tree& t) //Ham khoi tao BST
{
  t = NULL;
}
//====================================================
int IsEmpty(Tree& t) {
  return (t == NULL);
}
//====================================================
Tree CreateNode(int x) //Ham tao nut moi
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
  if (IsEmpty(t))t = CreateNode(x);
  else {
    if (x < t->data) Insert(t->pLeft, x);
    if (x > t->data) Insert(t->pRight, x);
  }
}
void CreateBinaryTree(Tree& t, int a[], int n) {
  for (int i = 0;i < n;i++)
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
int DemNodeLa(Tree t) {
  if (t == NULL) return 0;
  if ((t->pLeft == NULL) && (t->pRight == NULL)) return 1;
  return DemNodeLa(t->pLeft) + DemNodeLa(t->pRight);
}
int MaxNode(Tree t) {
  if (t->pRight == NULL)
    return t->data;
  else
    return MaxNode(t->pRight);
}
int MinNode(Tree t) {
  if (t->pLeft == NULL)
    return t->data;
  else
    return MinNode(t->pLeft);
}
int DoCaoCay(Tree t) {
  if (t == NULL)
    return 0;
  int d1 = DoCaoCay(t->pLeft);
  int d2 = DoCaoCay(t->pRight);
  return DoCaoCay(t->pRight) + DoCaoCay(t->pLeft) + 1;
}
TNode* SearchX(Tree t, int x) {
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
int DelX(Tree& t, int y) {
  if (t == NULL) return 0;
  else if (t->data > y) return DelX(t->pLeft, y);
  else if (t->data < y) return DelX(t->pRight, y);
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
      t->data = Q->data;
      DelX(t->pLeft, Q->data);
    }
  }
  return 1;
}
int sumTree(Tree t) {
  int s = 0;
  if (t == NULL) {
    return 0;
  }
  else {
    s += t->data;
    s += sumTree(t->pLeft);
    s += sumTree(t->pRight);
  }
  return s;
  return s;
}
int DemNode1Con(Tree t) {
  if (t == NULL) {
    int a = DemNode1Con(t->pLeft);
    int b = DemNode1Con(t->pRight);
    if (t->pLeft != NULL && t->pRight == NULL)
      return 1 + a + b;
    return a + b;
  }
  return 0;
}
int DemNode2Con(Tree t) {
  if (t == NULL)
    return 0;
  if (t->pLeft != NULL && t->pRight != NULL)
    return 1 + DemNode2Con(t->pLeft) + DemNode2Con(t->pRight);
  return DemNode2Con(t->pLeft) + DemNode2Con(t->pRight);
}
void OutPutK(Tree t, int k) {
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
//void SearchStandFor(Tree &pHuy,Tree&pTM)
//{
//	if(pTM->pLeft)
//		SearchStandFor(pHuy,pTM->pLeft);
//	else
//	{
//		pHuy->data=pTM->data;
//		pHuy=pTM;
//		pTM = pTM ->pRight;
//	}
//}
//void Remove(Tree &t,int x)
//{
//	if(t != NULL)
//	{
//		if(x<t->data)
//			Remove(t->pLeft,x);
//		else if(x>t->data)
//			Remove(t->pRight,x);
//		else
//		{
//			TNode * pHuy = t;
//			if(t->pLeft == NULL)
//				t=t->pRight;
//			else if (t->pRight == NULL)
//				t=t->pLeft;
//			else SearchStandFor(pHuy,t->pRight);
//			delete pHuy;
//		}
//	}
//}
//int Remove(Tree t,int x){
//	if(t==NULL)
//		return 0;
//	if(t->data>x)
//		return Remove(t->pLeft,x);
//	if(t->data<x)
//		return Remove(t->pRight,x);
//	TNode*p,f,rp;
//	p=t;
//	if(t->pLeft==NULL)
//		t=t->pRight;
//	else if(t->pRight==NULL)
//		t=t->pLeft;
//	else{
//		f=p;
//		rp=p->pRight;
//		while(rp->pLeft!=NULL){
//			f=rp;
//			rp=f->pLeft;
//		}
//		p->data=rp->data;
//		if(f==p)
//			f->pRight=rp->pRight;
//		else
//			f->pLeft=rp->pRight;
//		p=rp;
//	}
//	delete p;
//	return 1;
//}
//int TimMinTrai(Tree t)
//{
//	if(t->pLeft==NULL)
//		return NULL;
//	return MinNode(t->pLeft);
//}
//int TimMinPhai(Tree t)
//{
//	if(t->pRight==NULL)
//		return NULL;
//	return MinNode(t->pRight);
//}
int main() {
  int a[] = { 99,5,8,1,5,6,2,9,7,4 };
  int n = 10;
  Tree t;
  int x, y, k;
  TNode* p;
  Init(t);
  CreateBinaryTree(t, a, n);
  printf("\n\n\t Duyet NLR: "); NLR(t);
  printf("\n\n\t Duyet LNR: "); LNR(t);
  printf("\n\n\t Duyet LRN: "); LRN(t);
  printf("\n\n\t So Node La = %d", DemNodeLa(t));
  printf("\n\n\t Max = %d", MaxNode(t));

  printf("\n\n\t Do cao = %d", DoCaoCay(t));
  printf("\n\n\t Tong data cay la = %d ", sumTree(t));
  //	printf("\n\n Min Trai = %d", TimMinTrai(t));
  //	printf("\n\n Min Phai = %d", TimMinPhai(t));
  //	printf("\n\n\t Nhap data can xoa: ");
  //	scanf("%d",n);
  //	Remove(t,n);

  printf("\n\n\t Dem Node co 1 con = %d", DemNode1Con(t));
  printf("\n\n\t Dem Node co 2 con = %d", DemNode2Con(t));
  printf("\n\n\t Nhap tang k: ");
  scanf("%d", &k);
  printf("\n\n\t Xuat cac node tren tang k\n");
  OutPutK(t, k + 1);
  printf("\n\n\t Nhap y can xoa: ");
  scanf("%d", &y);
  if (DelX(t, y))
    printf("\n\n\t Xoa thanh cong\n");
  else
    printf("\nKhong tim thay %d can xoa\n", y);
  printf("\n\n\t\t\t\t Duyet cay sau khi xoa kieu NLR \n\n");
  printf("\n\n\t Duyet NLR: "); NLR(t);
  printf("\n\n\t\t\t\t Duyet cay sau khi xoa kieu LNR \n\n");
  printf("\n\n\t Duyet LNR: "); LNR(t);
  printf("\n\n\t\t\t\t Duyet cay sau khi xoa kieu LRN \n\n");
  printf("\n\n\t Duyet LRN: "); LRN(t);
  //	printf("\n\n\t In Node tren tang k = %d"); OutPutK(t,k);
  //	printf("\n\n\t Nhap x can tim: ");
  //	scanf("%d",&x);
  //	p = SearchX(t,x);
  //	if (p != NULL) 
  //		printf("\n\n\tTim thay %d trong cay\n", p->data);
  //    else 
  //		printf("\n\n\t%d khong co trong cay\n", x);

  //	printf("\n\n\tNhap y can xoa: ");
  //	scanf("%d",&y);
  //	if (DelX(t, y)) 
  //		printf("\n\n\tXoa thanh cong\n");
  //    else 
  //		printf("\n\n\tKhong tim thay %d can xoan", y);
  //	CreateBinaryTree(t, a, n);
  //	printf("\n\n\tDuyet NLR:"); NLR(t);
  //	printf("\n\n\tDuyet LNR:"); LNR(t);
  //	printf("\n\n\tDuyet LRN:"); LRN(t);
  printf("\n\n\n\n\n\n\n\n\n\n");
  return 0;
}
