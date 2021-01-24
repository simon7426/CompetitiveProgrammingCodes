#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    int cnt=0,cnt2=0,i,n,f=0,si,j;
    string s,t;
    cin>>n;
    for(j=0;j<n;j++)
    {
        cnt2=0;
        cin>>s;
        if(s=="0")
        {
            cout<<s<<endl;
            return 0;
        }
        si=s.size();
        //cout<<si<<endl;
        if(s[0]=='1')
        {
            for(i=1;i<si;i++)
            {
                if(s[i]=='0')cnt2++;
                else
                {
                    f=1;
                    t=s;
                    cnt2=0;
                    break;
                }
            }
        }
        else
        {
            f=1;
            t=s;
        }
        cnt+=cnt2;
    }
    //cout<<s<<" "<<t<<endl;
    if(f==1)
    {
        cout<<t;
    }
    else
    {
        cout<<1;
    }
    for(i=0;i<cnt;i++)
            cout<<'0';
        cout<<endl;
}
