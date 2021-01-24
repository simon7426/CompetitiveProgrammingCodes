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
vi p,ra,si;
int cnts;
void ufind(int n)
{
    ra.assign(n,0);
    p.assign(n,0);
    si.assign(n,1);
    for(int i=0;i<n;i++)
        p[i]=i;
    cnts=n-1;
}
int findset(int i) {return ((p[i]==i)?i:p[i]=findset(p[i]));}
bool issame(int i,int j) {return findset(i)==findset(j);}
void unionset(int i,int j)
{
    if(!issame(i,j))
    {
       cnts--;
      int x=findset(i);int y=findset(j);
      if(ra[x]>ra[y])
        {
            si[findset(x)]+=si[findset(y)];
            p[y]=x;
        }
      else
      {
          si[findset(y)]+=si[findset(x)];
          p[x]=y;
          if(ra[x]==ra[y]) ra[y]++;
      }
    }
}
int setsize(int n)
{
    return si[findset(n)];
}
int numofsets() {return cnts;}
string s,t;
int a[1010],b[1010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    ufind(26+1);
    int n;
    cin>>n;
    cin>>s>>t;
    int i,j,k,ans=0,x,y;
    for(i=0;i<n;i++)
    {
        x=s[i]-'a';
        y=t[i]-'a';
        if(issame(x,y))continue;
        unionset(x,y);

        a[ans]=x;
        b[ans]=y;
        ans++;
    }
    cout<<ans<<endl;
    for(i=0;i<ans;i++)
        cout<<(char)(a[i]+'a')<<" "<<(char)(b[i]+'a')<<endl;
    return 0;
}

