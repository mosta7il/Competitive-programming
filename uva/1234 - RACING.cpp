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
int n, m, t;
struct dsu{
	int g[100 * 100 + 2];

	dsu(int n){
		for (int i = 1; i <= n; i++)
			g[i] = i;
	}

	int root(int a){
		if (a == g[a])
			return a;
		return g[a] = root(g[a]);
	}

	void join(int a, int b){
		int ra = root(a);
		g[ra] = b;
	}
};

vector< pair< int, pair< int, int> > > edge;

void krsukal(int &cost){
	dsu tree(n);
	
	for (int i = edge.size() - 1; i >= 0;i--){
		auto x = edge[i];
		int u = x.second.first, v = x.second.second;
		if (tree.root(u) != tree.root(v)){
			cost -= x.first;
			tree.join(u, v);
		}
	}

}
int main(){
	fast();
	cin >> t;
	while (t--){
		edge.clear();
		cin >> n >> m;
		int ret = 0;
		for (int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			edge.push_back({ c, { u, v } }); 
			ret += c;
		}
		sort(edge.begin(), edge.end());
		krsukal(ret);
		cout << ret << endl;
	}
	return 0;
}
