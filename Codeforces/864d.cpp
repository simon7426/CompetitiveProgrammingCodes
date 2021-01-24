#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v[200010];
int cnt[200010],a[200010];
main()
{
    memset(cnt,0,sizeof cnt);
    int n,i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        a[i]=t;
        v[t].push_back(i);
        cnt[t]++;
    }
    priority_queue<int> pq;
    for(i=1;i<=n;i++)
    {
        if(cnt[i]>1)
        {
            for(j=0;j<v[i].size()-1;j++)
            {
                pq.push(-v[i][j]);
            }
        }
    }
    int x,ans=0;
    for(i=1;i<=n;i++)
    {
        if(cnt[i]==0)
        {
            ans++;
            x=-pq.top();
            pq.pop();
            a[x]=i;
        }
    }
    printf("%d\n",ans);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
