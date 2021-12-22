#include <iostream>
using namespace std;
#define MAX 1000
int n;
int a[MAX][MAX]= {1};

// Dùng mảng 2 chiều
int f1(int n)
{
//	a[0][0]=1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=n; j++)
            if(j<i)
                a[i][j] = a[i-1][j];
            else
                a[i][j] = a[i-1][j] + a[i][j-i];
    return a[n][n];

}
// Dung 2 mang 1 chieu
int f2(int n)
{
    int next[n+1] = {0}, cur[n+1]= {1};
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=n; j++)
            if(j<i)
                next[j] = cur[j];
            else
                next[j] = cur[j] + next[j-i];
        for (int k=0; k<=n; k++)
            cur[k] = next[k];
    }
    return cur[n];
}

// Dung 1 mang mot chieu
int f3(int n)
{
    int f[n+1]= {1};
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            f[j] = f[j] + f[j-i];
    return f[n];
}

// Dung ky thuat de quy
int f4(int m, int n)
{
    if(!m) {
        if(!n)
            return 1;
        return 0;
    } else {
        if(m>n)
            return f4(m-1,n);
        return f4(m-1,n) + f4(m,n-m);
    }
}

// Dung De quy co nho
int f5(int m, int n)
{
    if (!m)
        if(!n)
            a[m][n]=1;
        else
            a[m][n]=0;
    else {
        if (m>n)
            a[m][n] = f5(m-1,n);
        else
            a[m][n] = f5(m-1,n) + f5(m,n-m);
    }
    return a[m][n];
}
int main()
{
    cout << "\n\n Nhap n: ";
    cin >> n;

    cout << "\n\n Ket qua: " << f4(n,n);

    return 0;
}
