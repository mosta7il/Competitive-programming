#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e6;
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
const long long MAX = 20 *1000 * 1000 + 1;

int n, m;
bool g[1001][1001]; int dest[1001][1001];
bool isv(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
int bfs(int x, int y , int xx , int yy){

	
	for (int i = 0; i < 1001; i++)for (int j = 0; j < 1001; j++)
		dest[i][j] = -1;

	queue< pair<int, int> >q;
	q.push({ x, y });
	dest[x][y] = 0;
	while (q.size()){
		int i = q.front().first, j = q.front().second;
		q.pop();
		if (i == xx&& j == yy)
			break;

		for (int d = 0; d < 4; d++){
			int ii = i + dx[d], jj = j + dy[d];
			if (isv(ii, jj) &&!g[ii][jj]&& dest[ii][jj] == -1){
				dest[ii][jj] = dest[i][j] + 1;
				q.push({ ii, jj });
			}
		}
		
	}

	return dest[xx][yy];
}
int main(){
	fast();
	while (cin >> n >> m &&n){
		memset(g, 0, sizeof g);
		int p; cin >> p;
		for (int i = 0; i < p; i++){
			int r , k; cin >>r>> k;
			for (int j = 0; j < k; j++){
				int c; cin >> c;
				g[r][c] = 1;
			}
		}
		pair<int, int> src, des;
		cin >> src.first >> src.second >> des.first >> des.second;
		cout << bfs(src.first, src.second, des.first, des.second) << endl;
	}

	
	return 0;
}
