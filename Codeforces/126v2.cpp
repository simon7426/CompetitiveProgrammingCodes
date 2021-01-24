
#include <bits/stdc++.h>
using namespace std;

//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> pll;
const double PI = acos(-1);

//defines
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a)*(a))
#define inf 100000000
#define mod 1000000007
#define EPS 1e-9
//define harmonic(n) 0.57721566490153286l+log(n)
#define nl puts("")

//loop
#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, n) for(int i = 1; i <= n; ++i)

//input
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sd(a) scanf("%lf", &a)
#define sc(a) scanf("%c", &a)
#define sst(a) scanf("%s", a)


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

//debug
#ifdef tahsin
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) { return os << "(" << p.first << ", " << p.second << ")"; }

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << *it; }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) { if( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ; }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) { for(int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl; }

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

#else
#define dbg(args...)
#endif

//Direction Array
//int fx[]={1, -1, 0, 0}; int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1}; int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};

//bit manipulation
bool checkBit(int n, int i) { return (n&(1<<i)); }
int setBit(int n, int i) { return (n|(1<<i)); }
int resetBit(int n, int i) { return (n&(~(1<<i))); }
//end of template

#define MX 1000010
char a[MX];
int z[MX], cnt[MX];

int main () {
#ifdef tahsin
#endif

	sst(a);

	int n = strlen(a);

	z[0] = 0;

	int l = 0, r = 0;
	for(int i = 1; a[i]; ++i) {
		if(i <= r) z[i] = min(z[i-l], r-i+1);
		while(i + z[i] < n && a[i+z[i]] == a[z[i]]) ++z[i];
		if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
	}

	int mid = 0;
	for(int i = 1; i < n-1; ++i) mid = max(mid, min(z[i], n-1-i));

	int mx = 0, start = -1;
	for(int i = n-1; i > 0; --i) {
		if(z[i] == n-i && z[i] <= mid && z[i] > mx) {
			mx = z[i];
			start = i;
		}
	}

	if(start == -1) {
		puts("Just a legend");
		return 0;
	}

	mx = min(mx, n-2);
	rep(i, mx) putchar(a[i+start]);
	nl;

	for(int i=0;i<=n;i++)
        cout<<z[i]<<" ";
    cout<<endl;

//	timeStamp;
	return 0;
}
