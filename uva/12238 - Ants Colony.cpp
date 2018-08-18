#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

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
	//freopen("hunter.in", "r", stdin);
}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 100 * 1000 + 5;

vector < vector < pair < int, long long> > > g;
int H[MAX], L[2 * MAX], E[2 * MAX];
long long cost[MAX];
int tree[8 * MAX];
int N, Q;
int idx = 1;
void DFS(int src, int par, int dep, long long len){
	H[src] = idx;
	E[idx] = src;
	L[idx++] = dep;
	cost[src] = len;
	for (auto e : g[src]){
		if (par != e.first){
			DFS(e.first, src, dep + 1, len + e.second);
			E[idx] = src;
			L[idx++] = dep;
		}
	}
}


void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = l;
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	build(left, l, md); build(right, md + 1, r);
	if (L[tree[left]] <= L[tree[right]])
		tree[cur] = tree[left];
	else tree[cur] = tree[right];
}

int query(int cur, int l, int r, int x, int y){
	if (x <= l && y >= r)
		return tree[cur];
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	if (y <= md)
		return query(left, l, md, x, y);
	else if (x > md)
		return query(right, md + 1, r, x, y);
	else{
		int one = query(left, l, md, x, y);
		int two = query(right, md + 1, r, x, y);

		if (L[one] <= L[two])
			return one;
		else return two;
	}
}
int main() {
	fast();
	
	while (cin >> N && N){
		g.clear(); g.resize(N);
		idx = 1;
		for (int i = 0; i < N - 1; i++){
			int u; long long c;
			cin >> u >> c;
			g[i+1].push_back({ u, c });
			g[u].push_back({ 1+i, c });
		}
	

		DFS(0, -1, 0, 0);
		build(1, 1, 2 * N);

		cin >> Q;
		while (Q--){
			int u, v;
			cin >> u >> v;
			int l = H[u], r = H[v];
			if (l > r){
				swap(l, r);
				swap(v, u);
			}
			int lca = query(1, 1, 2 *N, l, r);
			lca = E[lca];
			long long lcost = cost[u] - cost[lca],
				rcost = cost[v] - cost[lca];
			cout << lcost + rcost;
			if (Q)cout << " ";
		}
		cout << "\n";
	}


	return 0;
}
