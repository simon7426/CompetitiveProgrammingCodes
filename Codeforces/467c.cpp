#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll ma=0;
int n,m,k;
ll s[5010],a[5010];
ll dp(int cnt,int l,ll sum)
{
   // cout<<cnt<<" "<<l<<" "<<sum<<endl;
    if(l>=n+m) return -1;
    if(cnt==k) {return ma=max(ma,sum);}
    ma=max(ma,dp(cnt,l+1,sum));
    for(int i=l+m;i<=n+1;i++)
    {
        //cout<<i<<" "<<s[l+m-1]-s[l-1]<<endl;
        return ma=max(ma,dp(cnt+1,i,sum+s[l+m-1]-s[l-1]));
    }
    return -1;
}
main()
{
    optimize();
    cin>>n>>m>>k;
    memset(s,0,sizeof s);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s[i+1]=a[i]+s[i];
    }
    ma=dp(0,1,0);
    cout<<ma<<endl;
    return 0;
}
