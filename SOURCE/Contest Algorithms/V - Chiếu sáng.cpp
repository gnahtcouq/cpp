// Created by Nguyễn Mạnh Quân

#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define endl '\n'

bool check(int a[], int b[], int n, int m, int x)
{
    F(i, 0, n)
    {
        bool check = 1;
        F(j, 0, m)
        {
            if(abs(a[i] - b[j]) <= x)
            {
                check = 0;
                break;
            }
        }
        if(check) return 0;
    }
    return 1;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        F(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int b[m];
        F(i, 0, m) cin >> b[i];
        int l = 0, r = 1e9, ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(a, b, n, m, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
