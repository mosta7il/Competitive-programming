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

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, d;
ll a[(int)1e5 + 2];
ll fact[] = {1, 1, 2, 6};
ll nc2(ll x){
	if (x - 2 >= 2){
		return (x * (x - 1)) / 2;
	}
	else if(x-2 == 1){
		return (x);
	}
	else if(x-2 == 0){
		return 1;
	}

	return 0;
}
int main(){
	fast();
	cin >> n>>d;
	lp(i, n)cin >> a[i];
	ll cnt = 0;

	for (int i = 0; i < n; i++){

		int lo = 0, hi = n-1;
		while (lo < hi){
			int md = lo + (hi - lo + 1) / 2;
			if (a[md] - a[i] <= d){
				lo = md;
			}
			else{
				hi = md - 1;
			}
		}
		cnt += nc2(lo - i);
		
	}
	cout << cnt << endl;
	return 0;
}
//mosta7il_
