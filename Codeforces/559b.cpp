#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool faltu(string s,string t)
{
    int n=s.size();
    int m=t.size();
    string a1,b1,a2,b2;
    if(s==t)
        return true;
    if(n&1||m&1) return false;
    a1=s.substr(0,n/2);
    a2=s.substr(n/2);
    b1=t.substr(0,m/2);
    b2=t.substr(m/2);
    //cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
    return ((faltu(a1,b1)&&faltu(a2,b2))||(faltu(a1,b2)&&faltu(a2,b1)));
}
main()
{
    optimize();
    string s,t;
    cin>>s>>t;
    if(faltu(s,t))
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
