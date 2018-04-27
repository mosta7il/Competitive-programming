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
ll a, b;
ll pw(ll x, ll y , ll md){
	if (y == 0)return 1;
	if (y == 1)return x;
	ll t = pw(x, y / 2 ,md);
	return ((t%md)*(t%md)*pw(x, y%2, md) % md)%md;
}

int n, m, k;
char g[51][51];
bool vis[51][51];
vector< pair<int, pair<int, int> > > con;
int cnt;
bool isv(int i, int j){
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
void dfs(int i, int j){
	if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
		cnt = -1e9;
	}
	vis[i][j] = 1;
	cnt++;
	for (int x = -1; x <= 1; x++){
		for (int y = -1; y <= 1; y++){
			if (x == 0 || y == 0){
				int ii = i + x, jj = j + y;
				if (isv(ii, jj) && !vis[ii][jj] && g[ii][jj] == '.'){
					dfs(ii, jj);
				}
			}
		}
	}
}
void rem(int i, int j){
	vis[i][j] = 1;
	g[i][j] = '*';
	for (int x = -1; x <= 1; x++){
		for (int y = -1; y <= 1; y++){
			if (x == 0 || y == 0){
				int ii = i + x, jj = j + y;
				if (isv(ii, jj) && !vis[ii][jj] && g[ii][jj] == '.'){
					rem(ii, jj);
				}
			}
		}
	}
}
int main(){
	fast();
	cin >> n >> m >> k;
	lp(i, n)lp(j, m)cin >> g[i][j];

	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (g[i][j] == '.'&&!vis[i][j]){
				cnt = 0;
				dfs(i, j);
				if (cnt > 0){
					con.push_back({ cnt, { i, j } });
				}
			}
		}
	}
	memset(vis, 0, sizeof vis);
	sort(con.begin(), con.end());
	ll res = 0;
	while (con.size() > k){
		pair<int, pair<int, int> > tmp = con[0];
		con.erase(con.begin());
		res += tmp.first;
		rem(tmp.second.first, tmp.second.second);
	}

	cout << res << endl;
	lp(i, n){
		lp(j, m)cout << g[i][j];
		cout << endl;
	}

	return 0;
}
//mosta7il_
