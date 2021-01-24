#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    int a,b,f,k,i,t,cnt=0;
    cin>>a>>b>>f>>k;
    int dis1=f;
    int dis2=a-f;
    if((b<2*dis1||b<2*dis2)&&(k!=1))
    {
        cout<<-1<<endl;
        return 0;
    }
    if(b<dis1||b<dis2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int s=b;
    for(i=0;i<k;i++)
    {
        //cout<<i<<" "<<k<<endl;
        if(!(i&1))
        {
            if(i==k-1)
            {

                s-=dis1;
                if(s<dis2)
                {

                    cnt++,s=b;
                }
                s-=dis2;
            }
            else{
            s-=dis1;
            if(s<2*dis2)
                {

                    cnt++,s=b;
                }
            s-=dis2;
            }
        }
        if(i&1)
        {
            if(i==(k-1))
            {
                s-=dis2;
                if(s<dis1)
                {
                    cnt++,s=b;
                }
                s-=dis1;
            }
            else{
            s-=dis2;
            if(s<2*dis1)
            {

                cnt++,s=b;
            }
            s-=dis1;
            }
        }

        //cout<<s<<endl;
    }
    cout<<cnt<<endl;
}
