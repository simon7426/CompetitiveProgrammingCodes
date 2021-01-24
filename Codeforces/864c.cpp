#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a,b,f,k,dis1,dis2;

int ff(int mid)
{
    int i,s=b;
    //cout<<mid<<" ";
    for(i=0;i<k;i++)
    {
        if(!(i&1))
        {
            if(i==k-1)
            {
                s-=dis1;
                if(s<dis2) --mid,s=b;
                s-=dis2;
            }
            s-=dis1;
            if(s<2*dis2) --mid,s=b;
            s-=dis2;
        }
        if(i&1)
        {
            if(i==k-1)
            {
                s-=dis2;
                if(s<dis1) --mid,s=b;
                s-=dis1;
            }
            s-=dis2;
            if(s<2*dis1) --mid,s=b;
            s-=dis1;
        }
    }
    //cout<<mid<<" "<<endl;
    if(mid<0) return 1;
    else return 0;
}

main()
{
    cin>>a>>b>>f>>k;
    dis1=f;
    dis2=a-f;
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
    int low=0,high=4*k,mid,lol;
    while(low<high)
    {
        mid=(low+high+1)>>1;
        //cout<<low<<" "<<high<<" "<<mid<<endl;
        lol=ff(mid);
        if(lol)
            low=mid;
        else
            high=mid-1;
    }
    cout<<low<<endl;
}
