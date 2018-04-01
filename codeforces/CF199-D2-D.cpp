#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
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
int n, k;
char g[2][1000 * 100 + 1];
bool vis[2][1000 * 100 + 1];
bool isv(int i, int j){
	if (j >= 0){
		if ( j < n && g[i][j] != 'X'&&!vis[i][j])
			return 1;
		else if (j >= n)
			return 1;
		return 0;
	}
	else return 0;

}
bool dfs(int i, int j, int w){
	queue< pair< int, pair<int, int> > > q;
	q.push({ w, { i, j } });
	while (!q.empty()){
		auto cur = q.front(); q.pop();
		if (cur.second.second >= n){
			return 1;
		}
		if (!isv(cur.second.first, cur.second.second))
			continue;
		vis[cur.second.first][cur.second.second] = 1;
		if (cur.first > cur.second.second){
			continue;
		}
		
		int ii = cur.second.first, jj = cur.second.second, ww = cur.first;
		
		q.push({ ww + 1, { ii, jj + 1 } });
		q.push({ ww + 1, { ii, jj - 1 } });
		q.push({ ww + 1, { !ii, jj + k} });
	}
	return 0;
}
int main(){
	fast();
	cin >> n >> k;
	for (int i = 0; i < 2;i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	if (dfs(0, 0, 0))
		cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
