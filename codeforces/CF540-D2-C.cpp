#include<bits\stdc++.h>
const int oo = 1e9;
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m;
pair<int, int>s, e;
char g[501][501];
bool vis[501][501];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool isv(int i, int j){
	return (i >= 0 && j >= 0 && i < n&&j < m);
}
bool dfs(int i, int  j ){
	if (i == e.first - 1 && j == e.second - 1){
		if (vis[i][j]) return 1;
	}
		if (vis[i][j])return 0;
		vis[i][j] = 1;
	bool res = 0;
	for (int dir = 0; dir < 4; dir++){
		int nx = dx[dir] + i; int ny = dy[dir] + j;
		if (isv(nx, ny)){
			res |= dfs(nx, ny );
		}
	}
	return (res);
}
int main(){
	fast();
	cin >> n >> m;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){
		cin >> g[i][j]; if (g[i][j] == 'X')vis[i][j] = 1;
	}
	cin >> s.first >> s.second >> e.first >> e.second;
	vis[s.first-1][s.second-1] = 0;
	bool res = dfs(s.first - 1, s.second - 1 );
	cout << (res ? ("YES\n") : ("NO\n"));

	return 0;
}
//mosta7il_
