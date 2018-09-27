#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-11);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 10 * 1000 + 5;

int n, cnt;
int top[MAX], down[MAX];
vector< vector< int > > g;

void DFS(int src, int par, bool f = 0){
	
	down[src] = cnt++;
	for (auto e : g[src]){
		if (par != e){
			if (!f){
				f = 1;
				top[e] = top[src];
			}
			else top[e] = down[src];
			DFS(e, src , 1);
		}
	}

}
int main() {
	fast();
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 2){
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 1 << endl;
		return 0;
	}
	cnt = 1;
	top[0] = cnt++;
	DFS(0, -1);

	for (int i = 0; i < n; i++){
		cout << top[i] << " " << down[i] << endl;
	}
	return  0;
}
