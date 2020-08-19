#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,end) for(int i=0; i<end; i++)
#define rlop(i,start) for(int i=start-1; i>=0; i--)
#define loop(i,start,end) for(int i=start; i<end; i++)
#define rloop(i,start,end) for(int i=start-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second


const ll OO = (4e18)+9;
const int MOD = (1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { r, d, l, u };
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1, 0,-1, 0 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string abc = "abcdefghijklmnopqrstuvwxyz";
string vowels = "aeiou"; //and sometimes "aeiouy"

int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; } //Compare Double Numbers
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)
ii rord(int n, int nCol){ //convert index from 1D array to 2D matrix . (One-indexed)
	int r = n%nCol,c = n/nCol;
	if(n%nCol == 0) c--, r = nCol;
	return ii(r,c);
}

ll poww(ll num, ll p , ll md){
  num %= md;
  ll ret = 1;
  while (p > 0) {
    if (p & 1) ret = (ret * num) % md;
    num = (num * num) % md;
    p >>= 1;
  }
  return ret;
}

ll nCr(ll n, ll r) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return n * nCr(n - 1, r - 1) / r;
}

bool fun(ii& i1, ii& i2){
    if(i1.f == i2.f) return i1.s > i2.s;
    return i1.f > i2.f;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string ss;
    cin>>ss;
    int q,l,r,xx,yy,zz,rem,mn;
    sc(q);
    vi x(sz(ss)+2,0),y(sz(ss)+2,0),z(sz(ss)+2,0);
    loop(i,1,sz(ss)+1) x[i] = x[i-1] + (ss[i-1]=='x'), y[i] = y[i-1] + (ss[i-1]=='y'), z[i] = z[i-1] + (ss[i-1]=='z');
    while(q--){
        sc(l),sc(r);
        if(r-l+1 < 3) { cout<<"YES\n"; continue; }
        xx = x[r] - x[l-1], yy = y[r] - y[l-1], zz = z[r] - z[l-1];
        mn = min(xx,min(yy,zz));
        rem = r-l+1-3*mn;
        if(rem > 2 || zz-2 >= mn || yy-2 >= mn || xx-2 >= mn) cout<<"NO\n";
        else cout<<"YES\n";
    }


    return 0;
}