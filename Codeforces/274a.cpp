#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100010],x[100010],c;
bool f(int t)
{
    int l=0,h=c-1,m;
    //cout<<t<<" "<<c<<endl;
    while(l<h)
    {
        m=(l+h+1)/2;
        if(x[m]<=t) l=m;
        else h=m-1;
        //cout<<l<<" "<<h<<" "<<m<<endl;
    }
    return (x[l]!=t);
}

main()
{
    int n,k,i,t;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%k==0)
        {
            t=a[i]/k;
            if(f(t)) x[c++]=a[i];
        }
        else x[c++]=a[i];
    }
    //for(i=0;i<c;i++) cout<<x[i]<<" "; cout<<endl;
    cout<<c<<endl;
    return 0;
}
