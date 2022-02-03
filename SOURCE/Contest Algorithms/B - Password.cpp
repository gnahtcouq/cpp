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
#define PI 3.141592653589793238
#define endl '\n'

bool a[300005];
 
int main()
{
    faster();
    int n, k;
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    int l = 1, r = 1, cnt = 0, ans = -1, tmpi = l, tmpj = r;
    while(r <= n && cnt < k)
    {
        if(!a[r]) cnt++;
        r++;
    }
    while(r <= n)
    {
        if(!a[r])
        {
            if(ans < r - l)
            {
                ans = r - l;
                tmpi = l;
                tmpj = r - 1;
            }
            FOR(i, l, r)
            {
                if(!a[i])
                {
                    l = i + 1;
                    break;
                }
            }
        }
        r++;
    }
    if(ans < r - l)
    {
        ans = r - l;
        tmpi = l;
        tmpj = r - 1;
    }
    l = tmpi;
    r = tmpj;
    cout << ans << endl;
    FOR(i, 1, l - 1) cout << a[i] << ' ';
    FOR(i, l, r) cout << 1 << ' ';
    FOR(i, r + 1, n) cout << a[i] << ' ';
    return 0;
}
