#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-9);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;
int dcmp(long double x, long double y)
{
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
const int MLOG = 20;
const int MAX = 2 * 100 * 1000 + 5;
int n, m;
long long result[MAX];

struct edge{
	int from, to, cost, idx;
	edge(){

	}
	edge(int f, int t, int w , int i){
		from = f, to = t, cost = w, idx = i;
	}

	bool operator < (const edge & e)const{
		return cost < e.cost;
	}
};
struct dsu{
	int g[MAX];
	
	dsu(int n){
		for (int i = 1; i <= n; i++){
			g[i] = i;
		}
	}

	int root(int a){
		if (g[a] == a)return a;
		return g[a] = root(g[a]);
	}
	void join(int a, int b){
		int ra = root(a), rb = root(b);
		g[ra] = rb;
	}
};
long long totalCost;
vector< edge > ed;
vector< pair< int, long long> > g[MAX];
long long dp[MAX][MLOG] , mx[MAX][MLOG];int depth[MAX];
void kruskal(){
	dsu tree(n);

	int idx = 0;
	for (auto &e : ed){

		int u = e.from, v = e.to, w = e.cost;
		if (tree.root(u) != tree.root(v)){
			tree.join(u, v);
			g[u].push_back({ v, w });
			g[v].push_back({ u, w });
			totalCost += w;
		}
		idx++;
	}
}

void dfs(int u, int parent , long long lst){
	dp[u][0] = parent;
	mx[u][0] = lst;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i].first;
		if (v == parent)continue;
		depth[v] = depth[u] + 1;
		dfs(v, u , g[u][i].second);
	}
}
long long mm;
int lca(int u, int v){
	if (depth[u] < depth[v])
		swap(u, v);
	for (int k = MLOG - 1; k >= 0; --k){
		if (depth[u] - (1 << k) >= depth[v]){
			mm = max(mm, mx[u][k]);
			u = dp[u][k];
		}
	}
	if (u == v)return u;
	for (int k = MLOG - 1; k >= 0; --k){
		if (dp[u][k] != dp[v][k]){
			mm = max(mm, mx[u][k]);
			mm = max(mm, mx[v][k]);
			u = dp[u][k];
			v = dp[v][k];
		}
	}
	mm = max(mm, mx[u][0]);
	mm = max(mm, mx[v][0]);
	return dp[u][0];
}
int main(){
	fast();

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;

		ed.push_back(edge(u, v, w , i));
	}
	sort(ed.begin(), ed.end());
	kruskal();
	memset(dp, -1, sizeof dp);
	memset(mx, 0, sizeof mx);
	dfs(1, -1 , 0);
	for (int k = 1; k < MLOG; ++k){
		for (int u = 1; u <= n; ++u){
			if (dp[u][k - 1] == -1)continue;
			dp[u][k] = dp[dp[u][k - 1]][k - 1];
			mx[u][k] = max(mx[dp[u][k - 1]][k - 1], mx[u][k - 1]);
		}
	}

	for (int i = 0; i < ed.size(); i++){
		mm = 0;
		int l = lca(ed[i].from, ed[i].to);
		result[ed[i].idx] = totalCost + ed[i].cost - mm;
	}

	for (int i = 0; i < ed.size(); i++){
		cout << result[i] << "\n";
	}
	return 0;
}
