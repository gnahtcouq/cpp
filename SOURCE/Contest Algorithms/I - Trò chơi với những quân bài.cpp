// Created by Nguyễn Mạnh Quân

#include<stdio.h>

int main()
{
    int n, k, ans = 0, x;
    scanf("%d%d", &n, &k);
    const int sz = k;
    int a[sz] = {};
    while(n--)
    {
        scanf("%d", &x);
        ++a[x % k];
        while(1)
        {
            if(a[ans % k])
            {
                --a[ans % k];
                ++ans;
            }
            else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
