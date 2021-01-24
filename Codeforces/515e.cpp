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

#define left(x) x<<1
#define right(x) (x<<1)+1

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

int dis[100010],hi[100010];
ll sm1[200010],sm2[200010];
pii st[800010],st2[800010];
int n,m;

void build(int p,int l,int r)
{
    if(l==r)
        {
            st[p]={l,-1};
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        pii p1=st[left(p)],p2=st[right(p)];
        if(sm1[p1.ff]>sm1[p2.ff])
        {
            if(p1.ss==-1)
            {
                st[p]={p1.ff,p2.ff};
            }
            else if(sm1[p1.ss]>=sm1[p2.ff])
            {
                st[p]=p1;
            }
            else
            {
                st[p]={p1.ff,p2.ff};
            }
        }
        else
        {
            if(p2.ss==-1)
            {
                st[p]={p2.ff,p1.ff};
            }
            else if(sm1[p2.ss]>=sm1[p1.ff])
            {
                st[p]=p2;
            }
            else
            {
                st[p]={p2.ff,p1.ff};
            }
        }
    }
}

void build2(int p,int l,int r)
{
    if(l==r)
        {
            st2[p]={l,-1};
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    else
    {
        build2(left(p),l,(l+r)/2);
        build2(right(p),(l+r)/2+1,r);
        pii p1=st2[left(p)],p2=st2[right(p)];
        if(sm2[p1.ff]>sm2[p2.ff])
        {
            if(p1.ss==-1)
            {
                st2[p]={p1.ff,p2.ff};
            }
            else if(sm2[p1.ss]>=sm2[p2.ff])
            {
                st2[p]=p1;
            }
            else
            {
                st2[p]={p1.ff,p2.ff};
            }
        }
        else
        {
            if(p2.ss==-1)
            {
                st2[p]={p2.ff,p1.ff};
            }
            else if(sm2[p2.ss]>=sm2[p1.ff])
            {
                st2[p]=p2;
            }
            else
            {
                st2[p]={p2.ff,p1.ff};
            }
        }
    }
}

pii rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return {-1,-1};
    if(l>=i&&r<=j)
    {
        return st[p];
    }
    //cout<<p<<" "<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
    pii p1=rmq(left(p),l,(l+r)/2,i,j);
    pii p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1.ff==-1) return p2;
    if(p2.ff==-1) return p1;
    if(sm1[p1.ff]>sm1[p2.ff])
    {
        if(p1.ss==-1)
        {
            return {p1.ff,p2.ff};
        }
        else if(sm1[p1.ss]>=sm1[p2.ff])
        {
                return p1;
        }
        else
        {
            return {p1.ff,p2.ff};
        }
    }
    else
    {
        if(p2.ss==-1)
        {
            return {p2.ff,p1.ff};
        }
        else if(sm1[p2.ss]>=sm1[p1.ff])
        {
            return p2;
        }
        else
        {
            return {p2.ff,p1.ff};
        }
    }
}
pii rmq(int i,int j)
{
    return rmq(1,0,n+n-1,i,j);
}

pii rmq2(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return {-1,-1};
    if(l>=i&&r<=j) return st2[p];
    pii p1=rmq2(left(p),l,(l+r)/2,i,j);
    pii p2=rmq2(right(p),(l+r)/2+1,r,i,j);
    if(p1.ff==-1) return p2;
    if(p2.ff==-1) return p1;
    if(sm2[p1.ff]>sm2[p2.ff])
    {
        if(p1.ss==-1)
        {
            return {p1.ff,p2.ff};
        }
        else if(sm2[p1.ss]>=sm2[p2.ff])
        {
                return p1;
        }
        else
        {
                return {p1.ff,p2.ff};
        }
    }
    else
    {
        if(p2.ss==-1)
        {
            return {p2.ff,p1.ff};
        }
        else if(sm2[p2.ss]>=sm2[p1.ff])
        {
            return p2;
        }
        else
        {
            return {p2.ff,p1.ff};
        }
    }
}
pii rmq2(int i,int j)
{
    return rmq2(1,0,n+n-1,i,j);
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in(),m=in();
    for(int i=0;i<n;i++)
        dis[i]=in();
    for(int i=0;i<n;i++)
        hi[i]=in();
    sm1[0]=2*hi[0];
    sm2[0]=2*hi[0];
    for(int i=1;i<2*n;i++)
    {
        sm1[i]=sm1[i-1]+dis[(i-1)%n]+2*hi[i%n]-2*hi[(i-1)%n];
        sm2[i]=sm2[i-1]-dis[(i-1)%n]+2*hi[i%n]-2*hi[(i-1)%n];
    }
    //for(int i=0;i<n+n;i++) printf("%I64d ",sm1[i]);printf("\n");
    //for(int i=0;i<n+n;i++) printf("%I64d ",sm2[i]);printf("\n");
    build(1,0,n+n-1);
    build2(1,0,n+n-1);
    int x,y,l,r;
    pii r1,r2;
    for(int i=0;i<m;i++)
    {
        x=in(),y=in();
        x--,y--;
        if(x>y)
        {
            l=y+1;
            r=x-1;
        }
        else
        {
            l=y+1;
            r=n+x-1;
        }
        r1=rmq(l,r);
        r2=rmq2(l,r);
        //cout<<l<<" "<<r<<" "<<r1.ff<<" "<<r1.ss<<" "<<r2.ff<<" "<<r2.ss<<endl;
        if(r1.ff==r2.ff)
        {
            printf("%I64d\n",max(sm1[r1.ff]+sm2[r2.ss],sm1[r1.ss]+sm2[r2.ff]));
        }
        else
        {
            printf("%I64d\n",sm1[r1.ff]+sm2[r2.ff]);
        }
    }
    return 0;
}
