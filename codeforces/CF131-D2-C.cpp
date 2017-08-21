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
typedef unsigned long long         ull;
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
int n, m, t;
ld cnt;
ld comb(int n, int r){
	int dif = n - r;
	ld ret = 1;
	if (dif >= r){
		int s = n - r;
		for (int i = n; i > s; i--, r--){
			ret *= (ld)i;
			if (r > 1)
				ret /= (ld)r;
		}
	}
	else{
		int s = n - dif;
		for (int i = n; i > s; i--, dif--){
			ret *= (ld)i;
			if (dif > 1)
				ret /= (ld)dif;
		}
	}


	return ret;
}

int main(){
	fast();
	cin >> n >> m >> t;

	for (int i = 4; i <= (n) && t - i > 0; i++){
		if (t-i <= m)
			cnt += comb(n, i) * comb(m, t - i);
	}

	cout << fixed<<setprecision(0) << cnt << endl;
	return 0;
}
//mosta7il_
