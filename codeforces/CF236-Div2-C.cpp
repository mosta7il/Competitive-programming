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
long long gcd(long long a, long long b)
{
	while (a&&b)a>b ? a %= b : b %= a;
	return a + b;
}
ll lcm(ll a, ll b){
	return  (a*b / gcd(a, b));
}
int n;
ll dp[1000 * 1000 + 1][4];
ll rec(ll i, int k){
	if (k == 3)return 1;
	if (i == n+1){
		if (k == 3)return 1;
		return -OO;
	}
	if (dp[i][k] != -1)return dp[i][k];
	ll ret = -OO;
	ret = max(ret, lcm(i,rec(i, k + 1)));
	ret = max(ret, rec(i + 1, k));

	return dp[i][k] = ret;
}
int main(){
	fast();
	cin >> n;
	ll mx = 0;
	if (n > 100){
		lpi(i, n - 100, n + 1){
			lpi(j, n - 100, n + 1){
				lpi(w, n - 100, n + 1){
					ll res = lcm(i, j);
					res = lcm(res, w);
					mx = max(mx, res);
				}
			}
		}
	}
	else{
		lpi(i, 1, n + 1){
			lpi(j, 1, n + 1){
				lpi(w, 1, n + 1){
					ll res = lcm(i, j);
					res = lcm(res, w);
					mx = max(mx, res);
				}
			}
		}
	}
	cout << mx << endl;
	return 0;
}
//mosta7il_
