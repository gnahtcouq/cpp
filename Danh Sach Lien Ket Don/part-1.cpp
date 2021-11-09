/* 
7 buoc can ban luon phai co tren danh sach lien ket don

B1: Khai bao cau truc du lieu danh sach lien ket
B2: Khoi tao danh sach lien ket
B3: Tao Node trong danh sach lien ket
B4: Them dau/Them cuoi trong danh sach lien ket
B5: Viet ham InPut/OutPut
B6: Nhung xu ly yeu cau can co tren danh sach lien ket
B7: Giai phong danh sach lien ket

Lam demo tren danh sach lien ket don cac so nguyen


 */


#include <iostream>
using namespace std;

// B1: Khai bao cau truc du lieu danh sach lien ket
struct Node{
    int data;
    struct Node *pNext;
};
typedef struct Node NODE;

struct List{
    NODE *pHead, *pTail;
};
typedef struct List LIST;
/* ---------------------------------------------- */

// B2: Khoi tao danh sach lien ket
void init(LIST &l){
    l.pHead = l.pTail = NULL;
}

// B3: Tao Node trong danh sach lien ket
NODE* getNode(int DATA){
    NODE *p = new NODE; // khoi tao con tro p

    // Neu truong hop may tinh het bo nho
    if(p == NULL){
        cout << "\nKhong du bo nho de cap phat con tro";
        return NULL; // tra ve rong
    }
    p->data = DATA; // Dua data vao trong Node
    p->pNext = NULL; // Khoi tao moi lien ket
    return p; // Tra Node p ve
}

// B4: Them Node p vao dau/Them Node p vao cuoi trong danh sach lien ket
void addHead(LIST &l, NODE *p){
    // danh sach rong
    if(l.pHead == NULL){
        l.pHead = l.pTail = p; // p vua la dau vua la cuoi
    }
    else{
        p->pNext = l.pHead; // cho p tro toi dau danh sach
        l.pHead = p; // cap nhat lai dau danh sach
    }
}
void addTail(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        l.pTail -> pNext = p; // pTail tro Next toi p
        l.pTail = p; // cap nhat pTail chinh la p
    }
}
/* --------------------------------------------------- */

// B5: Viet ham InPut/OutPut
void inPut(LIST &l){
    init(l); // khoi tao danh sach

    int n;
    cout << "\nNhap vao so luong phan tu trong danh sach: ";
    cin >> n;

    // vong lap chay n lan, moi lan nhap du lieu cho 1 Node
    for(int i = 1; i <= n; i++){
        int data;
        cout << "\nNhap vao data: ";
        cin >> data;

        // Dong goi data vao Node
        NODE *p; // khai bao
        p = getNode(data); // cho con tro p tro toi Node duoc tao ra
        //addHead(l,p); // them Node p vao dau danh sach
        addTail(l,p);
    }
}
void outPut(LIST l){
    // for(int i=0; i<n; i++)
    for(NODE *p = l.pHead; p != NULL; p=p->pNext){
        cout << p->data << " ";
    }
}
/* ------------------------------------------------- */

// B6: Nhung xu ly yeu cau can co tren danh sach lien ket

// Tinh tong danh sach
int tinhTong(LIST l){
    // for(int i=0;i<n;i++)
    int tong = 0;
    for(NODE *p=l.pHead; p!=NULL; p=p->pNext){
    // for(NODE *p=l.pHead; p; p=p->pNext)
        tong += p->data;
    }
    return tong;
}

// Liet ke cac so chan trong danh sach
void lietKeSoChan(LIST l){
    cout << "\nCac so chan co trong danh sach la: ";
    for(NODE *p=l.pHead; p!=NULL; p=p->pNext){
        if(p->data % 2 == 0){
            cout << p->data << " ";
        }
    }
}

// Sap xep danh sach lien ket don tang dan/giam dan
void hoanVi(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void sapXep(LIST &l, char phanloai){
    /*
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if(a[i] > a[j])
                hoanVi(a[i],a[j]);
        }
    }
     */
    for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
        for(NODE *q = p->pNext; q!= NULL; q = q->pNext){
            if(phanloai == 't'){
                if(p->data > q->data)
                    hoanVi(p->data,q->data);
            }
            else if(phanloai = 'g'){
                if(p->data < q->data)
                    hoanVi(p->data,q->data);
            }
        }
    }
}


// B7: Giai phong danh sach lien ket
void giaiPhong(LIST &l){
    NODE *p;
    while (l.pHead != NULL){
        p = l.pHead; // Cho con tro p tro vao pHead
        l.pHead = l.pHead -> pNext; // pHead duoc tro sang Node ben canh
        delete p; // giai phong con tro
    }
}

int main(){
    LIST l; // khai bao danh sach
    inPut(l);
    outPut(l);

    int tong = tinhTong(l);
    cout << "\nTong = " << tong;

    lietKeSoChan(l);

    cout << "\nDanh sach sau khi sap xep tang la: ";
    sapXep(l,'t');
    outPut(l);
    cout << "\nDanh sach sau khi sap xep giam la: ";
    sapXep(l,'g');
    outPut(l);

    giaiPhong(l); // giai phong danh sach
    // cout << "\npTail = " << l.pTail->data;

    cout << endl;
    return 0;
}