#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e10;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const long long MAX = 100 * 1000 + 5;
int n;
vector< vector< int> > g;
int mx, mxnode;
void DFS(int src, int par , int dep){
	if (mx < dep){
		mxnode = src;
		mx = dep;
	}
	for (auto e : g[src]){
		if (e != par){
			DFS(e, src, dep + 1);
		}
	}
}
int main() {
	fast();
	cin >> n;

	g.resize(n);
	for (int i = 1;i < n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	mx = mxnode = -1;
	DFS(0, -1, 0);
	mx = -1;
	DFS(mxnode, -1, 0);
	cout << mx << endl;
	return 0;
}
