#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <complex>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <iomanip>
#include <valarray>
#include <sstream>
#include <fstream>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef map<int,int> mii;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,n) for(int i=0; i<n; i++)
#define rlop(i,n) for(int i=n-1; i>=0; i--)
#define loop(i,start,n) for(int i=start; i<n; i++)
#define rloop(i,end,n) for(int i=n-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')

const ll OO = (ll)(1e18)+9;
const ll MOD = (ll)(1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { r, d, l, u };
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1, 0,-1, 0 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int dcmp(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; } //Compare Double Numbers
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //convert index from 2D matrix to 1D array. (Zero-indexed)
ii rord(int n, int nCol){ //convert index from 1D array to 2D matrix . (One-indexed)
	int r = n%nCol,c = n/nCol;
	if(n%nCol == 0) c--, r = nCol;
	return ii(r,c);
}



int main()
{	
	//noS Read Think Code Debug Difficulty Type Discription

	//
	int n,m,ans=0;
	cin>>n>>m;
	vi v1(n),v2(m);
	lop(i,n) cin>>v1[i];
	lop(i,m) cin>>v2[i];
	v1.PB(0),v2.PB(0);
	if(n >= m){
		int j=0, sum1=0,sum2=v2[0];
		lop(i,n){
			sum1 += v1[i];
			if(sum1 == sum2) sum1 = 0, sum2 = v2[++j],ans++;
			else if(sum1 > sum2) {
				while(sum2 < sum1) sum2+=v2[++j];
				if(sum1 == sum2) sum1 = 0, sum2 = v2[++j],ans++;
			}
		}
	}
	else{
		int j=0, sum1=0,sum2=v1[0];
		lop(i,m){
			sum1 += v2[i];
			if(sum1 == sum2) sum1 = 0, sum2 = v1[++j],ans++;
			else if(sum1 > sum2) {
				while(sum2 < sum1) sum2+=v1[++j];
				if(sum1 == sum2) sum1 = 0, sum2 = v1[++j],ans++;
			}
		}
	}
	//ans++;
	cout<<ans<<endl;


	return 0;
}