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
int n, m;
ll a[25];
ll dp[25][500];
ll rec(int i, int sum){
	if (i == m){
		if (sum <= n)return sum;
		return -OO;
	}
	//if (dp[i][sum] != -1)return dp[i][sum];
	ll ret = -OO;
	ret = max(ret, rec(i + 1, sum + a[i]));
	ret = max(ret, rec(i + 1, sum));
	return ret;
}
vector<ll>v;
void build(int i, int sum){
	if (i == m){
		return;
	}
	ll ret1 = -OO, ret2 = -OO;
	ret1 = max(ret1, rec(i + 1, sum + a[i]));
	ret2 = max(ret2, rec(i + 1, sum));
	if (ret1 > ret2){
		v.push_back(a[i]);
		build(i + 1, sum + a[i]);
	}
	else{
		build(i + 1, sum);
	}

}
int main(){
	fast();
	while (cin >> n >> m){
		//clr(dp, -1);
		lp(i, m)cin >> a[i];
		ll res = rec(0, 0);
		build(0, 0);
		lp(i, v.size()){
			cout << v[i];
			cout << " ";
		}
		cout << "sum:" << res << endl;
		v.clear();
	}
	return 0;
}
//mosta7il_
