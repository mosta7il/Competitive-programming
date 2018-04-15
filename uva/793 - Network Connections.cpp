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

int t, n;
string s;
int u, v;
char x;
struct dsu{
	int par[MAX];
	int rank[MAX];

	dsu(int n){
		for (int i = 1; i <= n; i++){
			par[i] = i;
			rank[i] = 1;
		}
	}
	int find_root(int a){
		if (par[a] == a)
			return a;
		return par[a] = find_root(par[a]);
	}
	void add_edge(int a, int b){
		int ra = find_root(a);
		int rb = find_root(b);
		if (ra == rb)
			return;
		if (rank[ra] > rank[rb])swap(ra, rb);
		par[ra] = rb;
		if (rank[ra] == rank[rb])
			rank[rb]++;
	}

	bool query(int a, int b){
		if (find_root(a) == find_root(b))
			return 1;
		return 0;
	}
};
int main(){
	fast();
	cin >> t;
	int id = 0;
	while (t--){
		if (id)
			cout << endl;
		id++;

		int cnt = 0, cnt1 = 0;
		cin >> n;
		cin.ignore();

		dsu g(n);
		while (getline(cin, s) && (int)s.size()){
			stringstream ss;
			ss << s;
			ss >> x >> u >> v;
			if (x == 'c'){
				g.add_edge(u, v);
			}
			else{
				g.query(u, v) ? cnt++ : cnt1++;
			}
		}
		cout << cnt << "," << cnt1 << endl;
	}

	return 0;
}
