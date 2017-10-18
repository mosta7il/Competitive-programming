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

int n, m, k;
char g[501][501];
bool vis[501][501];
bool isv(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}
void dfs(int i, int j){
	
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
			if (!(dx == 0 || dy == 0))continue;

			int ii = dx + i, jj = j + dy;
			if (isv(ii, jj) && !vis[ii][jj] && g[ii][jj] == '.'){
				vis[ii][jj] = 1;
				dfs(ii, jj);
			}
		}
	}
	if (k){
		g[i][j] = 'X';
		k--;
	}
}
int main(){
	fast();
	cin >> n >> m >> k;
	lp(i, n){
		lp(j, m){
			cin >> g[i][j];
		}
	}

	lp(i, n){
		lp(j, m){
			if (g[i][j] == '.'&& k&&!vis[i][j]){
				dfs(i, j);
			}
		}
	}

	lp(i, n){
		lp(j, m)cout << g[i][j];
		cout << endl;
	}
	return 0;
}
//mosta7il_
