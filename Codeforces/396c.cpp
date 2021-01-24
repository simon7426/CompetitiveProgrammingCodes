#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

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
int sm[300010],cng[300010];
vi g[300010];
int dep[300010],tin[300010],tout[300010],clk=0;
void dfs(int x,int d)
{
    dep[x]=d;
    tin[x]=++clk;
    for(int i=0;i<g[x].size();i++)
    {
        dfs(g[x][i],d+1);
    }
    tout[x]=clk;
}

void update(int x,int v1,int v2)
{
    for(;x<300010;x+=(x&-x))
    {
        sm[x]+=v1;
        cng[x]+=v2;
        sm[x]%=MOD;
        cng[x]%=MOD;
    }
}

int query(int x,int v)
{
    int ret=0,ret2=0;
    for(;x>0;x-=(x&-x))
    {
        ret+=sm[x];
        ret2+=cng[x];
        ret%=MOD;
        ret2%=MOD;
    }
    return modSub(ret,modMul(v,ret2));
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),p;
    for(int i=2;i<=n;i++)
    {
        p=in();
        g[p].pb(i);
    }
    dfs(1,1);
    int q=in(),tp,v,x,k,tmp;
    while(q--)
    {
        tp=in();
        v=in();
        if(tp==1)
        {
            x=in();
            k=in();
            tmp=modAdd(x,modMul(dep[v],k));
            update(tin[v],tmp,k);
            update(tout[v]+1,-tmp,-k);
        }
        else
        {
            printf("%d\n",query(tin[v],dep[v]));
        }
    }
    return 0;
}

