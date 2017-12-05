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
int grid[401][401];
vector<int> train[401] , bus[401];
bool visT[401], visB[401];
int bfs(vector<int> *v , bool * vis){
	int level[401] = { 0 };

	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()){
		int src = q.front();
		q.pop();

		for (int i = 0; i < v[src].size(); i++){
			if (!vis[v[src][i]]){
				q.push(v[src][i]);
				vis[v[src][i]] = 1;
				level[v[src][i]] = 1 + level[src];
			}
		}
	}
	return level[n];
}
int main(){
	fast();
	cin >> n >> m;
	int u, v;
	lp(i, m){
		cin >> u >> v;
		grid[u][v] = 1;
		grid[v][u] = 1;
		train[u].push_back(v);
		train[v].push_back(u);
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j)continue;
			if (grid[i][j] == 0)
				bus[i].push_back(j);
		}
	}

	int tr = bfs(train, visT), bu = bfs(bus, visB);

	if (tr == 0 || bu == 0){
		cout << -1 << endl;
	}
	else cout << max(tr, bu) << endl;

	return 0;
}
//mosta7il_
