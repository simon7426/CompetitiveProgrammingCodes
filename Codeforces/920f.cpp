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
int p[1000010],prime[1000010],divi[1000010],t[1000010];

const int mx=4000010;
#define left(x) x<<1
#define right(x) (x<<1)+1
int a[1000010];
struct segmenttree
{
    int n;
    ll sts[mx];
    int stm[mx];
    int fl[mx];
    int
    //int lazy[mx];
    build()
    {
        mem(sts,0);
        mem(stm,0);
        mem(fl,0);
        //mem(lazy,0);
        build(1,0,n-1);
    }
    void build(int p,int l,int r)
    {
        if(l==r)
            {
            sts[p]=stm[p]=a[l];
            if(a[l]<=2) fl[p]=1;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
            }
        else
        {
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            ll p1=sts[left(p)],p2=sts[right(p)];
            sts[p]=p1+p2;
            int pm1=stm[left(p)],pm2=stm[right(p)];
            stm[p]=max(pm1,pm2);
            if(stm[p]<=2) fl[p]=1;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    }
    void update(int p,int l,int r,int i,int j,int v)
    {
        //printf("%d %d %d %d\n",l,r,i,j);
        if(l>r||l>j||r<i) return;
        if(l==r)
        {
            sts[p]=stm[p]=divi[sts[p]];
            if(stm[p]<=2) fl[p]=1;
            return;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
        //printf("%d %d\n",st[p],v);
        int mid=(l+r)/2;
        if(i<=mid && !fl[left(p)])update(left(p),l,(l+r)/2,i,j,v);
        if(mid<=r && !fl[right(p)])update(right(p),1+(l+r)/2,r,i,j,v);
        ll p1=sts[left(p)],p2=sts[right(p)];
        sts[p]=p1+p2;
        int pm1=stm[left(p)],pm2=stm[right(p)];
        stm[p]=max(pm1,pm2);
        if(stm[p]<=2) fl[p]=1;
    }

    void update(int i,int j)
    {
        update(1,0,n-1,i,j,0);
    }

    ll query(int p,int l,int r,int i,int j)
    {
        if(i>r||j<l)
            return -1;
        if(l>=i&&r<=j) return sts[p];
        ll p1=query(left(p),l,(l+r)/2,i,j);
        ll p2=query(right(p),(l+r)/2+1,r,i,j);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        return p1+p2;
    }
    ll query(int i,int j)
    {
        return query(1,0,n-1,i,j);
    }
};

segmenttree seg;



void init()
{
    int n=1e6+5;
    divi[1]=1,t[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(!p[i])
        {
            prime[++prime[0]]=i;
            divi[i]=2;
            t[i]=1;
        }
        for(int j=1;j<=prime[0] && i*prime[j]<=n;j++)
        {
            p[i*prime[j]]=1;
            if(!(i%prime[j]))
            {
                divi[i*prime[j]]=divi[i]/(t[i]+1)*(t[i]+2);
                t[i*prime[j]]=t[i]+1;
                break;
            }
            else
            {
                divi[i*prime[j]]=divi[i]*2;
                t[i*prime[j]]=1;
            }
        }
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    init();
    int n=in(),m=in();
    for(int i=0;i<n;i++)
    {
        a[i]=in();
    }
    seg.n=n;
    seg.build();
    for(int i=0;i<m;i++)
    {
        int t=in(),l=in(),r=in();
        if(t==1)
        {
            seg.update(l-1,r-1);
        }
        else
        {
            printf("%I64d\n",seg.query(l-1,r-1));
        }
    }
}

