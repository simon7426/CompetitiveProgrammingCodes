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

inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%I64d",&x); return x;}
inline double ind() { double x;scanf("%lf",&x);return x;}

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

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
char s[1010][1010];
pii pre[1010][1010];
int vis[1010][1010];
int n,m,sx,sy,ex,ey,k;
 queue<pii> q;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    //optimize();
    mem(vis,0);
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    --sx,--sy,--ex,--ey;
    if(sx==ex&&sy==ey)
    {
        printf("0\n");
        return 0;
    }
    pii v;
    int x,y;

    q.push(mp(sx,sy));
    pre[sx][sy].ff=-1;
    pre[sx][sy].ss=-1;
    pre[ex][ey].ff=-1;
    pre[ex][ey].ss=-1;
    vis[sx][sy]=1;
    int f=0;
    while(!q.empty())
    {
        v=q.front();
        q.pop();

        //cout<<v.ff<<" "<<v.ss<<endl;
        for(i=0;i<4;i++)
        {

            x=v.ff+dx[i];
            y=v.ss+dy[i];
            //cout<<x<<" "<<y<<endl;
            if(x<0||x>=n||y<0||y>=m) continue;
            if(s[x][y]!='.'||vis[x][y]==1) continue;
            vis[x][y]=1;
            pre[x][y]=v;
            if(x==ex&&y==ey)
            {
                f=1;
                break;
            }
            q.push(mp(x,y));
        }
        //v=pre[v.ff][v.ss];
        //cout<<v.ff<< " "<<" "<<v.ss<<endl;
        if(f==1)
        {
            while(!q.empty())
                q.pop();
        }
    }
    pii u=mp(-1,-1);
    if(pre[ex][ey]==u)
    {
        printf("-1\n");
        return 0;
    }
    int cnt=0,ans=0,dir=0;

    while(ex!=-1&&ey!=-1)
    {

        x=pre[ex][ey].ff;
        y=pre[ex][ey].ss;
        if(cnt==k)
        {
            cnt=0;
            ans++;
        }
        if(dir==0)
        {
            //cout<<ex<<" "<<x<<"sad"<<endl;
            if(ex==x)
                dir=1;
            else
                dir=2;
            ans++;
        }
        else if(dir==1&&x!=-1)
        {
            if(ex==x)
                cnt++;
            else
            {
                dir=2;
                cnt=0;
                ans++;
            }
        }
        else if(dir==2&& x!=-1)
        {
            if(ey==y)
                cnt++;
            else
            {
                dir=1;
                cnt=0;
                ans++;
            }
        }
        ex=x;
        ey=y;

        //cout<<ex<<" "<<ey<<endl;
        //cout<<cnt<<" "<<dir<<" "<<ans<<endl;
    }
    //if(cnt!=0) ans++;
    //cout<<pre[0][0].ff<<" "<<pre[0][0].ss<<endl;
    printf("%d\n",ans);
}
