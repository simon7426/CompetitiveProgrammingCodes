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
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; ///Hexagonal Direction

inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%lld",&x); return x;}
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
#define CP
struct rider
{
    int x,y,k;
    rider(){}
    rider(int a,int b,int c): x(a),y(b),k(c) {}
};


int n,m,dis[12][12],cnt[12][12],vis[12][12],dis2[12][12];
char s[12][12];
vector<rider> v;
int cntr;
queue<pii> q;

void dfs(int x,int y,int k,int di)
{
    //cout<<x<<" "<<y<<" "<<k<<" "<<di<<endl;
    if(k==0) return;
    int xx,yy,i,j;
    for(i=0;i<8;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];

        if(xx<0||xx>=n||yy<0||yy>=m) continue;
        //cout<<xx<<" "<<yy<<endl;
        if(vis[xx][yy]==0||1+di<dis2[xx][yy])
        {
            vis[xx][yy]=1;
            dis2[xx][yy]=1+di;
            q.push(mp(xx,yy));
            //cout<<xx<< " "<< yy<< " "<<k-1<<" "<<di<<endl;
            dfs(xx,yy,k-1,di);
        }

    }

}

void bfs(int x,int y,int k)
{
    int i,j,xx,yy;
    mem(vis,0);
    mem(dis2,0);

    q.push(mp(x,y));
    vis[x][y]=1;
    pii a;
    while(!q.empty())
    {
        a=q.front();
       // cout<<"bfs "<<a.ff<<" "<<a.ss<<endl;
        q.pop();
        for(i=0;i<8;i++)
        {
                xx=a.ff+dx[i];
                yy=a.ss+dy[i];
                //cout<<dx[i]<<" "<<dy[i]<<endl;
                if(xx<0||yy<0||xx>=n||yy>=m) continue;

                if(vis[xx][yy]==0||1+dis2[a.ff][a.ss]<dis2[xx][yy]){
                vis[xx][yy]=1;
                dis2[xx][yy]=1+dis2[a.ff][a.ss];
                //cout<<xx<<" "<<yy<<" "<<vis[xx][yy]<<endl;
                q.push(mp(xx,yy));
                dfs(xx,yy,k-1,dis2[a.ff][a.ss]);
                }
        }
    }
}

void process()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(vis[i][j]!=0)
            {
                cnt[i][j]++;
                dis[i][j]+=dis2[i][j];
            }
        }
    }
}

void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dis2[i][j]<<" ";
        cout<<endl;
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in(),tc,i,j;
    for(tc=1;tc<=tcc;tc++)
    {
        mem(dis,0);
        mem(cnt,0);
        v.clear();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
        {
            if(s[i][j]>='1'&&s[i][j]<='9')
                v.pb(rider(i,j,s[i][j]-'0'));
        }
        cntr=v.size();
        int ans=INT_MAX;
        if(cntr<=1)
            printf("Case %d: 0\n",tc);
        else
        {
           for(i=0;i<cntr;i++)
           {
               //cout<<endl;
               //cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].k<<endl;
                bfs(v[i].x,v[i].y,v[i].k);
                //print();
                //cout<<endl;
                process();
           }
           for(i=0;i<n;i++)
           {
               for(j=0;j<m;j++)
                {
                    if(cnt[i][j]==cntr)
                        ans=min(ans,dis[i][j]);
                }
           }
           //cout<<cntr<<endl;
           //print();
           if(ans==INT_MAX) ans=-1;
           printf("Case %d: %d\n",tc,ans);
        }
    }
    return 0;

}

