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

int n;

struct dsu{
	int g[201];
	dsu(int n){

		for (int i = 0; i < n; i++)
			g[i] = i;
	}

	void join(int a , int b){
		int ra = root(a), rb = root(b);
		g[ra] = b;
	}

	int root(int a){
		if (g[a] == a)
			return a;
		return g[a] = root(g[a]);
	}

};
vector<pair< double, pair< int, int> > > edge;
vector< pair< double, pair< int, int> > > MST;
int X[201], Y[201];
double kruskal(){
	dsu tree(n);
	double mx = 0;
	for (auto x : edge){
		int u = x.second.first, v = x.second.second;
		if (tree.root(0) == tree.root(1))
			break;
		if (tree.root(u) != tree.root(v)){
			mx = max(mx, x.first);
			tree.join(u, v);
		}
	}
	return mx;
}
int main(){
	fast();
	int cnt = 1;
	while (cin >> n&&n){

		edge.clear();
		MST.clear();
		for (int i = 0; i < n; i++){
			cin >> X[i] >> Y[i];
		}

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				double des = hypot(X[i] - X[j], Y[i] - Y[j]);
				edge.push_back({ des, { i, j } });
			}
		}

		sort(edge.begin(), edge.end());
		double ans = kruskal();
		cout << "Scenario #" << cnt++ << endl;
		cout << "Frog Distance = ";
		cout << fixed << setprecision(3) << ans << endl << endl;;
	}
	return 0;
}
