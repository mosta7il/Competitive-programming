#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
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
vector<int>g[MAX];
int dp[MAX][MLOG], depth[MAX];
int dist[MAX];

void bfs(vector<int> src){

	queue<int>q;
	for (auto &e : src){
		q.push(e);
		 dist[e] = 0;
	}
	while (q.size()){
		int cur = q.front();
		q.pop();

		for (auto &e : g[cur]){
			if (dist[e] > dist[cur] + 1){
				dist[e] = dist[cur] + 1;
				q.push(e);
			}
		}
	}
}
void dfs(int u, int parent){
	dp[u][0] = parent;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if (v == parent)continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}
int lca(int u, int v){
	if (depth[u] < depth[v])
		swap(u, v);
	for (int k = MLOG - 1; k >= 0; --k){
		if (depth[u] - (1ll << k) >= depth[v]){
			u = dp[u][k];
		}
	}
	if (u == v)return u;
	for (int k = MLOG - 1; k >= 0; --k){
		if (dp[u][k] != dp[v][k]){
			u = dp[u][k];
			v = dp[v][k];
		}
	}
	return dp[u][0];
}

int main(){
	fast();
	memset(dp, -1, sizeof dp);
	memset(dist, 62, sizeof dist);
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1 , -1);
	for (int k = 1; k < MLOG; ++k){
		for (int u = 1; u <= n; ++u){
			if (dp[u][k - 1] == -1)continue;
			dp[u][k] = dp[dp[u][k - 1]][k - 1];
		}
	}
	vector<int>src;

	int root = sqrt(m);
	src.push_back(1);
	for (int i = 0; i < m; i++){
		int type, u;
		cin >> type >> u;

		if ((i%root == 0)){
			bfs(src);
			src.clear();
		}
		if (type == 1){
			src.push_back(u);
		}
		else{
			int mn = dist[u];
			for (auto &e : src){
				int l = lca(e, u);
				mn = min(mn, depth[u] + depth[e]  - 2 * depth[l]);
			}
			cout << mn << "\n";
		}
	}
	return 0;
}
