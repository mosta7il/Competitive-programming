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
int c[201];
int dist[1001], par[1001];
vector< edge >v;
void ford(){
	
	for (int i = 1; i <= n; i++){
		dist[i] = OO;
		par[i] = -1;
	}
	dist[1] = 0;
	for (int i = 0; i<n-1;i++){
		for (auto &e : v){
			if (dist[e.u] >= OO)continue;
			if (dist[e.v] > e.cost + dist[e.u] ){
				par[e.v] = e.u;
				dist[e.v] = e.cost + dist[e.u];
				
			}
		}
	}
	for (auto &e : v){
		if (dist[e.u] >= OO)continue;
		if (dist[e.v] > e.cost + dist[e.u]){
			dist[e.v] = -OO;

		}
	}
}

int main(){
	fast();
	//cin >> t;
	int cnt = 1;
	while (cin>>n){

		cout << "Set #" << cnt++ << endl;
		v.clear();
		for (int i = 1; i <= n;i++)
			cin >> c[i];
		cin >> m;
		for (int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y ;
			v.push_back(edge(x, y, (c[y] - c[x]) * (c[y] - c[x]) * (c[y] - c[x])));
		}
		
		ford();
		
		cin >> k;
		
		for (int i = 0; i < k; i++){
			int x; cin >> x;
			if(dist[x] == OO ||dist[x] < 3)cout <<"?\n";
			else  cout << dist[x] << endl;
		}
	}
	return 0;
}
