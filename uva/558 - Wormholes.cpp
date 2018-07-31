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
const long long MAX = 2 * 1000 + 1;
int t;
int n, m, k;

struct edge{
	int u, v, cost;
	edge(int t, int f, int w){
		u = t, v = f, cost = w;
	}
};

int dist[1001];
vector< edge >v;
bool ford(){

	if (v.size() == 0)
		return 0;

	for (int i = 0; i < n; i++)
		dist[i] = OO;

	for (int i = 0; i < n; i++){
		
		for (auto &e : v){
			if (dist[e.v] > e.cost + dist[e.u]){

				dist[e.v] = e.cost + dist[e.u];
				if (i == n - 1)
					return 1;
			}
		}
	}

	return 0;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		v.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			int x, y, c;
			cin >> x >> y >> c;
			v.push_back(edge(x, y, c));
		}
		cout << (ford() ? "possible\n" : "not possible\n");
	}
	return 0;
}
