#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    //memset(a,0,sizeof a);
    ll n,t,cnt=0,e=0,o=0;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t&1)
        {
            o++;
        }
        cnt+=t;
    }
    if(cnt&1)
    {
        cout<<"First"<<endl;
        return 0;
    }
    else
    {
        if(o>=1)
        {
            cout<<"First"<<endl;
        }
        else

        {
            cout<<"Second"<<endl;
        }
    }
    return 0;
}
