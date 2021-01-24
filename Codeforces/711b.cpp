#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int check(int x)
{
    if(x==0)
        return x+1;
    return x-1;
}
int main()
{
    int n,i,j,t,x,y;
    ll a[505][505];
    ll sumr[502],sumc[502];
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        cin>>a[i][0];
        sumr[i]=a[i][0];
        for(j=1;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0){x=i;y=j;}
            sumr[i]+=a[i][j];
        }
    }
        int f=0;
        for(i=1;i<n;i++)
        {
            if(sumr[i]!=sumr[i-1])
                f++;
        }
       /* cout<<f<<endl;
        for(i=0;i<n;i++)
            cout<<sumr[i]<<" ";
        cout<<endl;*/
        ll ans=sumr[check(x)]-sumr[x];
        if(f>2||ans<=0) {cout<<-1<<endl;return 0;}
        //cout<<ans<<endl;
        a[x][y]=ans;
       /* for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            sumc[i]=a[0][i];
            for(j=1;j<n;j++)
            {
                sumc[i]+=a[j][i];
            }
        }
        ll sumd=0,sumrd=0;
        for(i=0;i<n;i++)
        {
            sumd+=a[i][i];
            sumrd+=a[i][n-i-1];
        }
        sumc[n]=sumd;
        sumc[n+1]=sumrd;
        //for(i=0;i<=n+1;i++)
        //    cout<<sumc[i]<<" ";
        //cout<<endl;
        for(i=1;i<=n+1;i++)
        {
            if(sumc[i]!=sumc[i-1])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        cout<<ans<<endl;
}
