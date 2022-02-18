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

bool check(int a[], int n, int k, int x)
{
    int tmp, cnt = 0;
    F(i, 1, n)
    {
        tmp = a[i] - a[i - 1];
        if(tmp > x)
        {
            if(tmp % x) cnt += tmp / x;
            else cnt += tmp / x - 1;
            if(cnt > k) return 0;
        }
    }
    return cnt <= k;
}

int main()
{
    faster();
    int t;
    cin >> t;
    FOR(i, 1, t)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        F(i, 0, n) cin >> a[i];
        if(a[0] == a[n - 1])
        {
            cout << 0 << endl;
            continue;
        }
        int l = 1, r = 1e9, ans = 0, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(check(a, n, k, mid))
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
