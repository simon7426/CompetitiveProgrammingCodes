#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

main()
{
    int n,i,t=0,cnta=0,cntb=0;
    string s;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]=='a'&&cntb==0)
            cnta++;
        if(s[i]=='b'&&cnta!=0)
            cntb++;
        if(s[i]=='a'&&cntb!=0)
        {
            t=modMul(modPow(2,cnta),cntb)%MOD;
            cntb=0;
            cnta++;
        }
    }
    t=modMul(modPow(2,cnta),cntb)%MOD;
    cout<<t<<endl;
    return 0;
}
