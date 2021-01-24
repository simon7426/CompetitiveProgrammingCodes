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
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

priority_queue<pii> pq1,pq2;
int a[100010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),m=in(),i,t,u,v,w,cnt=0;
    for(i=0;i<n;i++)
    {
        a[i]=in();u=in();v=in();
        pq1.push(mp(u,i));
        pq2.push(mp(v,i));
        cnt+=a[i];
    }
    ll ans=0;
    int pi=ceil((double)cnt/(double)m);
   // for(int j=0;j<n;j++)
           // cout<<a[j]<<" ";
        //cout<<endl;
    for(i=0;i<pi;i++)
    {
        vii v1,v2;
        pii x,y={0,-1},yy={0,-1};
        int z1=0,zz1=0,z2=0,zz2=0;
        ll val1=0L,val2=0L;
        int cnt1=0,cnt2=0;
        while(!pq1.empty())
        {
            if(a[pq1.top().ss]+cnt1>m)
                break;
            x=pq1.top();
            if(a[x.ss])v1.pb(x);
            cnt1+=a[x.ss];
            val1+=(ll)x.ff*(ll)a[x.ss];
            pq1.pop();
            //cout<<x.ff<<" "<<x.ss<<" "<<cnt1<<endl;
        }
        if(cnt1!=m&&!pq1.empty())
        {
            x=pq1.top();
            y=x;
            pq1.pop();
            z1=m-cnt1;
            zz1=a[x.ss]-(m-cnt1);
            val1+=(ll)x.ff*(ll)z1;
        }
        while(!pq2.empty())
        {
            if(a[pq2.top().ss]+cnt2>m)
                break;
            x=pq2.top();
            if(a[x.ss])v2.pb(x);
            cnt2+=a[x.ss];
            val2+=(ll)x.ff*(ll)a[x.ss];
            pq2.pop();
        }
        if(cnt2!=m&&!pq2.empty())
        {
            x=pq2.top();
            //cout<<a[x.ss]<<" "<<x.ff<<endl;
            yy=x;
            pq2.pop();
            z2=m-cnt2;
            zz2=a[x.ss]-(m-cnt2);
            val2+=(ll)x.ff*(ll)z2;
        }
        if(val1>val2)
        {
            ans+=val1;
            for(int k=0;k<v2.size();k++)
                pq2.push(v2[k]);
            if(zz2!=0) {pq2.push(yy);}
            for(int k=0;k<v1.size();k++)
            {
                a[v1[k].ss]=0;
            }
            //cout<<"zz1 "<<y.ss<<" "<<zz1<<endl;
            if(y.ss!=-1)
            {


            a[y.ss]=zz1;
            pq1.push(y);
            }
        }
        else
        {
            ans+=val2;
            for(int k=0;k<v1.size();k++)
                pq1.push(v1[k]);
            if(zz1!=0) pq1.push(y);
            for(int k=0;k<v2.size();k++)
            {
                a[v2[k].ss]=0;
            }
            //cout<<"zz2 "<<y.ss<<" "<<zz2<<endl;
            if(yy.ss!=-1)
            {
            a[yy.ss]=zz2;
            pq2.push(yy);
            }
        }
        //for(int j=0;j<n;j++)
        //    cout<<a[j]<<" ";
        //cout<<endl;
        //cout<<ans<<" "<<val1<<" "<<val2<<endl;
    }
    printf("%I64d\n",ans);
}
