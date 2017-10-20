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

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
ll s, t;
ll dp[1001];
ll rec(ll i){
	if (i > t)return OO;
	if (i == t){
		return 0;
	}
	if (dp[i] != -1)return dp[i];
	ll ret = OO;
	ll tmp = i;
	for (int d = 2; d*d <= tmp; d++){
		if (tmp % d == 0){
			ret = min(ret, rec(i + d) + 1);
		}
		while (tmp%d == 0)tmp /= d;
	}
	if (tmp >1 && tmp != i)ret = min(ret, rec(i + tmp) + 1);

	return dp[i] = ret;
}
int main(){
	fast();
	int x = 1;
	while (cin >> s >> t&&s != 0){
		cout << "Case " << x++ << ": ";
		clr(dp, -1);
		ll res = rec(s);
		if (res >= OO){
			cout << -1 << endl;
		}
		else{
			cout << res << endl;
		}
	}
	return 0;
}
//mosta7il_
