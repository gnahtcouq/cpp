/* 
7 buoc can ban luon phai co tren danh sach lien ket don

B1: Khai bao cau truc du lieu danh sach lien ket
B2: Khoi tao danh sach lien ket
B3: Tao Node trong danh sach lien ket
B4: Them dau/Them cuoi trong danh sach lien ket
B5: Viet ham InPut/OutPut
B6: Nhung xu ly yeu cau can co tren danh sach lien ket
B7: Giai phong danh sach lien ket

 */


#include <iostream>
using namespace std;

// B1: Khai bao cau truc du lieu danh sach lien ket
struct Node{
    int data;
    struct Node *pNext;
};
typedef struct Node NODE; // doi struct Node thanh NODE

struct List{
    NODE *pHead, *pTail;
};
typedef struct List LIST; // doi struct List thanh LIST
/* ---------------------------------------------- */

void init(LIST &l);
NODE* getNode(int DATA);
void addHead(LIST &l, NODE *p);
void addTail(LIST &l, NODE *p);
void inPut(LIST &l);
void outPut(LIST l);
int tinhTong(LIST l);
void lietKeSoChan(LIST l);
void hoanVi(int &x, int &y);
void sapXep(LIST &l, char phanloai);
void themSau(LIST &l, NODE *x, NODE *q);
void themSauTatCaSoChan(LIST &l, int phantuthem);
void themTruoc(LIST &l, NODE *x, NODE *p);
void themTruocTatCaSoChan(LIST &l, int phantuthem);
void xoaDau(LIST &l);
void xoaSauMotNode(LIST &l, NODE *q);
void xoaCuoi(LIST &l);
void xoaHetTatCaSoChan(LIST &l);
void suaCacSoChan(LIST &l, int sothaythe);
void giaiPhong(LIST &l);

int main(){
    LIST l; // khai bao danh sach
    inPut(l);
    outPut(l);

/*     int tong = tinhTong(l);
    cout << "\nTong = " << tong;

    lietKeSoChan(l);

    cout << "\nDanh sach sau khi sap xep tang la: ";
    sapXep(l,'t');
    outPut(l);
    cout << "\nDanh sach sau khi sap xep giam la: ";
    sapXep(l,'g');
    outPut(l); */

    // Them 69 vao dang sau 2
    NODE *q, *x;
    q = getNode(2);
    x = getNode(69);

/*     cout << "\nThem 69 vao dang truoc 2: ";
    themTruoc(l, x, q);
    outPut(l); */

/*     cout << "\nThem x vao truoc tat ca so chan: ";
    themTruocTatCaSoChan(l, 69);
    outPut(l); */

/*     cout << "\nXoa dau danh sach: ";
    xauDau(l);
    outPut(l); */

/*     cout << "\nXoa Node nam sau 2: ";
    xoaSauMotNode(l,q);
    outPut(l); */

/*     cout << "\nXoa het tat ca so chan: ";
    xoaHetTatCaSoChan(l);
    outPut(l); */

/*     int sothaythe;
    cout << "\nNhap so can thay the: ";
    cin >> sothaythe;
    cout << "\nSua cac so chan thanh so " << sothaythe << " la: ";
    suaCacSoChan(l,sothaythe);
    outPut(l); */

    giaiPhong(l); // giai phong danh sach

    cout << endl;
    return 0;
}



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

// them Node x vao dang sau Node q
void themSau(LIST &l, NODE *x, NODE *q){
    // q != NULL
    // chay vong lap tim ra q
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        if(p->data == q->data){
            // Tim thang nam dang sau
            NODE *g = p->pNext;
            x->pNext = g;
            p->pNext = x;
            return;
        }
    }
}

// Them x vao dang sau tat ca cac so chan
void themSauTatCaSoChan(LIST &l, int phantuthem){
    for(NODE *p = l.pHead; p != NULL; p=p->pNext){
        if(p->data % 2 == 0){
            NODE *x = getNode(phantuthem); // getNode o ngay ben trong de tao ra Node moi
            // them x vao sau p
            NODE *g = p->pNext;
            x->pNext = g;
            p->pNext = x;
            p = p->pNext; // bo qua khong xet phan tu vua them
        }
    }
}

// Them Node x vao truoc Node p
void themTruoc(LIST &l, NODE *x, NODE *p){
    // Tim Node nam truoc Node p -> goi la Node q
    NODE *q;
    if(p->data == l.pHead->data){
        addHead(l, x);
        return;
    }
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data == p->data){
            x->pNext = k;
            q->pNext = x;
            return;
        }
        q = k;
    }
}

void themTruocTatCaSoChan(LIST &l, int phantuthem){
    NODE *q = l.pHead;
    for(NODE *p = l.pHead->pNext; p != NULL; p=p->pNext){
        if(p->data % 2 == 0){
            NODE *x = getNode(phantuthem);
            x->pNext = p;
            q->pNext = x;
        }
        q = p;
    }
    // Xet rieng phan tu dau
    if(l.pHead->data % 2 == 0){
        NODE *g = getNode(phantuthem);
        addHead(l,g);
    }
}

void xoaDau(LIST &l){
    if(l.pHead != NULL){
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

// Xoa Node nam sau q
void xoaSauMotNode(LIST &l, NODE *q){
    for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
        if(p->data == q->data){
            // NODE can xoa goi la k
            NODE *k = p->pNext;
            p->pNext = k->pNext;
            delete k;
        }
    }
}

void xoaCuoi(LIST &l){
    NODE *truoc; // Node truoc
    for(NODE *p = l.pHead; p != NULL; p = p->pNext){
        if(p == l.pTail){
            truoc->pNext = NULL;
            l.pTail = truoc;
            delete p;
            return;
        }
        truoc = p;
    }
}

// 2 4 6 7 8
void xoaHetTatCaSoChan(LIST &l){
    NODE *truoc = l.pHead; // Node nam truoc
    for(NODE *p = l.pHead->pNext; p != l.pTail; p = p->pNext){
        if(p->data % 2 == 0){
            // xoa p
            // tim Node nam truoc p va cho p tro toi Node nam sau p
            NODE *sau;
            sau = p->pNext;
            truoc->pNext = sau;
            delete p;
            p = truoc;
        }
        truoc = p;
    }
    if(l.pHead->data % 2 == 0){
        xoaDau(l);
    }
    if(l.pTail->data % 2 == 0){
        xoaCuoi(l);
    }
}

// sua tat cac cac so chan trong danh sach thanh so 69
void suaCacSoChan(LIST &l, int sothaythe){
    for(NODE *p=l.pHead; p != NULL; p = p->pNext){
        if(p->data % 2 == 0){
            p->data = sothaythe;
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
        return;
    }
}