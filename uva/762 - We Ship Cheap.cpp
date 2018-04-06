#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
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
int n, node;
vector<string>a;
map<string, int>ind;
vector<int> g[1000 * 100 + 1];
void add_node(string s ){
	if (ind[s] == 0){
		ind[s] = node + 1;
		node++;
	 a.push_back(s);
	}
}
int main()
{
	fast();
	int cnt = 0;
	while (cin >> n){
		if (cnt)
			cout <<endl;
		cnt++;
		a.clear();
		ind.clear();
		node = 0;
		for (int i = 0; i < 100 * 1000 + 1; i++)
			g[i].clear();

		for (int i = 0; i < n; i++){
			string s, t;
			cin >> s >> t;
			
			add_node(s); add_node(t);
			g[ind[s]].push_back(ind[t]);
			g[ind[t]].push_back(ind[s]);
		}

		string s, t;
		cin >> s >> t;
		add_node(s); add_node(t);
		vector<bool>vis(node+1 , 0);
		vector<int>par(node + 1 , -1);
		queue<int>q; q.push(ind[s]);
		par[ind[s]] = -1;
		while (q.size()){
			int cur = q.front(); q.pop();
			vis[cur] = 1;
			for (auto e : g[cur]){
				if (!vis[e]){
					q.push(e);
					par[e] = cur;
				}
			}
		}

		if (par[ind[t]] == -1){
			cout << "No route\n";
		}
		else{
			vector<string>path;
			int des = ind[t];
			while (des != -1){
				path.push_back(a[des-1]);
				des = par[des];
			}
			for (int i = path.size()-1; i > 0; i--)
				cout << path[i] << " " << path[i - 1] << endl;
		}
	}

	return 0;
}
