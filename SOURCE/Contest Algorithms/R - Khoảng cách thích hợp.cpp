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
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vi v(n, 0);
        F(i, 0, n) cin >> v[i];
        sort(v.begin(), v.end());
        int l = 0, r = 1e9;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int prev = 0, cnt = 1;
            F(i, 1, n)
            {
                if(v[i] - v[prev] >= mid)
                {
                    ++cnt;
                    prev = i;
                }
            }
            if(cnt >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
