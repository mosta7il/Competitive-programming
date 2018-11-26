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
int n, m, cnt;
set<int>vis;
vector<int>conn;
set<int> forbidden[200 * 1000 + 1];

void bfs(int src){
	cnt++;
	vector<int>good;
	for (set<int>::iterator i = vis.begin(); i != vis.end();){
			set<int>::iterator it = (forbidden[src].lower_bound(*i));
			if (it != forbidden[src].end() && *it == *i)
				i++;
			else {
				int v = *i;
				good.push_back(*i);
				vis.erase(*i);
				i = vis.lower_bound(v);
			}
	}
	for (auto i : good)
		bfs(i);
}

int main(){
	fast();
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		forbidden[u].insert(v);
		forbidden[v].insert(u);
	}
	for (int i = 1; i <= n; i++)
		vis.insert(i);
	set<int>::iterator it;
	for (int i = 1; i <= n; i++){
		it = vis.lower_bound(i);
		if (it != vis.end()&&*it == i){
			vis.erase(i);
			bfs(i);
			conn.push_back(cnt);
			cnt = 0;
		}
		if (vis.size() == 0)
			break;
	}
	sort(conn.begin(), conn.end());
	cout << conn.size() << endl;
	for (auto e : conn){
		cout << e << " ";
	}
	return 0;
}
