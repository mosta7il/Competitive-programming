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
int t, n, e, node;
vector< pair<long long, pair<int, int> > > edge , MST ;

struct dsu{
	int par[200];
	int rank[200];

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

	void join(int a, int b){
		int ra = find_root(a), rb = find_root(b);
		if (ra == rb)
			return;
		if (rank[rb] > rank[ra])
			swap(ra, rb);

		par[rb] = ra;
		if (rank[ra] == rank[rb])
			rank[ra]++;
	}
};

int  kruskal(pair<long long , pair<int , int> > blocked , bool f){

	dsu g(n);
	long long cost = 0;
	int cntBolcked = 0;

	for (int i = 0; i < edge.size(); i++){
		if (blocked == edge[i] && !cntBolcked){
			cntBolcked++;
			continue;
		}
		int u = edge[i].second.first,
			v = edge[i].second.second;
		long long w = edge[i].first;

		if (g.find_root(u) != g.find_root(v)){
			if(f)
				MST.push_back(edge[i]);
			cost += w;
			g.join(u, v);
			node--;
		}
	}
	return cost;
}
int main(){
	fast();
	cin >> t; int id = 1;
	while (t--){
		cout << "Case #" << id++ << " : ";

		edge.clear();
		MST.clear();

		cin >> n >> e;
		node = n-1;

		for (int i = 0; i < e; i++){
			int u, v; long long w;
			cin >> u >> v >> w;
			edge.push_back({ w, { u, v } } );
		}
		sort(edge.begin(), edge.end());
		long long MSTCost = kruskal({ -1, { -1, -1 } } , 1) , SMSTCost = 1e9;
		if (node != 0){
			cout << "No way\n";
			continue;
		}
		for (int i = 0; i < MST.size(); i++){
			node = n-1;
			long long tmp = kruskal(MST[i], 0);
			if (tmp >= MSTCost && node == 0){
				SMSTCost = min(tmp, SMSTCost);
			}
		}

		if (SMSTCost != 1e9){
			cout << SMSTCost << endl;
			continue;
		}

		cout << "No second way\n";
	}
	return 0;
}
