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
const int inf2=0x3f3f3f3f;
struct Edge
{
    int to;
    int capa;
    int next;
}edge[100010];

int source,sink;
int cnt;
int head[1010];
int dis[1010];
int vis[1010];
int dep[1010];

void init()
{
    mem(head,-1);
    cnt=0;
    return;
}

void add(int u,int v,int cap)
{
    edge[cnt].to=v;
    edge[cnt].capa=cap;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].to=u;
    edge[cnt].capa=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
    return;
}

int bfs()
{
    queue<int> q;
    q.push(source);
    mem(dep,-1);
    dep[source]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=head[node];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].capa>0&&dep[v]==-1)
            {
                dep[v]=dep[node]+1;
                if(v==sink)return 1;
                q.push(v);
            }
        }
    }
    return dep[sink]!=-1;
}

int dfs(int node,int minf)
{
    if(node==sink || minf==0)
    {
        return minf;
    }
    int r=0;
    for(int i=head[node];~i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dep[v]==dep[node]+1&&edge[i].capa>0)
        {
            int tmp=dfs(v,min(edge[i].capa,minf));
            if(tmp>0)
            {
                edge[i].capa-=tmp;
                edge[i^1].capa+=tmp;
                r+=tmp;
                minf-=tmp;
                if(!minf) break;
            }
        }
    }
    if(!r) dep[node]=-1;
    return r;
}

int dinic()
{
    int mf=0;
    while(bfs())
    {
        mf+=dfs(source,inf2);
    }
    return mf;
}

int main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        init();
        int n,m,u,v,w;
        n=in(),m=in();
        source=1,sink=n+n;
        add(source,source+n,inf2);
        add(n,sink,inf2);
        for(int i=2;i<=n-1;i++)
        {
            w=in();
            add(i,i+n,w);
        }
        for(int i=0;i<m;i++)
        {
            u=in(),v=in(),w=in();
            add(u+n,v,w);
            add(v+n,u,w);
        }
        printf("Case %d: %d\n",tc,dinic());
    }
    return 0;
}
/*
2
4 4
2 5
1 2 3
1 3 3
2 4 1
3 4 3
4 4
2 2
1 2 3
1 3 3
2 4 1
3 4 3
*/

