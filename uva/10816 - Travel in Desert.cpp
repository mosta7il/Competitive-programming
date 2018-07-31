#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e9;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long long MAX = 2 * 1000 + 1;
int n, m, s, t;
struct edge{
	int u, v;
	int tmpcost, distcost;

	edge (int x, int y, int tmp, int dis){
		u = x, v = y, tmpcost = tmp, distcost = dis;
	}

	bool operator < (const edge  & e)const{
		return distcost > e.distcost;
	}
};

vector<edge>adj[101];
int dist[101];
int par[101], tmp_par[101];
int dijkstra(int md){
	for (int i = 1; i <= n; i++){
		tmp_par[i] = -1;
		dist[i] = OO;
	}
	priority_queue<edge> q;
	q.push(edge(-1, s, 0, 0));
	dist[s] = 0;
	while(!q.empty()){
		edge cur = q.top();
		q.pop();

		if (cur.distcost > dist[cur.v])
			continue;

		tmp_par[cur.v] = cur.u;

		for (auto e : adj[cur.v]){
			if (e.tmpcost > md)
				continue;
			if (dist[e.v] > cur.distcost + e.distcost){
				dist[e.v] = cur.distcost + e.distcost;
				q.push(edge(e.u, e.v, e.tmpcost, dist[e.v]));
			}
		}
	}
	return dist[t];
}
int main(){
	fast();
	while (cin >> n >> m >> s >> t){
		
		for (int i = 1; i <= n; i++)
			adj[i].clear();

		for (int i = 0; i < m; i++){
			int u, x; double tmp, dist;
			cin >> u >> x>> tmp >> dist;
			adj[u].push_back(edge(u, x, tmp * 10, dist * 10));
			adj[x].push_back(edge(x, u, tmp * 10, dist * 10));
		}

		int lo = 200, hi = 500;
		pair<int, int>ans;
		while (lo <= hi){
			int md = lo + hi >> 1;
			int ret = dijkstra(md);
			if (ret != OO){
				hi = md - 1;
				for (int i = 0; i <= n; i++)
					par[i] = tmp_par[i];
				ans = { md , ret};
			}
			else lo = md + 1;
		}
		vector<int>path;
		while (t != -1){
			path.push_back(t);
			t = par[t];
		}

		for (int i = path.size()-1; i >= 0; i--){
			cout << path[i];
			if (i != 0)cout << " ";
		}
		cout << endl;
		cout << fixed << setprecision(1) << ans.second / 10.0 << " " << ans.first / 10.0 << endl;
	}
	return 0;
}
