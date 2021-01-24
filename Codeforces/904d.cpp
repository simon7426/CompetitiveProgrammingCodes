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
#define lsb(x) ( x & (-x) )
map<int,int> m;
int ft[630010];
vi a,b;
int c[200010],le[200010],ri[200010];
void add(int b,int x)
{
    for(;b<=530010;b+=lsb(b))
        ft[b]+=x;
}
int rsq(int b)
{
    if(b<=0) return 0;
    int sum=0;
    for(;b;b-=lsb(b))
    {
        sum+=ft[b];
    }
    return sum;
}
int rsq(int l,int r)
{
    return rsq(r) - ( (l==1)? 0: rsq(l-1));
}
ll ans=0L;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in();
    int i,t;
    for(i=0;i<n;i++)
    {
        t=in();
        a.pb(t);
    }
    b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    mem(c,0);
    int nn=b.size();
    for(i=1;i<nn;i++)
    {
        if(abs(b[i]-b[i-1])>1)
            c[i]=1;
        c[i]+=c[i-1];
    }
    int pre=0;
    for(i=0;i<n;i++)
    {
        t=a[i];
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        a[i]+=c[a[i]];
        a[i]++;
        m[a[i]]=t;
        //cout<<a[i]<<" "<<t<<endl;
    }
    for(i=0;i<n;i++)
    {
        add(a[i],1);
        le[i]=rsq(a[i]-2)+rsq(a[i]+2,500010);
        //cout<<le[i]<<endl;
    }
    mem(ft,0);
    for(i=n-1;i>=0;i--)
    {
        add(a[i],1);
        ri[i]=rsq(a[i]-2)+rsq(a[i]+2,500010);
    }
    for(i=0;i<n;i++)
    {
        ans+=(ll)m[a[i]]*(ll)(le[i]-ri[i]);
        //cout<<m[a[i]]<<" "<<le[i]<<" "<<ri[i]<<endl;
    }
    printf("%I64d\n",ans);
    return 0;
}
