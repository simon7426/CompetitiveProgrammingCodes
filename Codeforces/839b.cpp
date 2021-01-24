#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[105];
main()
{
    int n,i,t,k,cnt=0,x,rem=0;
    string s;
    cin>>k>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        k-=(t/8);
        a[i]=t%8;
    }
    //for(i=0;i<n;i++) cout<<a[i]<<endl;
    int k4,k2,k1=0;
    //cout<<k<<endl;
    k4=k;
    k2=2*k;
    for(i=0;i<n;i++)
    {
        if(a[i]==0) continue;
        else if(a[i]==1)
        {
            if(k1>0)
                k1--;
            else if(k2==0&&k4>0)
            {
                k4--;
                k2++;
            }
            else
                k2--;
        }
        else if(a[i]==2)
        {
            if(k2<=0&&k4>0)
            {
                k4--;
                k1++;
            }
            else
                k2--;
        }
        else if(a[i]>=3&&a[i]<=4)
        {
            if(k4<=0)
                k2-=2;
            else
                k4--;
        }
        else if(a[i]>=5&&a[i]<=6)
        {
            if(k4<=0)
                k2-=3;
            else{
            k4--;
            k2--;
            }
        }
        else
        {
            if(k4<=0)
                k2-=4;
            else
            {
                k4--;
                k2-=2;
            }
        }
        if(k2<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}

