#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
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
const long long MAX = 1000 + 1;
int n, m, l;
vector< vector<int> > g;
vector< bool > vis;

int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> l;
		g.clear();	g.resize(n);
		vis.clear();	vis.resize(n);
		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			x--, y--;
			g[x].push_back(y);
		}
		queue<int>q;
		for (int i = 0; i < l; i++){
			int x; cin >> x;
			if(!vis[x-1])
				q.push(x - 1);
			vis[x-1] = 1;
		}
		int ans = 0;
		while (q.size() > 0){
			int cur = q.front();
			q.pop();
			
			ans++;
			for (auto e : g[cur]){
				if (!vis[e]){
					vis[e] = 1;
					q.push(e);
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
