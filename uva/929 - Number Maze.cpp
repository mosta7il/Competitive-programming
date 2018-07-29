#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e8;
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
int n, m;
int g[1001][1001];
int dist[1001][1001];
struct edge{
	int cost;
	int tox , toy;
	edge(int cost, int tox ,int toy){
		this->cost = cost, this->tox = tox, this->toy = toy;
	}

	bool operator <(const edge& e)const{
		return e.cost < cost;
	}
};
bool isv(int i, int j){
	return i >= 0 && j >= 0 && i < n&&j < m;
}
int die(){

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			dist[i][j] = OO;
	}
	priority_queue< edge > q;
	q.push(edge(g[0][0], 0, 0));
	dist[0][0] = g[0][0];
	while (!q.empty()){

		auto cur = q.top();
		q.pop();

		if (dist[cur.tox][cur.toy] < cur.cost)
			continue;
		if (cur.tox == n - 1 && cur.toy == m - 1)
			return dist[n - 1][m - 1];
		for (int i = 0; i < 4; i++){
			int ii = cur.tox + dx[i], jj = cur.toy + dy[i];
			if (isv(ii, jj)){
				if (dist[ii][jj] > cur.cost + g[ii][jj]){
					dist[ii][jj] = cur.cost + g[ii][jj];
					q.push(edge(cur.cost + g[ii][jj], ii, jj));
				}
			}
		}
	}
	return dist[n - 1][m - 1];
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
		cout << die() << endl;
	}
	
	return 0;
}
