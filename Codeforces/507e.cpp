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
int n,m;
vector< pair<pii,int> > g[100010],res;
queue<pair<pii,int> > pq;
int dis[100010],cost[100010],pre[100010],preid[100010];
int xx[100010],yy[100010],zz[100010],fl[100010],vis[100010];
vi ans;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();
    m=in();
    int x,y,z;
    for(int i=0;i<m;i++)
    {
        x=in();
        y=in();
        z=in();
        xx[i]=x;
        yy[i]=y;
        zz[i]=z;
        g[x].pb({{y,z},i});
        g[y].pb({{x,z},i});
    }
    pq.push({{0,0},1});
    pair<pii,int> tp,nxt;
    int curdis,curcost,cur,nxtid,state,id;
    for(int i=0;i<100010;i++)
    {
        dis[i]=inf;
        cost[i]=inf;
    }
    dis[1]=cost[1]=0;
    preid[1]=-1;
    while(!pq.empty())
    {
        tp=pq.front();
        pq.pop();

        //printf("here\n");
        cur=tp.ss;
        //printf("%d\n",cur);
        //if(vis[cur]) continue;
        //vis[cur]=1;
        curdis=-(tp.ff.ff);
        curcost=-(tp.ff.ss);
        if((curdis>dis[cur])||((curdis==dis[cur])&&(curcost>cost[cur])))continue;
        //printf("%d %d %d\n",cur,curdis,curcost);
        for(int i=0;i<g[cur].size();i++)
        {
            nxt=g[cur][i];
            nxtid=nxt.ff.ff;
            state=nxt.ff.ss;
            id=nxt.ss;
            //printf("%d %d\n",dis[nxtid],dis[cur]);
            if(dis[nxtid]>dis[cur]+1)
            {
                //printf("here\n");
                dis[nxtid]=dis[cur]+1;
                cost[nxtid]=cost[cur]+(state==0);
                preid[nxtid]=cur;
                pre[nxtid]=id;
                pq.push({{dis[nxtid],cost[nxtid]},nxtid});
            }
            else if(dis[nxtid]==dis[cur]+1)
            {
                if(cost[nxtid]>(cost[cur]+(state==0)))
                {
                    dis[nxtid]=dis[cur]+1;
                    cost[nxtid]=cost[cur]+(state==0);
                    preid[nxtid]=cur;
                    pre[nxtid]=id;
                    pq.push({{dis[nxtid],cost[nxtid]},nxtid});
                }
            }
        }

    }
    x=n;
    while(x!=1)
    {
        ans.pb(pre[x]);
        x=preid[x];
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        y=ans[i];fl[y]=1;
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(fl[i]==0 && zz[i]==1)
        {
            cnt++;
            res.pb({{xx[i],yy[i]},0});
        }
        if(fl[i]==1&&zz[i]==0)
        {
            cnt++;
            res.pb({{xx[i],yy[i]},1});
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%d %d %d\n",res[i].ff.ff,res[i].ff.ss,res[i].ss);
    }
}
/*
8 9
1 2 0
8 3 0
2 3 1
1 4 1
8 7 0
1 5 1
4 6 1
5 7 0
6 8 0
*/
