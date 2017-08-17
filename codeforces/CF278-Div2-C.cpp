#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int a[101][101];
vector<int> G[101]; bool vis[101];
int n, m;
void dfs(int u){
	if (vis[u])return;
	vis[u] = 1; 
	for (int i = 0; i < G[u].size(); i++){
		int t = G[u][i]; dfs(t);
	}
}
int main(){
	fast();
	cin >> n >> m;
	int k;
	bool ff = 0;
	for (int i = 1; i <= n; i++){
		cin >> k;
		while (k--){
			ff = 1;
			int u; cin >> u; a[i][u] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (a[i][j]){
				for (int w = 1; w <= n; w++){
					if (w == i)continue;
					if (a[w][j])G[i].push_back(w);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (!vis[i]){ dfs(i); cnt++; }
		}
		if (ff)
		cout << cnt - 1 << endl;
		else cout << cnt << endl;
	return 0;
}
//mosta7il_
