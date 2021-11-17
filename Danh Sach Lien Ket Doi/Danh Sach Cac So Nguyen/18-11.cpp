#include <iostream>
using namespace std;

// 1. Khai bao cau truc du lieu DSLK don du lieu cac so nguyen

struct Node {
    int data;
    // struct Node *pNext;
    // struct Node *pPrev;
    Node *pNext;
    Node *pPrev; // Day la dieu khac biet voi DSLK don
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
    p->pPrev = NULL; // Khoi tao moi lien ket - day la dieu khac biet
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
        l.pHead->pPrev = p; // day la dieu khac biet
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
        p->pPrev = l.pTail; // day la dieu khac biet
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

void xuatDanhSach(LIST l){
    // for(int i = 0; i < n; i++)
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
    // for(NODE *p = l.pTail; p != NULL; p = p->pPrev){
        cout << p->data << " ";
    }
}

void giaiPhong(LIST &l){
    NODE *p; // Khai bao Node p
    while(l.pHead != NULL){
        p = l.pHead; // Cho p tro toi Head
        l.pHead = l.pHead->pNext; // Head tron sang thang ben canh
        delete p; // Giai phong p (cung chinh la giai phong Head ban dau)
    }
}

int tinhTong(LIST l){
    int sum = 0;
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        sum += p->data;
    }
    return sum;
}

void lietKeSoChan(LIST l){
    cout << "\nCac so chan co trong danh sach la: ";
    for(NODE *p=l.pHead; p!=NULL; p = p->pNext){
        if(p->data % 2 == 0){
            cout << p->data << " ";
        }
    }
}

void hoanVi(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void sapXep(LIST &l, char phanloai){
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

// them Node x vao dang sau Node q

// q x g

void themSau(LIST &l, NODE *x, NODE *q){
    // q != NULL
    // chay vong lap tim ra q
    for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
        if(p->data == q->data){
            // Tim thang nam dang sau
            NODE *g = p->pNext;
            x->pNext = g;
            g->pPrev = x;
            p->pNext = x;
            x->pPrev = p;
            return;
        }
    }
    if(l.pTail->data == q->data){
        themCuoi(l, x);
    }
}

// Them x vao dang sau tat ca cac so chan
void themSauTatCaSoChan(LIST &l, int phantuthem){
    for(NODE *p = l.pHead; p != l.pTail; p=p->pNext){
        if(p->data % 2 == 0){
            NODE *x = taoNode(phantuthem); // getNode o ngay ben trong de tao ra Node moi
            // them x vao sau p
            NODE *g = p->pNext;
            x->pNext = g;
            g->pPrev = x;
            p->pNext = x;
            x->pPrev = p;
            p = p->pNext; // bo qua khong xet phan tu vua them
        }
    }
    if(l.pTail->data % 2 == 0){
        NODE *x = taoNode(phantuthem); // getNode o ngay ben trong de tao ra Node moi
        themCuoi(l, x);
    }
}

// Them Node x vao truoc Node p
//     p
//    x
// A B C D E
//   q
void themTruoc(LIST &l, NODE *x, NODE *p){
    // Tim Node nam truoc Node p -> goi la Node q
    NODE *q;
    if(p->data == l.pHead->data){
        themDau(l, x);
        return;
    }
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data == p->data){
            NODE *q = k->pPrev;
            x->pNext = k;
            k->pPrev = x;
            q->pNext = x;
            x->pPrev = q;
            return;
        }
    }
}

void themTruocTatCaSoChan(LIST &l, int phantuthem){
    NODE *q = l.pHead;
    for(NODE *p = l.pHead->pNext; p != NULL; p=p->pNext){
        if(p->data % 2 == 0){
            NODE *q = p->pPrev;
            NODE *x = taoNode(phantuthem);
            x->pNext = p;
            p->pPrev = x;
            q->pNext = x;
            x->pPrev = q;
        }
    }
    // Xet rieng phan tu dau
    if(l.pHead->data % 2 == 0){
        NODE *g = taoNode(phantuthem);
        themDau(l,g);
    }
}

void xoaDau(LIST &l){
    if(l.pHead != NULL){
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if(l.pHead != NULL){
            l.pHead->pPrev = NULL;
        }
    }
}

// Xoa Node nam sau q
void xoaSauMotNode(LIST &l, NODE *q){
    for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
        if(p->data == q->data){
            // NODE can xoa goi la k
            NODE *k = p->pNext;
            p->pNext = k->pNext;
            k->pNext->pPrev = p;
            delete k;
            return;
        }
    }
}

void xoaCuoi(LIST &l){
    if(l.pHead->pNext == NULL){
        xoaDau(l);
        return;
    }
    NODE *p = l.pTail;
    (p->pPrev)->pNext = NULL;
    l.pTail = p->pPrev;
    delete p;
}

void xoaHetTatCaSoChan(LIST &l){
    NODE *truoc = l.pHead; // Node nam truoc
    for(NODE *p = l.pHead->pNext; p != l.pTail; p = p->pNext){
        if(p->data % 2 == 0){
            truoc = p->pPrev;
            // xoa p
            // tim Node nam truoc p va cho p tro toi Node nam sau p
            NODE *sau;
            sau = p->pNext;
            p->pPrev = sau;
            truoc->pNext = sau;
            sau->pPrev = truoc;
            delete p;
            p = truoc;
        }
    }
    if(l.pHead->data % 2 == 0){
        xoaDau(l);
    }
    if(l.pTail->data % 2 == 0){
        xoaCuoi(l);
    }
}

void suaCacSoChan(LIST &l, int sothaythe){
    for(NODE *p=l.pHead; p != NULL; p = p->pNext){
        if(p->data % 2 == 0){
            p->data = sothaythe;
        }
    }
}

int main(){
    LIST l;
    int n;
    cout << "\nBan muon nhap bao nhieu Node: ";
    cin >> n;
    nhapDanhSach(l, n);
    xuatDanhSach(l);

    NODE *q, *x;
    q = taoNode(2);
    x = taoNode(69);

    // cout << "\nThem 69 vao dang sau 2: ";
    // themSau(l,x,q);
    // xuatDanhSach(l);

    // cout << "\nThem x vao sau tat ca so chan: ";
    // themSauTatCaSoChan(l, 69);
    // xuatDanhSach(l);

    // cout << "\nThem 69 vao dang truoc 2: ";
    // themTruoc(l, x, q);
    // xuatDanhSach(l);

    // cout << "\nThem x vao truoc tat ca so chan: ";
    // themTruocTatCaSoChan(l, 69);
    // xuatDanhSach(l);

    // cout << "\nXoa dau danh sach: ";
    // xoaDau(l);
    // xuatDanhSach(l);

    // cout << "\nXoa Node nam sau 2: ";
    // xoaSauMotNode(l, q);
    // xuatDanhSach(l);

    // cout << "\nXoa cuoi danh sach: ";
    // xoaCuoi(l);
    // xuatDanhSach(l);

    // cout << "\nXoa het tat ca so chan: ";
    // xoaHetTatCaSoChan(l);
    // xuatDanhSach(l);

    int sothaythe;
    cout << "\nNhap so can thay the: ";
    cin >> sothaythe;
    cout << "\nSua cac so chan thanh so " << sothaythe << " la: ";
    suaCacSoChan(l,sothaythe);
    xuatDanhSach(l);

    giaiPhong(l);
    cout << endl;
    system("pause");
    return 0;
}