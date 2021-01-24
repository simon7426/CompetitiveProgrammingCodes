#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; ///4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};///8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; ///Hexagonal Direction

inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%I64d",&x); return x;}
inline double ind() { double x;scanf("%lf",&x);return x;}

int gcd(int a,int b) { return b==0 ? a:gcd(b,a%b);}
int power( int x, int n)
{
    if(n==0)return 1;
    else if(n%2==0)
    {
        int y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}
//abcdefghijklmnopqrstuvwxyz//
int n,m,tot;
const int maxn = 100010;
const int K = 25;
vi g[maxn];
int dep[maxn],pa[maxn];
int centpar[maxn];
int lcapar[maxn][K];
int si[maxn];
int dead[maxn];
int ans[maxn];
void dfsdep(int u,int p,int d)
{
    dep[u] = d;
    pa[u] = p;
    int v,i;
    for(i=0;i<g[u].size();i++)
    {
        v = g[u][i];
        if(v==p) continue;
        dfsdep(v,u,d+1);
    }
}
void lcaprepo()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=0;1 << j <n;j++)
            lcapar[i][j]=-1;
    for(i=1;i<=n;i++)
    {
        lcapar[i][0] = pa[i];
    }
    for(j=1;1<<j < n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(lcapar[i][j-1]!=-1)
                lcapar[i][j]=lcapar[lcapar[i][j-1]][j-1];
        }
    }
}
void dfssubtree(int u,int p)
{
    si[u] = 1;
    tot++;
    int i,v;
    for(i=0;i<g[u].size();i++)
    {
        v = g[u][i];
        if(v==p) continue;
        dfssubtree(v,u);
        si[u]+=si[v];
    }
}
int findcentroid(int u,int p)
{
    int i,v;
    for(i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v!=p && !dead[v] && si[v]>tot/2)
            return findcentroid(v,u);
    }
    return u;
}
void centdecompose(int u,int p)
{
    tot = 0;
    dfssubtree(u,u);
    int centroid = findcentroid(u,u);
    if(p==-1) p=centroid;
    centpar[centroid]=p;
    dead[centroid] = 1;
    int i,v;
    for(i=0;i<g[centroid].size();i++)
    {
        v=g[centroid][i];
        if(dead[v]) continue;
        centdecompose(v,centroid);
    }
    g[centroid].clear();
}
int lca(int p,int q)
{
    int tmp,log,i;
    if(dep[p]<dep[q])
    {
        tmp=p;
        p=q;
        q=tmp;
    }
    for(log=1;(1<<log) <=dep[p];log++);
    log--;
    for(i=log;i>=0;i--)
    {
        if(dep[p]-(1<<i)>=dep[q])
            p=lcapar[p][i];
    }
    if(p==q)
        return p;
    for(i=log;i>=0;i--)
    {
        if(lcapar[p][i]!=-1 && lcapar[p][i]!=lcapar[q][i])
        {
            p=lcapar[p][i];
            q=lcapar[q][i];
        }
    }
    return pa[p];
}
int dist(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void update(int u)
{
    int x=u;
    while(1)
    {
        ans[x]=min(ans[x],dist(x,u));
        if(x==centpar[x]) break;
        x=centpar[x];
    }
}
int query(int u)
{
    int x=u;
    int res=100010;
    while(1)
    {
        res=min(res,ans[x]+dist(x,u));
        if(x==centpar[x]) break;
        x=centpar[x];
    }
    return res;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfsdep(1,1,0);
    lcaprepo();
    centdecompose(1,-1);
    for(int i=1;i<=n;i++) ans[i] = 100010;
    update(1);
    while(m--)
    {
        int ty,x;
        scanf("%d%d",&ty,&x);
        if(ty==1) update(x);
        else
        {
            printf("%d\n",query(x));
        }
    }
}

