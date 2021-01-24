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
typedef pair<ll,pii> lol;
priority_queue<lol,vector<lol> , greater<lol> > pq;
int x[100010];
int y[100010];
ll c[100010];
ll k[100010];
int vis[100010];
vector<pii> edge;
vi site;
ll cost(int f,int s)
{
    ll dis=abs(x[f]-x[s])+abs(y[f]-y[s]);
    ll res=dis*(k[f]+k[s]);
    return res;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),taken=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        x[i]=in();
        y[i]=in();
    }
    for(int i=1;i<=n;i++)
        c[i]=inl();
    for(int i=1;i<=n;i++)
        k[i]=inl();
    for(int i=1;i<=n;i++)
    {
        pq.push({c[i],{i,0}});
    }

    while(taken<n)
    {
        auto it=pq.top();
        pq.pop();
        //printf("%lld %d %d\n",it.ff,it.ss.ff,it.ss.ss);
        if(vis[it.ss.ff])continue;

        vis[it.ss.ff]=1;
        taken++;
        res+=it.ff;
        if(it.ss.ss)
            edge.push_back({it.ss.ff,it.ss.ss});
        else site.pb(it.ss.ff);
        int tmp=it.ss.ff;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            ll cst=cost(tmp,i);
            //printf("%lld %d %d\n",cst,tmp,i);
            pq.push({cst,{i,tmp}});
        }
    }
    printf("%I64d\n",res);
    printf("%d\n",site.size());
    for(int i=0;i<site.size();i++) printf("%d ",site[i]);
    printf("\n");
    printf("%d\n",edge.size());
    for(int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].ff,edge[i].ss);
}
