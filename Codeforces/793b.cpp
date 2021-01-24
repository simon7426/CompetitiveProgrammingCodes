#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[1005][1005];
char a[1005][1005];
int n,m,f;
/*void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<vis[i][j]<<" ";
            cout<<endl;
    }
}*/
void dfs(int x,int y,int cm,int tu)
{
    if(x<0||x>=n||y<0||y>=m||tu>2) return ;
    if(a[x][y]=='*') return;
    if(a[x][y]=='T'){f=1;return;}
    if(vis[x][y]!=-1&&vis[x][y]<=tu) return;
    vis[x][y]=tu;
    //cout<<x<<" "<<y<< " "<<cm<<" "<<tu<<" "<<a[x][y]<<endl;
    for(int i=0;i<4;i++)
    {
        if(i!=cm)
                dfs(x+dx[i],y+dy[i],i,tu+1);
        else
                dfs(x+dx[i],y+dy[i],i,tu);
    }
    //return false;
}
main()
{
    int x,y,x1,y1;
    f=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<m;j++)
            {cin>>a[i][j];
            if(a[i][j]=='S') {x=i;y=j;}}
    }
    memset(vis,-1,sizeof (vis));
    for(int i=0;i<4;i++)
    {
        x1=x+dx[i];
        y1=y+dy[i];
        //cout<<x1<<" "<<y1<<endl;
        dfs(x1,y1,i,0);
        //cout<<f<<endl;
        if(f==1) break;
    }
    //print();
    if(f==1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
