#include <iostream>
#include <stdlib.h>
using namespace std;

void nhapMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap vao a[" << i << "]= ";
        cin >> a[i];
    }
}
void xuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int tinhTong(int *a, int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[i];
    }
    return tong;
}
int timMax_1(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int timMin(int *a, int n)
{
    int *min;    // khai bao con tro
    min = &a[0]; // cho con tro Min tro toi o dau tien
    for (int i = 1; i < n; i++)
    {
        if (a[i] < *min)
            min = &a[i]; // cho con tro Min tro toi dia chi moi
    }
    return *min;
}
int *timMin_2(int *a, int n)
{
    int *min; // khai bao con tro
    min = &a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < *min)
            min = &a[i]; // cho con tro tro toi dia chi moi
    }
    return min;
}

/* 
int a,b;
hoanVi_1(a,b);
 
int *c, *d;
hoanVi_1(*c,*d); 
 */
void hoanVi_1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* 
int a,b;
hoanVi_2(&a,&b);

int *c, *d;
hoanVi_2(c,d);
 */
void hoanVi_2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sapXepMang(int *a, int n, char phanloai)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // sap tang dan
            if (phanloai == 't' || phanloai == 'T')
            {
                if (a[i] > a[j])
                    // hoanVi_1(a[i],a[j]);
                    hoanVi_2(&a[i], &a[j]);
            }
            if (phanloai == 'g' || phanloai == 'G')
            {
                if (a[i] < a[j])
                    // hoanVi_1(a[i],a[j]);
                    hoanVi_2(&a[i], &a[j]);
            }
        }
    }
}

// void themPhanTu(int a[], int &n, int vitrithem, int phantuthem){
//     for(int i=n-1; i>=vitrithem ; i--){
//         a[i+1] = a[i];
//     }
//     a[vitrithem] = phantuthem;
//     n++;
// }

/* 
LUU Y: Khi ta muon thay doi lai vung nho cho con tro
thong qua 1 ham con thi tham so con tro truyen vao ham phai la con tro tham chieu
de cap nhat lai duoc vung nho duoi ham main
 */
void themPhanTu(int *&a, int &n, int vitrithem, int phantuthem)
{
    realloc(a, (n + 1) * sizeof(int)); // cap du ra 1 o

    for (int i = n - 1; i >= vitrithem; i--)
    {
        a[i + 1] = a[i];
    }
    a[vitrithem] = phantuthem;
    n++;
}
void xoaPhanTu(int *&a, int &n, int vitrixoa)
{
    for (int i = vitrixoa + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    realloc(a, (n - 1) * sizeof(int));
    // n--;
    // realloc(a, n * sizeof(int));
}

// them vao sau cac so chan so 69
void themNhieu(int *&a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            themPhanTu(a, n, i + 1, 69);
            i++; // bo qua phan tu vua them 
        }
    }
}
void themNhieu_69(int *&a, int &n, int sophantuthem)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            for(int j=1; j<=sophantuthem;j++){
                themPhanTu(a, n, i + 1, 69);
                i++; // bo qua phan tu vua them
            }
        }
    }
}

void xoaTatCaSoChan(int *&a, int &n){
    for(int i=0; i<n; i++){
        if(a[i] % 2 ==0){
            xoaPhanTu(a,n,i);
            i--; // de lui lai xet het duoc tat ca
        }
    }
}

int main()
{
    int n;
    do
    {
        cout << "\nNhap vao so luong phan tu n = ";
        cin >> n;
        if (n < 0)
        {
            cout << "\nGia tri n khong hop le. Xin kiem tra lai";
        }
    } while (n < 0);

    // cap phat bo nho cho con tro
    // int *a = (int *)malloc(n * sizeof(int));
    // int *a = (int *)calloc(n, sizeof(int));
    int *a = (int *)realloc(NULL, n * sizeof(int));

    nhapMang(a, n);
    xuatMang(a, n);

/*     int tong = tinhTong(a, n);
    cout << "\nTong = " << tong;

    int max = timMax_1(a, n);
    cout << "\nMax = " << max;

    int min = timMin(a, n);
    cout << "\nMin = " << min;

    int min_2 = *timMin_2(a, n);
    cout << "\nMin 2 = " << min_2;

    // int *min = timMin_2(a,n);
    // cout << "\nmin = " << min;

    sapXepMang(a, n, 't');
    cout << "\nSap xep giam dan: ";
    xuatMang(a, n);

    sapXepMang(a, n, 'g');
    cout << "\nSap xep tang dan: ";
    xuatMang(a, n);

    cout << endl;
    int vitrithem = 2;
    int phantuthem = 69;
    themPhanTu(a, n, vitrithem, phantuthem);
    xuatMang(a, n);

    int vitrixoa = 3;
    xoaPhanTu(a, n, vitrixoa);
    cout << "\nMang sau khi xoa la: ";
    xuatMang(a, n);

    themNhieu(a,n);
    cout << "\nThem vao dang sau cac so chan so 69 la: ";
    xuatMang(a,n);
    cout << endl;

    themNhieu_69(a,n,3);
    xuatMang(a,n); */

    xoaTatCaSoChan(a,n);
    cout << "\nXoa het cac so chan la: ";
    xuatMang(a,n);

    free(a); // giai phong bo nho

    cout << endl;
    return 0;
}