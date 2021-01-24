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
struct edge
{
    int to,nxt;
}ed[600010];
int head[100010],cnt=-1;
bool use[100010],vis[600010];
void add(int u,int v)
{
    ed[++cnt].to=v;
    ed[cnt].nxt=head[u];
    head[u]=cnt;
    ed[++cnt].to=u;
    ed[cnt].nxt=head[v];
    head[v]=cnt;
}
int tin[100010],low[100010],timer=0;
void tarjan(int x,int id)
{
    tin[x]=low[x]=++timer;
    for(int i=head[x];~i;i=ed[i].nxt)
    {
        int v=ed[i].to;
        if(!tin[v])
        {
            tarjan(v,i);
            low[x]=min(low[x],low[v]);
            if(low[v]>tin[x]){printf("0\n");exit(0);}
        }
        else if(i!=(id^1))low[x]=min(low[x],tin[v]);
    }
}
void dfs(int x)
{
    if(use[x]) return;
    use[x]=1;
    for(int i=head[x];~i;i=ed[i].nxt)
    {
        if(vis[i])continue;
        vis[i]=vis[i^1]=true;
        printf("%d %d\n",x,ed[i].to);
        dfs(ed[i].to);
    }
}
int n,m;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    mem(head,-1);
    n=in(),m=in();
    int x,y;
    for(int i=0;i<m;i++)
    {
        x=in(),y=in();
        add(x,y);
    }
    tarjan(ed[0].to,-1);
    dfs(ed[0].to);
    return 0;
}
