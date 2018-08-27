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
const long long MAX = 10 * 100 * 1000 + 5;
int n, m;
int a[MAX];
vector< vector<int> > g;
vector<bool>vis;
vector<int>comp;
vector<int>ans;
void DFS(int src){

	vis[src] = 1;
	comp.push_back(src);
	for (auto e : g[src]){
		if (!vis[e])
			DFS(e);
	}
}
int main() {
	fast();
	cin >> n >> m;
	g.resize(n);
	vis.resize(n, 0);
	ans.resize(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	for (int i = 0; i < n; i++){
		if (!vis[i]){
			comp.clear();
			DFS(i);
			sort(comp.begin(), comp.end());
			vector<int>tmp;
			for (auto e : comp){
				tmp.push_back(a[e]);
			}
			sort(tmp.rbegin(), tmp.rend());
			for (int i = 0; i < tmp.size(); i++)
				ans[comp[i]] = tmp[i];
		}
	}

	for (auto e : ans)
		cout << e << " ";

	return 0;
}
