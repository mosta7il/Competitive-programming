#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
const long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 5 * 100 * 1000 + 5;
int n, m;
int src, des;
vector< vector< int > > g;
bool conn[1001][1001];
vector<int>  BFS(int node){
	vector<int>dist(n, -1);
	queue<int>q;
	q.push(node);
	dist[node] = 0;
	while (q.size()){
		int cur = q.front();
		q.pop();

		for (auto e : g[cur]){
			if (dist[e] == -1){
				q.push(e);
				dist[e] = dist[cur] + 1;
			}
		}
	}
	return dist;
}
int main() {
	fast(); 
	cin >> n >> m >> src >> des;
	src--, des--;
	g.resize(n);

	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v; 
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		conn[u][v] = conn[v][u] = 1;
	}

	vector<int>distS = BFS(src);
	vector<int>distD = BFS(des);
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (!conn[i][j]){
				int L = distS[i] + distD[j] + 1,
					R = distS[j] + distD[i] + 1;
				L = min(L, R);
				if (L >=distS[des]){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
