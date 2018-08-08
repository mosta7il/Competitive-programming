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
const long long MAX = 30*1000 + 1;

int  n, m , k , d ,t;

struct dsu{
	int par[MAX], rank[MAX];

	dsu(int n){
		for (int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 1;
		}
	}

	int root(int a){
		if (par[a] == a)
			return a;
		return par[a] = root(par[a]);
	}

	void join(int a, int b){
		int ra = root(a), rb = root(b);
		par[ra] = rb;
		rank[rb] += rank[ra];
	}

	int maxSet(int n){
		int mx = rank[0];

		for (int i = 0; i < n; i++){
			mx = max(rank[i], mx);
		}
		return mx;
	}
};
vector < vector< pair< int, int> >  >g;

int dist(pair<int, int> i, pair<int, int> j){

	int r = i.first - j.first;
	int l = i.second - j.second;
	return r*r + l *l;
}
int check(int i, int j){
	int mn = OO;
	for (auto e : g[i]){
		for (auto x : g[j]){
			mn = min(mn, dist(e, x));
		}
	}

	return mn;
}
int main(){
	fast();
	cin >> t;
	int cnt = 0;
	while (t--){
		
		cin >> n >> m >> k >> d;
		k *= k; d *= d;

		g.clear();
		g.resize(n + m+100);
		dsu tree(m + n+100);
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			g[i].push_back({ x, y });
		}
		for (int i = m; i < n+m; i++){
			int b; cin >> b;
			for (int j = 0; j < b; j++){
				int x, y; cin >> x >> y;
				g[i].push_back({ x, y });
			}
		}

		for (int i = 0; i < n+m; i++){
			for (int j = i+1; j < n + m; j++){
				if (i < m && j < m)continue;

				if (i <m && check(i, j) <= d){
					tree.join(i, j);
				}
				else if (i >=m && check(i, j) <= k){
					tree.join(i, j);
				}
			}
		}

		bool ok = 0;
		for (int i = 0; i < m; i++){
			if (tree.root(i) == tree.root(m))
				ok = 1;
		}

		if (ok)
			cout << "Tree can be saved :)\n";
		else cout << "Tree can't be saved :(\n";
	}
	return 0;
}
