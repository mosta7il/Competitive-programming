/*

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;

int n;
int grid[2001][2001];
vector< pair<int, pair<int , int> > >ed;
vector< pair< int, int> >g[2001];

struct dsu{
	int par[2001];

	dsu(int n){
		for (int i = 0; i < n; ++i)
			par[i] = i;
	}
	dsu(){}

	int root(int a){
		if (a == par[a])
			return a;
		return par[a] = root(par[a]);
	}
	void join(int a, int b){
		int ra = root(a), rb = root(b);
		par[ra] = rb;
	}
};

void kruskal(){
	dsu tree(n);
	
	for (auto &e : ed){
		int u = e.second.first, v = e.second.second;
		int cost = e.first;
		if (tree.root(u) != tree.root(v)){
			g[u].push_back({ cost, v });
			g[v].push_back({ cost, u });
			tree.join(u, v);
		}
	}
}

int v[2001];

void DFS(int src, int par , ll tot){
	v[src] = tot;
	for (auto &e : g[src]){
		if (e.second != par){

			DFS(e.second, src, tot + e.first);
		}
	}
}
int main(){
	fast();
	cin >> n;
	bool ok = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int x;
			cin >> x;
			grid[i][j] = x;
			if (j > i){
				ok &= (x > 0);
				ed.push_back({ x, { i, j } });
			}
			else if (i == j){
				ok &= !x;
			}
		}
	}
	if (!ok){
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n; i++){
		for (int j =i + 1; j < n; j++){
			if (grid[i][j] != grid[j][i]){
				ok = 0;
			}
		}
	}
	if (!ok){
		cout << "NO\n";
		return 0;
	}
	sort(ed.begin(), ed.end());
	kruskal();

	for (int i = 0; i < n; i++){
		DFS(i, -1, 0);
		for (int j = 0; j < n; j++){
			ok &= (grid[i][j] == v[j]);
		}
		if (!ok){
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}
