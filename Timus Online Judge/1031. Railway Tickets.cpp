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
ll l1, l2, l3, c1, c2, c3;
int f, t;
int n,m;
ll a[(int)1e5 + 7];
ll dp[(int)1e5 + 7];

ll rec(int l){
	if (l == t){
		return 0;
	}
	if (dp[l] != -1)return dp[l];
	ll ret = OO;
	for (int j = l + 1; j <= t; j++){
		ll len = a[j] - a[l];
		if (len <= l1){
			ret = min(rec(j) + c1 , ret);
		}
		else if (len <= l2){
			ret = min(ret , rec(j) + c2);
		}
		else if(len <= l3){
			ret = min(ret ,rec(j) + c3);
		}
	}
	return dp[l] = ret;
}
int main(){
	fast();

	memset(dp, -1, sizeof dp);

	cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
	cin >>n>> f >> t;

	if (f > t)swap(f, t);

	for (int i = 2; i <= n; i++)cin >> a[i];

	cout << rec(f) << endl;
	return 0;
}
//mosta7il_
