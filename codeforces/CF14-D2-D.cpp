#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 5000;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
bool vis[201];
vector<int> g[201];
vector< pair < int, int> > edge;
int mx;
pair< int , int> ret;
void dfs(int src , pair<int , int> block, int dep){
	vis[src] = 1;
	for (auto e : g[src]){
		if (block == make_pair(min(src, e), max(src, e)))
			continue;
		if (!vis[e]){
			dfs(e , block,dep+1);
		}
	}
	if (dep > ret.first){
		ret = { dep, src };
	}
}
int main() {
	fast();

	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		edge.push_back({ min(a, b), max(a, b) });
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < edge.size(); i++){
		int res = 1;
		memset(vis, 0, sizeof vis);
		dfs(edge[i].first, edge[i], 0);
		auto cur = ret;
		ret = { 0, 0 };
		memset(vis, 0, sizeof vis);
		dfs(cur.second, edge[i], 0);
		res *= ret.first;

		ret = { 0, 0 };

		memset(vis, 0, sizeof vis);
		dfs(edge[i].second, edge[i], 0);
		cur = ret;
		ret = { 0, 0 };
		memset(vis, 0, sizeof vis);
		dfs(cur.second, edge[i], 0);
		res *= ret.first;
		ret = { 0, 0 };
		mx = max(res, mx);
	}
	cout << mx << endl;
	return 0;
}
