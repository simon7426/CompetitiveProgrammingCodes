#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    int n,i,t,m,c[101];
    memset(c,0,sizeof c);
    cin>>n>>m;
    int x=n/m;
    for(i=0;i<n;i++)
    {
        cin>>t;
        c[t]++;
    }
    int cnt=0;
    for(i=1;i<=m;i++)
    {
        if(c[i]<x)
            cnt+=x-c[i];
    }
    cout<<cnt<<endl;
    return 0;
}
