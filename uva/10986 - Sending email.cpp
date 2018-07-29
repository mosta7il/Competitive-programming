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
const long long MAX = 20 *1000 * 1000 + 1;
struct edge{
	int cost,  to;
	edge(int w, int x){
		cost = w; to = x;
	}

	bool operator < (const edge& e)const{
		return cost > e.cost;
	}
};
int t;
int n, m, T , src;
vector<edge>adj[20001];
int dist[20001];

int msh_dijkstra(){

	for (int i = 0; i < n; i++)
		dist[i] = OO;
	dist[src] = 0;
	priority_queue< edge > q;
	q.push(edge(0, src));
	while (!q.empty()){

		auto cur = q.top();
		q.pop();

		if (dist[cur.to] < cur.cost)continue;

		if (cur.to == T)
			return dist[T];
		for (auto e : adj[cur.to]){

			if (dist[e.to] > cur.cost + e.cost){
				dist[e.to] = cur.cost + e.cost;
				q.push(edge(dist[e.to], e.to));
			}
		}
	}
	return dist[T];
}
int main(){
	fast();
	cin >> t;
	int tt = 1;
	while (t--){

		cin >> n >> m >> src >> T;

		for (int i = 0; i< n; i++)
			adj[i].clear();

		cout << "Case #" << tt++ << ": ";
		for (int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(edge(c, b));
			adj[b].push_back(edge(c, a));
		}
		int ret = msh_dijkstra();
		if (ret == OO){
			cout << "unreachable\n";
		}
		else cout << ret << endl;
	}
	
	return 0;
}
