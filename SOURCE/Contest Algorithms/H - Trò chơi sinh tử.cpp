// Created by Nguyễn Mạnh Quân

#include<stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(n > m) swap(&n, &m);
        long long sum = n + m;
        if(sum % 3 == 0 && n << 1 >= m) printf("MAY SURVIVE\n");
        else printf("MAY DIE\n");
    }
    return 0;
}
