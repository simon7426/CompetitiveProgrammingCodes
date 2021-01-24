#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    string s[20];
    int n,m,i,j,f;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>s[i];
    int l[20],r[20];
    for(i=0;i<n;i++)
    {
        f=0;
        for(j=0;j<m+2;j++)
        {
            if(s[i][j]=='1')
            {
                if(f==0) l[i]=j;
                f=1;
                r[i]=j;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<l[i]<< " "<<r[i]<<endl;
    }
}
