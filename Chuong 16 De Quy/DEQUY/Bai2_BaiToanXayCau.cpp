#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define pb push_back

const int HashMod=1125022017;
const int dx[4]= {0,1,0,-1};
const int dy[4]= {1,0,-1,0};
const int oo = 2e9;
const int nmax=2e5+9;

vector <int> v[nmax];
int n,q;
int nchild[nmax];
int depth[nmax];
int lab[nmax];
int pos[nmax];
int chain[nmax];
int IT[8*nmax];
int Lazy[8*nmax];
int cnt = 0;
void dfs(int u,int p)
{
    int m=-1;
    nchild[u]=1;
    for (int i=0; i<v[u].size(); i++)
    {
        int e=v[u][i];
        if (e==p)
            continue;
        depth[e]=depth[u]+1;
        lab[e]=u;
        dfs(e,u);
        nchild[u]+=nchild[e];
        if (m==-1 || nchild[v[u][m]]<nchild[e])
            m=i;
    }
    if (m!=-1)
        swap(v[u][m],v[u][0]);
}

void HLD(int u,int c)
{
    chain[u]=c;
    ++cnt;
    pos[u]=cnt;
    if (v[u][0]==lab[u])
        return ;
    HLD(v[u][0],c);
    for (int i=1; i<v[u].size(); i++)
    {
        int e=v[u][i];
        if (e==lab[u])
            continue;
        HLD(e,e);
    }
}

void Update(int id,int l,int r,int u, int v,int k)
{
    if (Lazy[id]!=-1)
    {
        IT[id]=Lazy[id]*(r-l+1);
        Lazy[id*2]=Lazy[id];
        Lazy[id*2+1]=Lazy[id];
        Lazy[id]=-1;
    }
    if (l>v || r<u)
        return ;
    //cout << IT[id] << " " << l << " " << r << " " << u << " " << v << endl;
    if (l>=u && r<=v)
    {
        IT[id]=k*(r-l+1);
        Lazy[id*2]=k;
        Lazy[id*2+1]=k;
        return;
    }
    int mid = (l+r)/2;
    Update(id*2,l,mid,u,v,k);
    Update(id*2+1,mid+1,r,u,v,k);
    IT[id]=IT[id*2]+IT[id*2+1];
}

int Query (int id,int l,int r,int u,int v)
{
    if (Lazy[id]!=-1)
    {
        IT[id]=Lazy[id]*(r-l+1);
        Lazy[id*2]=Lazy[id];
        Lazy[id*2+1]=Lazy[id];
        Lazy[id]=-1;
    }
    if (l>v || r<u)
        return 0;
    //cout << IT[id] << " " << id << " " << l << " " << r << " " << u << " " << v << endl;
    if (l>=u && r<=v)
        return IT[id];
    int mid = (l+r)/2;
    return Query(id*2,l,mid,u,v) + Query(id*2+1,mid+1,r,u,v);
}
void Update_(int x,int y)
{
    while (chain[x]!=chain[y])
    {
        //cout << x << " " << y << " " << pos[x] << " " << pos[y] << endl;
        if (depth[chain[x]]<depth[chain[y]])
        {
            Update(1,1,n,pos[chain[y]],pos[y],0);
            y=lab[chain[y]];
        }
        else
        {
            Update(1,1,n,pos[chain[x]],pos[x],0);
            x=lab[chain[x]];
        }
    }
    //cout << x << " " << y << " " << pos[x] << " " << pos[y] << endl;
    //cout << x << " " << y << endl;
    if (depth[x]>depth[y])
        Update(1,1,n,pos[y]+1,pos[x],0);
    if (depth[y]>depth[x])
        Update(1,1,n,pos[x]+1,pos[y],0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("Test.inp","r",stdin);
    //freopen("Test.out","w",stdout);
    cin >> n;
    for (int i=1; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,1);
    HLD(1,1);
    cin >> q;
    memset(Lazy,-1,sizeof(Lazy));
    Update(1,1,n,2,n,1);
    for (int i=1; i<=q; i++)
    {
        int x,y;
        cin >> x >> y;
        Update_(x,y);
    }

    cout << Query(1,1,n,2,n);
    return 0;
}
