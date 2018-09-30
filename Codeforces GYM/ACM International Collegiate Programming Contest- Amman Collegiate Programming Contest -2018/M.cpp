#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


const long long OO = 1e8;
const long long mod = 1e9 + 7;
const long double EPS = (1e-12);
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

const long long MAX =  100 * 1000 + 5;
int t, n, q;
vector< vector< pair<int , pair<int ,int > > > >g;
vector<int>Euler, Level, Fo;
vector< long long > up, down;
vector< vector<int> >tree;
int Time; long long tot;
void init(int n){
	Time = 1; tot = 0;
	g.clear();	up.clear(), down.clear();
	Euler.clear(); Level.clear(); Fo.clear();
	g.resize(n); up.resize(n); down.resize(n); tree.clear();
	Euler.resize(2 * n); Level.resize(2 * n); Fo.resize(n); tree.resize(2 * n, vector<int>(17, 0));
}
void DFS(int src, int par, int dep){
	Euler[Time] = src;
	Level[Time] = dep;
	Fo[src] = Time++;

	for (auto e : g[src]){
		if (e.first != par){
			down[e.first] = down[src] + e.second.first;
			up[e.first] = up[src] + e.second.second;
			DFS(e.first, src , dep+1);
			Euler[Time] = src;
			Level[Time++] = dep;
		}
	}

}
void build(){
	for (int i = 1; i < 2 * n; i++){
		tree[i][0] = i;
	}

	for (int i = 1; (1 << i) < 2 * n; i++){
		for (int j = 1; j < 2 * n; j++){
			if (j + (1 << i)-1 >= 2 * n)break;
			tree[j][i] = ((Level[tree[j][i - 1]] <= Level[tree[j + (1 << i - 1)][i - 1]]) ? tree[j][i - 1] : tree[j + (1 << i - 1)][i - 1]);
		}
	}
}

int query(int x, int y){
	int dis = (y - x + 1);
	int lo = log2(dis);
	return ((Level[tree[x][lo]] <= Level[tree[y - (1 << lo) + 1][lo]]) ? tree[x][lo] : tree[y - (1 << lo) + 1][lo]);
}
int main() {
	fast();
	cin >> t;
	while (t--){
		cin >> n;
		init(n);
		for (int i = 1; i < n; i++){
			int u, v, c1, c2;
			cin >> u >> v >> c1 >> c2;
			tot += c1 + c2;
			u--, v--;
			g[u].push_back({ v, { c1, c2 } });
			g[v].push_back({ u, { c2, c1 } });
		}
		DFS(0, -1, 0);
		build();
		cin >> q;

		while (q--){
			int u, v;
			cin >> u >> v;
			u--, v--;
			int x = Fo[u], y = Fo[v];
			if (x > y){
				swap(x, y);
				//swap(v, u);
			}
			int lca = Euler[query(x , y)];
			long long l = down[u] - down[lca];
			long long r = up[v] - up[lca];
			cout << (tot - l - r) << "\n";
		}
	}
	
	return 0;
}
