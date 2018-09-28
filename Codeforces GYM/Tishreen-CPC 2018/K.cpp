#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

 long long  OO = 1e17;
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
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 1000 * 1000  + 5;
int t, n, m, k, src, des;
vector< vector< pair< long long, pair< int, int> > > > g;
priority_queue< pair< long long, pair< int, int> >, vector <pair< long long, pair< int, int> > >, greater<pair< long long, pair< int, int> >> >q;

long long dist[1000 *100 + 5][101];
long long ans;
int lp[MAX];
bool p[MAX];
map < int, bool > a[MAX];
void sieve(){
	for (int i = 2; i < MAX; i++)lp[i] = i;
	for (long long i = 2; i * i <= MAX; i++){
		if (!p[i]){
			for (long long j = i*i; j < MAX; j += i){
				p[j] = 1;
				if (lp[j] == j)lp[j] = i;
			}
		}
	}
}

void dijkstra(){

	memset(dist, 63, sizeof dist);
	OO = ans = dist[0][0];
	dist[src][0] = 0;
	q.push({ 0, { src, 0 } });
	while (q.size() > 0){
		auto cur = q.top();
		q.pop();

		if (cur.first > dist[cur.second.first][cur.second.second])
			continue;

		for (auto e : g[cur.second.first]){
			int v = e.second.first;
			long long cost = e.first;
			int d = e.second.second + cur.second.second;
			if (dist[v][d] > cost + cur.first && d <= k){
				dist[v][d] = cost + cur.first;
				q.push({ dist[v][d], { v, d } });
			}
		}

	}
}
int main() {
	fast();
	sieve();

	for (int i = 2; i < MAX; i++){
		int cur = i;
		while (cur != lp[cur]){
			a[i][lp[cur]] = 1;
			cur /= lp[cur];
		}
		a[i][cur] = 1;
	}

	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		g.clear();
		g.resize(n);
		for (int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back({ w, { v, 0 } });
			g[v].push_back({ w, { u, 0 } });
			for (auto e : a[w]){
				g[u].push_back({ w / e.first+ 2 * e.first, { v, 1 } });
				g[v].push_back({ w / e.first+ 2 * e.first, { u, 1 } });
			}
		}
		cin >> src >> des;
		src--, des--;
		dijkstra();
		for (int i = 0; i <= k; i++){
			ans = min(ans, dist[des][i]);
		}
		if (ans == OO)
			cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return  0;
}
