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

ll C(ll k, ll n)
{
    ll res = 1;
    for(int i = 1; i <= k; ++i, --n) res = res * n / i;
    return res;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, x, tmp;
        ll ans = 0;
        cin >> n >> k;
        int dd[1000005] = {};
        vi v;
        F(i, 0, n)
        {
            cin >> x;
            ++dd[x];
            if(dd[x] == 1) v.pb(x);
        }
        sort(v.begin(), v.end());
        for(auto i : v)
        {
            tmp = k - i;
            if(tmp != i && dd[i] && dd[tmp] && binary_search(v.begin(), v.end(), tmp))
            {
                ans += dd[i] * dd[tmp];
                dd[i] = 0;
                dd[tmp] = 0;
            }
            else if(tmp == i) ans += C(2, dd[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
