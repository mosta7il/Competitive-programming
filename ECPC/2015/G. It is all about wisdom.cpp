#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e15;
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
int t;
int n, m, k;

struct dij_edge{
	long long to, wcost , mcost;
	dij_edge(int t, long long mc ,long long wc){
		to = t, mcost = mc , wcost = wc;
	}

	bool operator < (const dij_edge &e)const{
		return mcost > e.mcost;
	}
};
vector< dij_edge> adj[1000 * 100+1];
long long dist[100 * 1000 + 1];

long long dij(long long md){
	for (int i = 0; i <= n; i++){
		dist[i] = OO;
	}
	priority_queue< dij_edge >p;
	p.push(dij_edge(1, 0 , 0));
	dist[1] = 0;
	while (!p.empty()){

		auto cur = p.top();
		p.pop();

		if (dist[cur.to] < cur.mcost)
			continue;

		if (cur.to == n)
			return dist[n];

		for (auto &e : adj[cur.to]){
			if (e.wcost > md)
				continue;

			if (dist[e.to] > cur.mcost + e.mcost){
				dist[e.to] = cur.mcost + e.mcost;
				p.push(dij_edge(e.to, dist[e.to] , 0));
			}
		}
	}
	return dist[n];
}
int main(){
	fast();
	cin >> t;
	while (t--){
		
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
		}
		for (int i = 0; i < m; i++){
			int f,t, wc, mc;
			cin >>f>>t >> mc >> wc;
			adj[f].push_back(dij_edge(t, mc, wc));
			adj[t].push_back(dij_edge(f, mc, wc));
		}
		
		long long lo = 1, hi = 1000 * 1000 * 1000 + 1;
		long long ans = -1;
		while (lo <= hi){
			long long md = lo + hi >>1;
			
			long long ret = dij(md);
			if (ret < k){
				ans = md;
				hi = md - 1;
			}
			else lo = md + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
