#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX =1000 + 1;
int n, m;
string g[MAX];
int ans[MAX][MAX];
bool vis[MAX][MAX];
int cell[5 * 1000 * 100 + 1];
bool isv(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m&&g[i][j] != '*';
}
int  bfs(int i, int j, int label){
	queue < pair<int, int> >q;
	q.push({ i, j });
	int cnt = 1;
	vis[i][j] = 1;
	ans[i][j] = label;
	while (q.size()){
		auto cur = q.front();
		q.pop();
		for (int idx = 0; idx < 4; idx++){
			int ii = cur.first + dx[idx],
				jj = cur.second + dy[idx];
			if (isv(ii, jj) && !vis[ii][jj]){
				vis[ii][jj] = 1;
				ans[ii][jj] = label;
				q.push({ ii, jj });
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	fast();
	cin >> n >> m;

	for (int i = 0; i < n; i++){
		cin >> g[i];
	}
	int label = 1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!vis[i][j]&&g[i][j] !='*'){
				cell[label] = bfs(i, j, label);
				label++;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (g[i][j] != '.'){
				int cnt = 1; set<int>st;
				for (int idx = 0; idx < 4; idx++){
					if (isv(dx[idx] + i, dy[idx] + j)){
						st.insert(ans[dx[idx] + i][j + dy[idx]]);
					}
				}
				for (auto x : st){
					cnt += cell[x];
				}
				cout << cnt % 10;
			}
			else cout << '.';
		}
		cout << endl;
	}
	return 0;
}
