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
vi g[300010];
int p[300010],vis[300010],n,m,q;
int f1[300010],dia[300010],dis[300010];
int findp(int x)
{
    if(x==p[x])return p[x];
    return p[x]=findp(p[x]);
}
void uni(int x,int y)
{
    int a=findp(x);
    int b=findp(y);
    if(a==b) return;
    if(a<b)p[b]=a;
    if(b<a)p[a]=b;
}

void prepo()
{
    int i,ans=0,x,y;
    queue<int> q;
    mem(vis,0);
    mem(f1,0);
    mem(dis,0);
    for(i=1;i<=n;i++)
    {
        if(i==p[i])
        {
            ans=0;
            q.push(i);
            vis[i]=1;
            dis[i]=0;
            f1[i]=i;
            while(!q.empty())
            {
                x=q.front();
                q.pop();
                for(int j=0;j<g[x].size();j++)
                {
                   y=g[x][j];
                   if(vis[y])continue;
                   vis[y]=1;
                   dis[y]=dis[x]+1;
                   q.push(y);
                   if(ans<dis[y])
                   {
                       ans=dis[y];
                       f1[i]=y;
                   }
                }
            }
        }
    }
    mem(dis,0);
    mem(vis,0);
    for(i=1;i<=n;i++)
    {
        if(i==p[i])
        {
            ans=0;
            q.push(f1[i]);
            vis[f1[i]]=1;
            dis[f1[i]]=0;
            while(!q.empty())
            {
                x=q.front();
                q.pop();
                for(int j=0;j<g[x].size();j++)
                {
                   y=g[x][j];
                   if(vis[y])continue;
                   vis[y]=1;
                   dis[y]=dis[x]+1;
                   q.push(y);
                   if(ans<dis[y])
                   {
                       ans=dis[y];
                       dia[i]=ans;
                   }
                }
            }
        }
    }
    /*for(i=1;i<=n;i++) if(i==p[i])
        printf("%d %d\n",i,dia[i]);*/
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();
    m=in();
    q=in();
    int i,j,x,y,z;
    for(i=1;i<=n;i++)p[i]=i;
    for(i=0;i<m;i++)
    {
        x=in(),y=in();
        g[x].pb(y);
        g[y].pb(x);
        uni(x,y);
    }
    prepo();
    int a,b,c,d;
    for(i=0;i<q;i++)
    {
        x=in();
        if(x==1)
        {
            y=in();
            z=findp(y);
            printf("%d\n",dia[z]);
        }
        else
        {
            y=in(),z=in();
            a=findp(y);
            b=findp(z);
            if(a==b)continue;
            c=dia[a];
            d=dia[b];
            if(c&1) c=(c>>1)+1;
            else c=(c>>1);
            if(d&1) d=(d>>1)+1;
            else d=(d>>1);
            if(a<b)
            {
                p[b]=a;dia[a]=max(c+d+1,max(dia[a],dia[b]));
            }
            if(b<a)
            {
                p[a]=b;dia[b]=max(c+d+1,max(dia[a],dia[b]));
            }
        }
    }
}

