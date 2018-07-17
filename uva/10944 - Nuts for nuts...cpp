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
const long long MAX = 100 * 1000 + 1;

int n, m, p;
int shortest[16][16];
pair<int, int> a[16];
char g[21][21];
int mem[(1 << 16) + 1][16];
bool vis[21][21];

bool isv(int i, int j){

	return (i >= 0 && j >= 0 && i < n&&j < m);
}
int level[21][21];
void bfs(int i){
	queue<pair<int, int> > q;
	q.push({ a[i] });
	vis[a[i].first][a[i].second] = 1;
	level[a[i].first][a[i].second] = 0;
	while (q.size()){

		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 8; idx++){
			int ii = cur.first + dx[idx],
				jj = cur.second + dy[idx];
			if (isv(ii, jj) && !vis[ii][jj]){
				level[ii][jj] = level[cur.first][cur.second] + 1;
				vis[ii][jj] = 1;
				q.push({ ii, jj });
			}
		}
	}

}

int rec(int mask, int lst){
	if (mask == (1 << p) - 1){
		return shortest[0][lst];
	}
	int &ret = mem[mask][lst];
	if (ret != -1)
		return ret;
	ret = 1e6;
	for (int idx = 1; idx < p; idx++){
		if (mask & (1 << idx))
			continue;
		ret = min(ret , rec(mask | (1 << idx), idx) + shortest[lst][idx]);
	}
	return ret;
}
int main(){
	fast();
	while (cin >> n >> m){
		memset(mem, -1, sizeof mem);
		p = 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> g[i][j];
				if (g[i][j] == 'L')
					a[0] = { i, j };
				else if (g[i][j] == '#')
					a[p++] = { i, j };
			}
		}

		for (int i = 0; i < p; i++){
			memset(vis, 0, sizeof vis);
			memset(level, 0, sizeof level);
			bfs(i);
			for (int j = i+1; j < p; j++){
				shortest[i][j] = shortest[j][i] = level[a[j].first][a[j].second];
			}
		}

		cout << rec(1, 0) << endl;
	}
	return 0;
}
