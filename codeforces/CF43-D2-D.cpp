#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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
int n, m;
bool g[105][105];
vector<pair< int, int>>path;
bool isv(int i, int j){
	return (i > 0 && j > 0 && i <= n&&j <= m);
}
void dfs(int i, int j , int mask){
	g[i][j] = 1;
	path.push_back({ i, j });

	if (mask &(1 << 0)){
		if (isv(i , j +1)&& !g[i][j+1])
			dfs( i, j + 1 , mask);
	}
	if (mask &(1 << 1)){
		if (isv(i, j - 1) && !g[i][j - 1])
			dfs(i, j - 1 , mask);
	}
	if (mask & (1 << 2)){
		if (isv(i - 1, j) && !g[i - 1][j])
			dfs(i - 1, j,mask);
	}
	if (mask&(1 << 3)){
		if (isv(i + 1, j) && !g[i + 1][j])
			dfs(i + 1, j , mask);
	}
}
void print(){
	for (auto i : path)
		cout << i.first << " " << i.second << endl;
	cout << "1 1\n";
}
int main() {
	fast();
	
	cin >> n >> m;

	if (n == 1 && m > 2){
		dfs(1, 1, 1);
		cout << 1 << endl;
		cout << path.back().first << " " << path.back().second << " 1 1\n";
		print();
		return 0;
	}

	if (m == 1&&n >2){
		dfs(1, 1, 8);
		cout << 1 << endl;
		cout << path.back().first << " " << path.back().second << " 1 1\n";
		print();
		return 0;
	}

	if (n % 2 == 0){
		dfs(1, 1, 1);
		for (int i = 2; i <= n; i++){
			if (i % 2){
				auto node = path.back(); path.pop_back();
				g[node.first][node.second] = 0;
				dfs(i, 2, 1);
			}
			else{
				dfs(i, m, 2);
			}
		}
		if(n > 2)
			dfs(path.back().first - 1, path.back().second, 4);
		cout << 0 << endl;
		print();
	}
	else if (m % 2 == 0){
		dfs(1, 1, 8);
		for (int i = 2; i <= m; i++){
			if (i % 2){
				auto node = path.back(); path.pop_back();
				g[node.first][node.second] = 0;
				dfs(2, i, 8);
			}
			else{
				dfs(n, i, 4);
			}
		}
		if(m > 2)
			dfs(path.back().first, path.back().second - 1, 2);
		cout << 0 << endl;
		print();
	}
	else{
		dfs(1, 1, 15);
		cout << 1 << endl;
		cout << path.back().first << " " << path.back().second << " 1 1\n";
		print();
	}
	return 0;
}
