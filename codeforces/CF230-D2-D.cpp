#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
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
int n, m, k,  u, v, c;
vector<pair< int , long long> > g[100 * 1000 + 2];
set<pair< int, long long> > late[100 * 1000 + 2];

long long dist[1000 * 100 + 2];
int stopdeb;
void ssp(){

	for (int i = 0; i < 1000 * 100 + 2; i++)
		dist[i] = OO;
	priority_queue< pair<int, long long>  , vector< pair<int , int> > , greater<pair<int , int> > >q;
	q.push({ 0 , 1}); dist[1] = 0;

	while (q.size()){
		auto cur = q.top();
		q.pop();
		if (cur.second == n)
			break;
		if (cur.first > dist[cur.second])
			continue;
		long long from = cur.first;
		while ((late[cur.second].find({ from, cur.second }) != late[cur.second].end()))
			from++;
		for (auto i : g[cur.second]){
			auto nxt = i;
			long long ret = nxt.first  + from;
			if (ret < dist[nxt.second]){
				nxt.first = dist[nxt.second] = ret;
				q.push(nxt);
			}
		}
	}
}
int main() {
	fast();

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> c;
		g[u].push_back({ c, v });
		g[v].push_back({ c ,u });
	}

	for (int i =0; i < n; i++){
		cin >> k;
		while (k--){
			cin >> u;
			late[i+1].insert({ u , i+1});
		}
	}
	ssp();
	cout << ((dist[n] == OO) ? -1 : dist[n]) << endl;

	return 0;
}
