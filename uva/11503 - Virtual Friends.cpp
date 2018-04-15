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
const int MAX = 2e5+1;
int t, n , cnt;
map<string, int>ind;
void add_node(string s){
	if (ind[s])
		return;
	ind[s] = cnt++;
}

struct dsu{

	int par[MAX];
	int sz[MAX];
	void init(){
		for (int i = 1; i < MAX; i++){
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find_root(int a){
		if (par[a] == a)
			return a;
		return par[a] = find_root(par[a]);
	}

	void join(int a, int b){
		int ra = find_root(a), rb = find_root(b);
		if (rb == ra)
			return;
		par[ra] = rb;
		sz[rb] += sz[ra];
	}
};
dsu g;
int main(){
	fast();
	cin >> t;
	
	while (t--){
		cnt = 1;
		ind.clear();
		cin >> n;
		g.init();
		for (int i = 0; i < n; i++){
			string s, w;
			cin >> s >> w;
			add_node(s); add_node(w);
			g.join(ind[s], ind[w]);
			int root = g.find_root(ind[s]);
			cout << g.sz[root] << endl;
		}
	}
	

	return 0;
}
