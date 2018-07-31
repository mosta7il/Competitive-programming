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
const long long MAX = 2 * 1000 + 1;
int n;

struct edge{
	int u, v;
	long long cost;
	edge(int t, int f, long long w){
		u = t, v = f, cost = w;
	}
};
vector< edge > v;
long long dist[101], par[101];
long long cost[101];
void ford(){

	for (int i = 1; i <= n; i++)
		dist[i] = OO , par[i] = -1;
	dist[1] = 0;

	for (int i = 0; i < n - 1; i++){

		for (auto &e : v){
			if (dist[e.u] >= OO)
				continue;
			if ((dist[e.v] >(dist[e.u] + cost[e.v])) && (dist[e.u] + cost[e.v]) < 100){
				dist[e.v] = (dist[e.u] + cost[e.v]);
			}
		}

	}
	for (int i = 0; i < n; i++)
	for (auto &e : v){
		if (dist[e.u] >= OO)
			continue;
		if ((dist[e.v] >(dist[e.u] + cost[e.v])) && (dist[e.u] + cost[e.v]) < 100){
			dist[e.v] = -OO;
		}
	}
}


int main(){
	fast();
	while (cin >> n&&n != -1){
		v.clear();

		
		for (int i = 1  ; i <= n; i++){
			int c, k;
			cin >> c >> k;
			cost[i] = -c;
			for (int j = 0; j < k; j++){
				int x; cin >> x;
				v.push_back(edge(i, x, 1));
			}
		}
		ford();
		if (dist[n] < 100){
			cout << "winnable\n";
		}
		else cout << "hopeless\n";
		
	}
	return 0;
}
