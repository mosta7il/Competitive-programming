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
pair<int,int> a[(int)1e5 + 2];
vector<int> v[(int)1e5 + 2];
int n, m, k;

int main(){
	fast();
	cin >> n >> m >> k;
	int tmp = 1 , tt = k;
	ll cnt = 0;
	lp(i, n){
		int u;
		cin >> u;
		v[tmp].push_back(u);
		a[u] = { tmp, v[tmp].size() - 1 };
		tt--;
		if (!tt)tt = k, tmp++;
	}
	lp(i, m){
		int var;
		cin >> var;
		cnt += a[var].first;
		if (a[var].second == 0 && a[var].first > 1){
			int z = v[a[var].first - 1][v[a[var].first-1].size()-1];
			swap(v[a[var].first][a[var].second], v[a[var].first - 1][v[a[var].first - 1].size() - 1]);
			swap(a[var], a[z]);
		}
		else if (a[var].second > 0){
			int z = v[a[var].first][a[var].second-1];
			swap(v[a[var].first][a[var].second], v[a[var].first ][a[var].second -1]);
			swap(a[var], a[z]);
		}
	}

	cout << cnt << endl;

	return 0;
}
//mosta7il_
