#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
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
typedef pair<ll,ll> llll;
typedef vector<int> vi ;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<llll> vllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;
typedef map<string,string> mss;
typedef map<int,char> mic;
typedef map<char,int> mci;

#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%I64d",&x)
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


const ll OO = (ll)1e18+9;
const int oo = 2147483647;
const double EPS = 1e-9;
const double PI=acos(-1.0);

//enum dir { u, r, d, l };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

//enum diR { d, r, u, l , dr, ur, dl, ul };
int dX[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dY[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int dot(int x, int y, int x2, int y2) {return x * x2 + y * y2; }
ll gcd (ll x, ll y){ return !y ? x : gcd(y, x%y); }
ll lcm (ll a, ll b) { return a * (b / gcd(a, b)); }
int ord(int r,int c,int nCol) { return (nCol*r) + c + 1; } //transform from 2-D matrix to 1-D array. (Zero-indexed)
//Compare Double Numbers
int cmpDouble(ld d1,ld d2){ return fabs(d1-d2)<=EPS?0:d1>d2?1:-1; }


int _x,_y,n,m,cnt=0; char ch;
char grid[25][25];
vvi vis(25, vi(25,0));
bool valid(int i, int j){
	return i>=0 && j>=0 && i<n && j<m && grid[i][j]==ch;
}

void dfs(int i, int j){
	vis[i][j]=1, cnt++;
	lop(k,4){
		if(valid(i+dx[k], j+dy[k]) && !vis[i+dx[k]][j+dy[k]]) dfs(i+dx[k], j+dy[k]);
	}
	if(j==m-1 && !vis[i][0] && grid[i][0]==ch) dfs(i,0);
	if(!j && !vis[i][m-1] && grid[i][m-1]==ch) dfs(i,m-1);
}


int main()
{
	
	//p11094
	while(cin>>n){
		cin>>m; int mx=0; cnt=0; clr(vis), rsz(vis)(25,vi(25,0));
		lop(i,n) cin>>grid[i];
		cin>>_x>>_y; ch = grid[_x][_y];
		dfs(_x,_y);
		lop(i,n) lop(j,m) {
			cnt=0;
			if(!vis[i][j] && grid[i][j]!='w') dfs(i,j);
			mx = max(mx, cnt);
		}
		cout<<mx<<endl;
	}
	return 0;
}