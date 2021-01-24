#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[2010],b[2010];
map<int,int> m;
main()
{
    int n,k,i,t,j,x,f=0;
    scanf("%d %d",&k,&n);
    scanf("%d",&a[0]);
    for(i=1;i<k;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0) f=n;
        a[i]+=a[i-1];
    }
    //cout<<"here"<<endl;
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        b[i]=t;
        m[t]=0;
    }
//    int f=0;
    for(i=0;i<n;i++)
    {
        if(m[b[i]]!=1){
        for(j=0;j<k;j++)
        {
            x=b[i]-a[j];
            m[x]=1;
        }
        }
    }
    int cnt=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second==1&&!(binary_search(b,b+n,it->first))) cnt++;
    }
    //cout<<m.size()<<endl;
    printf("%d\n",cnt+f);
}
