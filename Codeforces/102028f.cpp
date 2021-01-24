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
int dx0[6]={2,4,2,-2,-4,-2};
int dy0[6]={-6,0,6,6,0,-6};
int dx1[6]={1,2,1,-1,-2,-1};
int dy1[6]={-3,0,3,3,0,-3};

struct node
{
    int x,y,dis;
};
char g[6060][6060];
int vis[6060][6060];
int sx,sy,tx,ty,n,m;
int bfs()
{
    queue<node> q;
    node st;
    st.x=sx,st.y=sy,st.dis=0;
    q.push(st);
    vis[sx][sy]=1;
    while(!q.empty())
    {
        node tmp;
        tmp=q.front();
        q.pop();
        if(g[tmp.x][tmp.y]=='T')
        {
            //printf("%d %d\n",tmp.x,tmp.y);
            return tmp.dis+1;
        }
        for(int i=0;i<6;i++)
        {
            int nxtgox=tmp.x+dx0[i];
            int nxtgoy=tmp.y+dy0[i];
            int nxtchkx=tmp.x+dx1[i];
            int nxtchky=tmp.y+dy1[i];
            if(g[nxtchkx][nxtchky]!=' ')continue;
            if(!vis[nxtgox][nxtgoy])
            {
                vis[nxtgox][nxtgoy]=1;
                node nxt;
                nxt.x=nxtgox,nxt.y=nxtgoy,nxt.dis=tmp.dis+1;
                q.push(nxt);
            }
        }
    }
    return -1;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    while(tcc--)
    {
        int i,j;
        scanf("%d%d",&n,&m);
        getchar();
        for(i=1;i<=4*n+3;i++)
        {
            gets(g[i]+1);
        }
        for(i=1;i<=4*n+3;i++)
        {
            for(j=1;j<=6*m+3;j++)
                {
                    vis[i][j]=0;
                    if(g[i][j]=='S')sx=i,sy=j;
                    //printf("%c",g[i][j]);
                }
            //printf("\n");
        }
        //printf("%d %d\n",sx,sy);
        int ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}

