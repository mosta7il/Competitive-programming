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
const long long MAX = 20 *1000 * 1000 + 1;

int t;
int n, m, b, d;
char g[1001][1001];
bool north[1001][1001], south[1001][1001];
int bestN[1001], bestS[1001];
bool isv(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
void Ndfs(int i, int j){
	north[i][j] = 1;

	for (int x = 0; x < 4; x++){
		int ii = i + dx[x], jj = j + dy[x];
		if (isv(ii, jj) && !north[ii][jj] && g[ii][jj] == '#')
			Ndfs(ii, jj);
	}
}
void Sdfs(int i, int j){
	south[i][j] = 1;

	for (int x = 0; x < 4; x++){
		int ii = i + dx[x], jj = j + dy[x];
		if (isv(ii, jj) && !south[ii][jj] && g[ii][jj] == '#')
			Sdfs(ii, jj);
	}
}
int mem[1001][101];
int rec(int idx , int rem){
	if (idx >= m){
		if (rem == 0)
			return 0;
		return 1e7;
	}
	int &ret = mem[idx][rem];
	if (ret != -1)
		return ret;
	ret = 1e9;
	ret = min(ret, rec(idx + 1, rem));
	if (rem > 0){
		ret = min(ret, rec(idx + d + 1, rem - 1) + abs(bestN[idx] - bestS[idx])-1);
	}
	
	return ret;
}
int main(){
	fast();
	//cin >> t;
	while (cin >> n >> m >> b >> d){
		memset(north, 0, sizeof north);
		memset(south, 0, sizeof south);
		memset(mem, -1, sizeof mem);
		

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> g[i][j];
			}
		}
		Ndfs(0, 0);
		Sdfs(n - 1, 0);
		for (int i = 0; i < m; i++){
			int lst = -1;
			for (int j = 0; j < n; j++){
				if (north[j][i])
					lst = j;
			}
			bestN[i] = lst;
			lst = -1;
			for (int j = n - 1; j >= 0; j--){
				if (south[j][i])
					lst = j;
			}
			bestS[i] = lst;
		}

		cout << rec(0, b) << endl;
	}
	return 0;
}
