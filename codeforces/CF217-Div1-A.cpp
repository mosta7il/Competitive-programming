#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
map<pair<int, int> , bool>g;
map<pair<int,int>, bool> vis;
int n, t;
void dfs(pair<int, int> v){
	vis[v] = 1;
	for (auto ii : g){
		if (!vis[ii.first]){
			if (v.first == ii.first.first || v.second == ii.first.second)
				dfs(ii.first);
		}
	}
}
int main(){
	fast();
	cin >> n;
	for (int i = 1; i <= n; i++){
		int u , v; cin >> u>>v;
		g[{u, v}] = 1;
	}
	int c = 0;
	for (auto ii : g){
		if (!vis[ii.first]){
			c++;
			vis[ii.first] = 1;
			dfs(ii.first);
		}
	}

	cout << c - 1 << endl;
	return 0;
}
//mosta7il_
