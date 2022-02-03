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
    ll ans = 1;
    FOR(i, 1, k)
    {
        ans = ans * n / i;
        n--;
    }
    return ans;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << C(k, n) << endl;
    }
    return 0;
}
