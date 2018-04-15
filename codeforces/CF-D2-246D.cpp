#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h> 
using namespace std;

const long long OO = 1000;
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
const int MAX = 1e5+1;

int n, m;

set<int> g[MAX];
int c[MAX];
int main(){
	fast();
	cin >> n >> m;
	int mx = -1, mxi = 1e6;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		mxi = min(mxi, c[i]);
	}
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (c[u] != c[v]){
			g[c[u]].insert(c[v]);
			g[c[v]].insert(c[u]);
		}
	}

	for (int i = 1; i < MAX; i++){
		if ((int) g[i].size() && (int)g[i].size() > mx){
			mx = (int)g[i].size();
			mxi = i;
		}
	}
	cout << mxi << endl;
	return 0;
}
