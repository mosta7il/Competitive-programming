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
int n, m;

struct edge{
	int u, v, c;
	edge(int u, int v, int c){
		this->u = u, this->v = v, this->c = c;
	}
	bool operator < (const edge &e)const{
		return c > e.c;
	}
};
vector<edge> ed;

struct dsu{
	int g[500];

	dsu(int n){
		for (int i = 1; i <= n; i++)
			g[i] = i;
	}

	int root(int a){
		if (g[a] == a)
			return a;
		return g[a] = root(g[a]);
	}

	void join(int a, int b){
		int ra = root(a), rb = root(b);
		g[ra] = b;
	}
};

int kruskal(int src , int des){

	int mn = 1e9;
	dsu tree(n);
	for (auto e : ed){
		int u = e.u, v = e.v;
		if (tree.root(src) == tree.root(des))
			break;
		if (tree.root(u) != tree.root(v)){
			tree.join(u, v);
			mn = min(mn, e.c);
		}
	}
	return mn;
}
int main(){
	fast();
	int cnt = 1;
	while (cin >> n >> m&&n){
		ed.clear();
		for (int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			ed.push_back(edge(u, v, c));
		}
		sort(ed.begin(), ed.end());
		int src, des, tot;
		cin >> src >> des >> tot;
		int ret = kruskal(src, des);
		ret--;

		cout << "Scenario #" << cnt++ << endl;
		cout << "Minimum Number of Trips = ";
		cout << (int)ceil(tot * 1.0 / ret) << endl << endl;
	}
	return 0;
}
