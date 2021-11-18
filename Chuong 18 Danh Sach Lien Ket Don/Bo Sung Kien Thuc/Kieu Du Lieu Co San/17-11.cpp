#include <iostream>
using namespace std;

// 1. Khai bao cau truc du lieu DSLK don du lieu cac so nguyen

struct Node {
    int data;
    // struct Node *pNext;
    Node *pNext;
};
//typedef struct Node NODE;
typedef Node NODE;

struct List {
    NODE *pHead;
    NODE *pTail;
};
// typedef struct List LIST;
typedef List LIST;

// 2. Khoi tao DSLK don

void khoiTao(LIST &l){
    l.pHead = l.pTail = NULL;
}

// 3. Tao Node trong danh sach
NODE* taoNode(int x){ // x chinh la du lieu dua vao data
    // Cap phat 1 Node
    NODE *p = new NODE;

    // Neu truong hop may tinh het bo nho
    if(p == NULL){
        return NULL; // tra ve rong
    }

    p->data = x; // Luu x vao data
    p->pNext = NULL; // Khoi tao moi lien ket
    return p; // Tra Node p ve
}

// 4. Them Node (them dau/them cuoi)

// 1 2 3 4 5 : Them cuoi
// 5 4 3 2 1 : Them dau

// Them Node p vao dau danh sach
void themDau(LIST &l, NODE *p){
    if(l.pHead == NULL){ // Tuc la danh sach bi rong
        l.pHead = l.pTail = p;
    }
    else{
        p->pNext = l.pHead; // p quang day de tham gia vao danh sach
        l.pHead = p; // p chinh thuc da dung dau danh sach
    }
}

// Them Node p vao cuoi danh sach
void themCuoi(LIST &l, NODE *p){
    if(l.pHead == NULL){ // Tuc la danh sach bi rong
        l.pHead = l.pTail = p;
    }
    else{
        l.pTail->pNext = p; // l.pTail quang day noi voi p
        l.pTail = p;
    }
}

// 5. Nhap du lieu cho danh sach
void nhapDanhSach(LIST &l, int n){
    // int n;
    // cout << "\nBan muon nhap bao nhieu Node: ";
    // cin >> n;

    khoiTao(l); // Khoi tao danh sach

    for(int i = 1; i <= n; i++){
        // Moi lan vong lap chay la ta nhap 1 Node
        int x;
        cout << "\nNhap vao data: ";
        cin >> x;

        NODE *p = taoNode(x); // Dua data vao Node p, tao ra node p
        themCuoi(l, p); // Them Node p vao cuoi danh sach
        // themDau(l, p);
    }
}

// Them 1 Node p vao sau 1 Node q
void themSau_q(LIST &l, NODE *p, NODE *q){
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data == q->data){ // Tim thay q
            NODE *g = k->pNext;
            k->pNext = p;
            p->pNext = g;
            return; // Ket thuc
        }
    }
}

/* 
    Xoa dau
    Xoa cuoi
    Xoa sau 1 Node bat ky
*/

void xoaDau(LIST &l){
    NODE *p = l.pHead; // p tro vao dau
    l.pHead = l.pHead->pNext; // dau tron sang ben canh
    delete p; // giai phong p
}

// Dau tien tim ra Node truoc Tail la cai gi
// Cho Tail = cai Node do
// Cap nhat pTail -> pNext = NULL
// Xoa
void xoaCuoi(LIST &l){
    NODE *p; // p se la Node nam truoc Tail tim thay
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k == l.pTail){
            l.pTail = p;
            l.pTail->pNext = NULL;
            delete k;
            return;
        }
        p = k;
    }
}

// Xoa Node g nam sau Node q trong danh sach
void xoaSau_q(LIST &l, NODE *q){
    NODE *g; // Node nam sau q
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        // tim q
        if(k->data == q->data){ // q bay gio chinh la k
            g = k->pNext;
            k->pNext = g->pNext; // <- xac dinh duoc k nam sau q thi
            delete g;
            return;
        }
    }
}

void xoaNodeKhoaBatKy(LIST &l, int x){
    if(l.pHead->data == x){
        xoaDau(l);
        return;
    }
    if(l.pTail->data == x){
        xoaCuoi(l);
        return;
    }

    NODE *q;
    // Neu Node can xoa khong phai dau/cuoi
    // -> Tim ra Node nam truoc Node co khoa can xoa
    // -> Goi ham xoa Node sau cai Node vua tim thay
    for(NODE *g = l.pHead; g != NULL; g = g->pNext){
        if(g->data == x){
            xoaSau_q(l, q);
            return;
        }
        q = g;
    }
}

// Tim thay return 1, khong thay return 0
int timKiem(LIST l, int x){
    for(NODE *q = l.pHead; q != NULL; q = q->pNext){
        if(q->data == x)
            return 1;
    }
    return 0;
}


void giaiPhong(LIST &l){
    NODE *p; // Khai bao Node p
    while(l.pHead != NULL){
        p = l.pHead; // Cho p tro toi Head
        l.pHead = l.pHead->pNext; // Head tron sang thang ben canh
        delete p; // Giai phong p (cung chinh la giai phong Head ban dau)
    }
}

void xuatDanhSach(LIST l){
    // for(int i = 0; i < n; i++)
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        cout << p->data << " ";
    }
}

int timMax(LIST l){
    
    /*
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max)
            max = a[i];
    }
    */

    int max = l.pHead->data;
    for(NODE *p = l.pHead->pNext; p != NULL; p = p->pNext){
        if(p->data > max){
            max = p->data;
        }
    }
    return max;
}

void hoanVi(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sapXep(LIST &l){

    
    /* for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j])
                hoanVi(a[i], a[j]);
        }
    } */

    for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
        for(NODE *q = p->pNext; q != NULL; q = q->pNext){
            if(p->data > q->data)
                hoanVi(p->data, q->data);
        }
    }
}

int tinhTong(LIST l){
    int sum = 0;
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        sum += p->data;
    }
    return sum;
}


int main(){
    LIST l;
    int n;
    cout << "\nBan muon nhap bao nhieu Node: ";
    cin >> n;
    nhapDanhSach(l, n);
    xuatDanhSach(l);

    // int max = timMax(l);
    // cout << "\nMax la: " << max;

    // sapXep(l);
    // cout << "\nDanh sach sau khi sap xep la: ";
    // xuatDanhSach(l);

    // int tong = tinhTong(l);
    // float tbc = (float)tong/n;
    // cout << "\nTrung binh cong = " << tbc;


    // int q, p;
    // cout << "\nNhap q: ";
    // cin >> q;

    // NODE *Q = taoNode(q);

    // cout << "\nNhap p: ";
    // cin >> p;

    // NODE *P = taoNode(p);

    // themSau_q(l, P, Q);
    // cout << "\nDanh sach sau khi them: ";
    // xuatDanhSach(l);

    // xoaDau(l);
    // cout << "\nDanh sach sau khi xoa dau: ";
    // xuatDanhSach(l);

    // xoaCuoi(l);
    // cout << "\nDanh sach sau khi xoa cuoi: ";
    // xuatDanhSach(l);

    // int q;
    // cout << "\nNhap q: ";
    // cin >> q;

    // NODE *Q = taoNode(q);

    // xoaSau_q(l, Q);
    // xuatDanhSach(l);

    // int x;
    // cout << "\nNhap khoa bat ky: ";
    // cin >> x;
    // xoaNodeKhoaBatKy(l, x);
    // cout << "\nDanh sau sau khi xoa la: ";
    // xuatDanhSach(l);

    int x;
    cout << "\nNhap khoa bat ky: ";
    cin >> x;
    
    int check = timKiem(l, x);
    if(check == 1)
        cout << "\nTim thay";
    else
        cout << "\nKhong tim thay";


    giaiPhong(l);
    cout << endl;
    system("pause");
    return 0;
}