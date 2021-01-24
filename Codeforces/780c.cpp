#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> g[200010];
int vis[200010],deg[200010],p[200010],col[200010];
main()
{
    int n,i,t,a,b,j;
    memset(deg,0,sizeof deg);
    memset(p,0,sizeof p);
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int ma=0;
    for(i=1;i<=n;i++)
    {
        ma=max(ma,deg[i]);
    }
    ++ma;
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    p[1]=0;
    col[1]=1;
    col[0]=0;
    int x,y,z,k=1;
    while(!q.empty())
    {
        x=q.front();
        z=p[x];
        q.pop();
        for(j=0;j<g[x].size();j++)
        {
            y=g[x][j];
            if(!vis[y])
            {
                vis[y]=vis[x]+1;
                p[y]=x;
                while(k==col[x]||col[z]==k)
                    k++;
                col[y]=k;
                //cout<<x<<" "<<y<<" "<<k<<" "<<p[y]<<endl;
                q.push(y);
                k++;
            }
        }
        k=1;
    }
    /*for(i=1;i<=n;i++) cout<<p[i]<< " ";
    cout<<endl;*/
    printf("%d\n",ma);
    for(i=1;i<=n;i++)
    {
        printf("%d ",col[i]);
    }
    printf("\n");
}
