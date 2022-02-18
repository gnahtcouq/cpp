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

bool check(ll a, ll b, ll k, ll m, ll n, ll mid)
{
    return mid * a -  (mid / k) * a + mid * b - (mid / m) * b >= n;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, k, m, n;
        cin >> a >> k >> b >> m >> n;
        ll l = 0, r = 1e9, ans = 0, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(check(a, b, k, m, n, mid))
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
