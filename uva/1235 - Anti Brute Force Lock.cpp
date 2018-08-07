#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
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
const long long MAX = 501  + 1;

struct edge{
	int u, v;
	int cost;
	edge(int x, int y, int c){
		u = x, v = y;
		cost = c;
	}

	bool operator < (const edge & e)const{
		return cost < e.cost;
	}
};
struct dsu{
	int par[MAX];

	dsu(int n){
		for (int i = 0; i < n; i++)
			par[i] = i;
	}

	int root(int a){
		if (par[a] == a)
			return a;
		return par[a] = root(par[a]);
	}

	void join(int a, int b){
		int ra = root(a), rb = root(b);
		par[ra] = rb;
	}
};
int dist(string a, string b){
	int ret = 0;
	for (int i = 0; i < 4; i++){
		ret += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
	}
	return ret;
}
int t, n;
string a[MAX];
vector<edge> v;

int kruskal(){

	int cost = 0;
	dsu tree(n);
	
	for (auto e : v){
		int x = e.u, y = e.v;

		if (tree.root(x) != tree.root(y)){
			tree.join(x, y);
			cost += e.cost;
		}
	}
	return cost;
}
int main(){
	fast();

	cin >> t;
	while (t--){
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				v.push_back(edge(i, j, dist(a[i], a[j])));
			}
		}
		sort(v.begin(), v.end());
		int w = kruskal();
		int mn = OO;
		for (int i = 0; i < n; i++){
			mn = min(mn, dist("0000", a[i]));
		}

		cout << mn + w << endl;
	}
	
	return 0;
}
