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
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n, m, k;

int color[101];
vector<ll> cost[101];
ll mem[101][101][101];
ll rec(int i, int w, int last){
	if (i == n){
		if (w != k)return OO;
		else return 0;
	}
	if (last != -1 && mem[i][w][last] != -1)return mem[i][w][last];
	ll ret = OO;
	if (color[i] > 0){
		ret = min(ret, rec(i + 1, w + (last != color[i]), color[i]));
	}
	else{
		for (int d = 1; d <= m; d++)
			ret = min(ret, rec(i + 1, w + (last != d), d) + cost[i][d]);
	}

	return mem[i][w][last]= ret;
}
int main(){
	fast();
	clr(mem, -1);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)cin >> color[i];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){
		if (j == 0)cost[i].push_back(0);
		int cc; cin >> cc; cost[i].push_back(cc);
	}
	ll res = rec(0, 0 , -1);

	if (res < OO){
		cout << res << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}
//mosta7il_
