#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int vis[100010];
pair<int,int> a[100010],b[100010];
int ans;
vector<int> v[100010];
main()
{
    memset(vis,0,sizeof vis);
    int n,i,t,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            a[i]=make_pair(t,i);
            b[i]=a[i];
        }
    sort(a,a+n);
    ans=0;
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            j=i;
            vis[i]=1;
            while(b[i].first!=a[j].first)
            {
                v[ans].push_back(j);
                vis[j]=1;
                j=a[j].second;
            }
            v[ans].push_back(j);
            vis[j]=1;
            ans++;
        }
    }
    printf("%d\n",ans);
    for(i=0;i<ans;i++)
    {
        printf("%d ",v[i].size());
        for(j=0;j<v[i].size();j++)
            printf("%d ",v[i][j]+1);
        printf("\n");
    }
    return 0;
}
