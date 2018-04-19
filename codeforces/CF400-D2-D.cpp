#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e6;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m, k;
long long type[501];
long long g[501][501];

int getT(int x){

	for (int i = 1; i <= k; i++){
		if (type[i] >= x)
			return i;
	}
}
int cnt;
void floyd(){

	for (int w = 1; w <= k; w++){
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= k; j++){
				g[i][j] = min(g[i][w] + g[w][j], g[i][j]);
			}
		}
	}

}

struct dsu{
	int par[1000 * 100 + 5];
	int rank[1000 * 100 + 5];
	dsu(int n){
		for (int i = 1; i <= n; i++){
			par[i] = i;
			rank[i] = 1;
		}
	}

	int find_root(int a){
		if (a == par[a])
			return a;
		return par[a] = find_root(par[a]);
	}

	void join(int a, int b){
		int ra = find_root(a), rb = find_root(b);
		if (ra == rb)
			return;
		if (rank[rb] > rank[ra])
			swap(ra, rb);
		par[rb] = ra;
		if (rank[ra] == rank[rb])
			rank[ra]++;
	}
};
int main(){
	fast();
	fill(g[0], g[0] + 501 * 501, OO);
	cin >> n >> m >> k;
	dsu conn(n);
	for (int i = 1; i <= k; i++){
		cin >> type[i];
		if (type[i] == 1){
			g[i][i] = 0;
		}
		type[i] += type[i - 1];
	}

	for (int i = 0; i < m; i++){
		int u, v; 
		long long c;
		cin >> u >> v >> c;
		int l = getT(u), r = getT(v);
		if (c == 0){
			if (conn.find_root(u) != conn.find_root(v)){
				conn.join(u, v);
			}
		}
		g[l][r] = min(g[l][r], c);
		g[r][l] = min(g[r][l], c);
	}
	
	for (int i = 1; i <= k; i++){
		for (int j = type[i - 1] + 1; j <= type[i]; j++){
			if (conn.find_root(type[i]) != conn.find_root(j)){
				cout << "No\n";
				return 0;
			}
		}
	}
	floyd();

	cout << "Yes\n";
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= k; j++)
		if (g[i][j] >= OO)cout << -1 << " ";
		else cout << g[i][j] << " ";
		cout << endl;
	}
	return 0;
}
