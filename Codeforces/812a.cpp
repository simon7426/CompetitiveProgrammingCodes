#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    int n,m,i,j,f,t;
    for(i=0;i<4;i++)
    {
        f=0;
        for(j=0;j<4;j++)
        {
            cin>>t;
            if(j!=3&&t==1)
            {
                f=1;
            }
            if(j==3&&f==1&&t==1)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
