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

//#define PB push_back
#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

int n,m,cnt,ncnt,scc;
vi g[30],sc[30],s;
int vis[30],low[30],num[30];
map<string,int> x;
map<int,string> y;

void dfs(int u)
{
    low[u]=num[u]=++ncnt;
    vis[u]=1;
    s.push_back(u);
    for(int j=0;j<g[u].size();j++)
    {
        int v=g[u][j];
        if(num[v]==0)
            dfs(v);
        if(vis[v]==1)
            low[u]=min(low[u],low[v]);
    }
    if(low[u]==num[u])
    {
        while(1)
        {
            int a=s.back();s.pop_back();vis[a]=0;
            sc[scc].push_back(a);
            if(u==a) break;
        }
        ++scc;
    }
}

main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,tc=0;
    string s,t;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0&&m==0)
            break;
        for(i=0;i<30;i++) {g[i].clear();sc[i].clear();}
        //low.clear();
        //num.clear();
        scc=ncnt=0;
        memset(vis,0,sizeof vis);
        memset(low,0,sizeof low);
        memset(num,0,sizeof num);
        x.clear();
        y.clear();
        cnt=ncnt=scc=0;
        for(i=0;i<m;i++)
        {
            cin>>s>>t;
            if(x.find(s)==x.end()){y[cnt]=s;x[s]=cnt++;}
            if(x.find(t)==x.end()){y[cnt]=t;x[t]=cnt++;}
           // cout<<x[s]<<" "<<x[t]<<endl;
            g[x[s]].push_back(x[t]);
        }
        /*for(i=0;i<n;i++)
        {
            cout<<y[i]<<" ---> ";
            for(j=0;j<g[i].size();j++)
                cout<<y[g[i][j]]<<" ";
            cout<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            if(num[i]==0)
                dfs(i);
        }
        //cout<<scc<<endl;
        printf("Calling circles for data set %d:\n",++tc);
        for(i=0;i<scc;i++)
        {

            cout<<y[sc[i][0]];
            for(j=1;j<sc[i].size();j++)
            {
                cout<<", "<<y[sc[i][j]];
            }
            cout<<endl;
        }
        //cout<<scc<<endl;
        cout<<endl;
    }
}
