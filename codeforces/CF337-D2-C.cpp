#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long long         ll;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef vector<ll>		  vll;


const ll OO = 1e16;
const ll mod = 1e9+9;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }



void fast(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
ll fun(ll a ,ll b){
	if(b == 0 )return 1;
	if(b == 1) return a;

	ll tt = fun(a , b/2)%mod;
	return (tt%mod * tt%mod * fun(a , b%2)%mod)%mod;
}
ll n , m , k;

int main(){
	fast();
	cin>>n>>m>>k;

	ll z = (n - ( n /k ) );
	if(m <= z){
		cout<<m<<endl;
	}else{
		ll rt = m - z;ll rs = 0;
		m-=rt * k;
		m= max(0ll,m);
		rs = fun(2 , rt+1);
		rs-=2;
		rs=(rs+mod)%mod;rs*=(k%mod);rs%=mod;
		cout<<(rs%mod + m%mod)%mod<<endl;
	}
	return 0;
}
//mosta7il_;
