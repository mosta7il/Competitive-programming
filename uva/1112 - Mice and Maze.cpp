#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e8;
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
vector<edge>adj[101];
int dist[101];
void Hala_Madrid_Y_Nada_Mas(){

	for (int i = 0; i <= n; i++)
		dist[i] = OO;
	dist[src] = 0;

	priority_queue<edge>q;
	q.push(edge(0, src));
	while (!q.empty()){

		auto cur = q.top(); q.pop();

		if (cur.cost > dist[cur.to])continue;

		for (auto e : adj[cur.to]){
			if (cur.cost + e.cost < dist[e.to]){
				dist[e.to] = cur.cost + e.cost;
				q.push(edge(cur.cost + e.cost, e.to));
			}
		}
	}
}
int main(){
	fast();
	cin >> t;
	int tt = 1;
	while (t--){
		if (tt > 1)
			cout << endl;
		tt++;
		for (int i = 0; i <= 100; i++)
			adj[i].clear();

		cin >> n >> src >> T >> m;
		for (int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			adj[b].push_back(edge(c, a));
		}

		Hala_Madrid_Y_Nada_Mas();
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (dist[i] <= T){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
