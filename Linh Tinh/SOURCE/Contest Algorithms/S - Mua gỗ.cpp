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

int main()
{
    faster();
    int n, m;
    cin >> n >> m;
    vi v(n);
    F(i, 0, n) cin >> v[i];
    int l = 1, r = 2000000000;
    int ans = 0;
    sort(v.begin(), v.end(), greater<int>());
    while(l <= r)
    {
        int mid = (l + r) / 2;
        ll sum = 0;
        F(i, 0, n)
        {
            if(v[i] > mid) sum += v[i] - mid;
            else break;
        }
        if(sum >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
