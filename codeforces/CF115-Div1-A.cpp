#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int vis[2001];
vector<int>G[2001]; int n, mx;
void dfs(int u , int dep){
	vis[u] = 1;
	for (int i = 0; i < G[u].size(); i++){
		int ve = G[u][i];
		if (!vis[ve]){
			dfs(ve , dep+1);
		}
	}
	mx = max(mx, dep);
}

int main(){
	fast();
	cin >> n;
	vector<int>p;
	for (int i = 0; i < n; i++){
		int w; cin >> w;
		if (w == -1)p.push_back(i + 1);
		else { G[w].push_back(i + 1); }
	}
	for (int i = 0; i < p.size(); i++){
		dfs(p[i] , 1);
	}
	cout << mx << endl;
	return 0;
}
//mosta7il_
