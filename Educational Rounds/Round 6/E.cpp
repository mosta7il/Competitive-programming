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

}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 4 * 100 * 1000 + 5;

int n, m;
vector< vector<int> > g;
int col[MAX];
int S[MAX], E[MAX];
long long tree[8 * MAX];
pair<int, int>a[MAX];
int lazy[8 * MAX];
int idx = 1;
void DFS(int src, int par){
	S[src] = idx;
	E[src] = idx++;
	for (auto e : g[src]){
		if (par != e){
			DFS(e, src);
			E[src] = idx++;
		}
	}
}
void propgate(int cur, int l, int r){
	if (lazy[cur]){
		tree[cur] = (1ll << (lazy[cur]) );
		if (l != r){
			lazy[cur * 2] = lazy[cur];
			lazy[cur * 2 + 1] = lazy[cur];
		}
		lazy[cur] = 0;
	}
}
void update(int cur, int l, int r, int x, int y, int val){
	propgate(cur, l, r);
	if (x <= l && y >= r){
		tree[cur] = 0;
		tree[cur] |= (1ll<<val);
		if (l != r){
			lazy[cur * 2] = val;
			lazy[cur * 2 + 1] = val;
		}
		return;
	}
	if (y < l || x > r)
		return;
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	update(left, l, md, x, y, val);
	update(right, md + 1, r, x, y, val);
	tree[cur] = 0;
	tree[cur] = (tree[left]) | (tree[right]);
}

long long query(int cur, int l, int r, int x, int y){
	propgate(cur, l, r);
	if (x <= l && y >= r){
		return tree[cur];
	}
	if (y < l || x > r)
		return 0 ;
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	long long one = query(left, l, md, x, y);
	long long two = query(right, md + 1, r, x, y);


	return two|one;
}
bool cmp(pair<int, int> i, pair<int, int>j){
	return (i.first < j.first);
}
int main() {
	//fast();
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for (int i = 0; i < n; i++){
		scanf("%d", &col[i + 1]);
		
	}
	for (int i = 0; i < n - 1; i++){
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1, -1);
	for (int i = 0; i < n; i++){
		a[i] = { S[i + 1], i + 1 };
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++){
		int cur = a[i].second;
		update(1, 1, 2 * n - 1, S[cur], E[cur], col[cur]);
	}
	for (int i = 0; i < m; i++){
		int t; cin >> t;
		if (t == 1){
			int vv, c;
			scanf("%d %d", &vv, &c);
			update(1, 1, 2 * n - 1, S[vv], E[vv], c);
		}
		else{
			int vv;
			scanf("%d", &vv);
			long long ans = query(1, 1, 2 * n - 1, S[vv], E[vv]);
			int cnt = 0;
			for (int ii = 0; ii <= 60; ii++){
				cnt += (ans&(1ll << ii))>0ll;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
