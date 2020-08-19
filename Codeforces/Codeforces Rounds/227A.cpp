//#include <bits/stdc++.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
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
#define ord0(s) (int)(s-'0')
#define orda(s) (int)(s-'a')
#define ordA(s) (int)(s-'A')

const ll OO = (ll)(1e18)+9;
const ll MOD = (ll)(1e9)+7;
const int oo = 2147483647;
const double EPS = 1e-9;
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

ll dis(int x1,int y1, int x2, int y2){
    return abs(x1 - x2) * 1LL * abs(x1-x2) + abs(y1 - y2) * 1LL * abs(y1-y2);
}

bool isRight(ll a, ll b, ll c){ return a >= 1 && b >= 1 && c >= 1 && (a+b == c || a+c == b || a == b+c); }
string dirc(int x1, int y1, int x2, int y2){
    string ret = "";
    if(y1 > y2) ret += 'U';
    else ret += 'D';
    if(x1 > x2) ret += 'R';
    else ret += 'L';
    return ret;
}

int main()
{
	//freopen("in.txt", "r",stdin);
	//freopen("out.txt", "w", stdout);
    int aX,aY,bY,bX,cX,cY;
    cin>>aX>>aY>>bX>>bY>>cX>>cY;
    ll a = dis(aX,aY,bX,bY), b = dis(bX,bY,cX,cY), c = dis(aX,aY,cX,cY);
    if(isRight(a,b,c)){
            if(bX == cX){
                if(bY > cY && aX < bX) cout<<"RIGHT\n";
                else if(bY > cY) cout<<"LEFT\n";
                else cout<<(aX < bX ? "LEFT\n" : "RIGHT\n");
            }
            else if(bY == cY){
                if(bX < cX && aY < bY) cout<<"RIGHT\n";
                else if(bX < cX) cout<<"LEFT\n";
                else cout<<(aY < bY ? "LEFT\n" : "RIGHT\n");
            }
            else{
                string BA = dirc(bX,bY,aX,aY), BC = dirc(cX,cY,bX,bY);
                if(BA[0] =='U'){
                    if(BA[1] == 'R'){
                        if(BC[0] == 'U') cout<<"LEFT\n";
                        else cout<<"RIGHT\n";
                    }
                    else{
                        if(BC[0] == 'D') cout<<"LEFT\n";
                        else cout<<"RIGHT\n";
                    }
                }
                else{
                    if(BA[1] == 'R'){
                        if(BC[0] == 'U') cout<<"LEFT\n";
                        else cout<<"RIGHT\n";
                    }
                    else{
                        if(BC[0] == 'D') cout<<"LEFT\n";
                        else cout<<"RIGHT\n";
                    }
                }
            }
    }
    else cout << "TOWARDS\n";


	return 0;
}