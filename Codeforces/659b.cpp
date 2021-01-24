#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct reg
{
    string na;
    int p;
    reg(){};
    reg(string s,int po)
    {
        na=s;
        p=po;
    }
};
bool com(reg a,reg b)
{
    return a.p>b.p;
}
main()
{
    int n,m,r,p,i;
    string s;
    cin>>n>>m;
    vector<vector<reg> > v;
    v.resize(m+2);
    for(i=0;i<n;i++)
    {
        cin>>s>>r>>p;
        v[r].emplace_back(s,p);
    }
    for(i=1;i<=m;i++)
    {
        sort(v[i].begin(),v[i].end(),com);
        if(v[i].size()==2)
        {
            cout<<v[i][0].na<<" "<<v[i][1].na<<endl;
        }
        else {
        if(v[i][1].p==v[i][2].p) cout<<"?"<<endl;
        else cout<<v[i][0].na<<" "<<v[i][1].na<<endl;
        }
    }
    return 0;
}
