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
#define MOD 1000000009
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
const int Si = 2000010;
#define left(x) x<<1
#define right(x) (x<<1)+1
int st[Si],a[Si],lazy[Si],dp[300010];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        st[p]=a[l];
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=((p1%MOD)+(p2%MOD))%MOD;
    }
}
void update(int p,int l,int r,int i,int j,int v)
{
    if(lazy[p]!=0)
    {
        st[p]=((st[p]%MOD)+(((ll)(lazy[p]%MOD)*(ll)(r-l+1)%MOD)%MOD)%MOD);
        if(l!=r)
        {
            lazy[left(p)]=((lazy[left(p)]%MOD)+(lazy[p]%MOD))%MOD;
            lazy[right(p)]=((lazy[right(p)]%MOD)+(lazy[p]%MOD))%MOD;
        }
        lazy[p]=0;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        st[p]=((st[p]%MOD)+(((ll)(v%MOD)*(ll)(r-l+1)%MOD)%MOD)%MOD);
        if(l!=r)
        {
            lazy[left(p)]=((lazy[left(p)]%MOD)+(v%MOD))%MOD;
            lazy[right(p)]=((lazy[right(p)]%MOD)+(v%MOD))%MOD;
        }
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=((p1%MOD)+(p2%MOD))%MOD;
}
void update(int i,int j,int v)
{
    update(1,0,n-1,i,j,v);
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=0)
    {
        st[p]=((st[p]%MOD)+(((ll)(lazy[p]%MOD)*(ll)(r-l+1)%MOD)%MOD)%MOD);
        if(l!=r)
        {
           lazy[left(p)]=((lazy[left(p)]%MOD)+(lazy[p]%MOD))%MOD;
            lazy[right(p)]=((lazy[right(p)]%MOD)+(lazy[p]%MOD))%MOD;
        }
        lazy[p]=0;
    }
    cout<<l<<" "<<r<<" "<<st[p]<<endl;
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return (((p1%MOD)+(p2%MOD))%MOD);
}
int rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}
void SegmentTree()
{
    memset(st,0,sizeof st);
    build(1,0,n-1);
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    dp[1]=dp[2]=1;
    for(int i=3;i<300010;i++)
        dp[i]=((dp[i-1]%MOD)+(dp[i-2]%MOD))%MOD;
    n=in();
    int q=in(),i,j,t;
    for(i=0;i<n;i++)
        a[i]=in();
    SegmentTree();
    int u,l,r;
    for(i=1;i<=q;i++)
    {
        u=in(),l=in(),r=in();
        if(u==1)
            {
                if(i-l+1>0)
                    update(l-1,r-1,dp[i-l+1]);
            }
        else
            printf("%d\n",rmq(l-1,r-1));
    }
    return 0;
}

