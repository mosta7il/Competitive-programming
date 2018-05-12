#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, k;
int curConn;
char g[1001][1001];
int vis[1001][1001];

vector<int> ansOfConn;
bool isv(int i, int j){
	return (i >= 0 && i < n&&j >= 0 && j < m&&vis[i][j] == -1);
}
int dfs(int x, int y){

	if (vis[x][y] != -1){
		return ansOfConn[vis[x][y]];
	}
	vis[x][y] = curConn;
	int cnt = 0;
	for (int i = 0; i < 4; i++){
		int ii = dx[i] + x, jj = dy[i] + y;
		if (isv(ii, jj) && g[ii][jj] == '*')
			cnt++;
	}
	for (int i = 0; i < 4; i++){
		int nxtx = x + dx[i], nxty = y + dy[i];
		if (isv(nxtx, nxty) && g[nxtx][nxty] != '*'){
			cnt += dfs(nxtx, nxty);
		}
	}

	return cnt;
}
int main() {
	fast();
	memset(vis, -1, sizeof vis);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		cin >> g[i][j];
	for (int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		int ret = dfs(x, y);
		cout <<ret<< endl;
		if (ansOfConn.size() == vis[x][y]){
			ansOfConn.push_back(ret);
			curConn++;
		}
	}
	return 0;
}
