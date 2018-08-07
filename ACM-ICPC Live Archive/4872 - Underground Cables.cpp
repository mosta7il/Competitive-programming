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
const long long MAX = 1000  + 1;

struct edge{
	int u, v;
	double cost;
	edge(int x, int y, double c){
		u = x, v = y;
		cost = c;
	}

	bool operator < (const edge & e)const{
		return dcmp(cost, e.cost) == -1;
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
int X[MAX], Y[MAX];
int n;
vector< edge > v;

double kruskal(){
	double cost = 0;
	dsu tree(n);
	for (auto e : v){
		int u = e.u, v = e.v;
		if (tree.root(u) != tree.root(v)){
			tree.join(u, v);
			cost += e.cost;
		}
	}
	return cost;
}
int main(){
	fast();

	while (cin >> n&&n){
		v.clear();
		for (int i = 0; i < n; i++){
			cin >> X[i] >> Y[i];
		}

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				v.push_back(edge(i, j, hypot(X[i] - X[j], Y[i] - Y[j])));
			}
		}
		sort(v.begin(), v.end());
		double ans = kruskal();
		cout << fixed << setprecision(2) << ans << endl;
	}
	
	return 0;
}
