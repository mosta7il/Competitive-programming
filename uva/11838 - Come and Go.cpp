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
int n, m;
vector< int >g[2001];
int low[2001], dfn[2001], in[2001];
int dfsn;
vector< vector<int> >com;
stack<int> s;
void init(int n){

	for (int i = 0; i < n; i++)
		g[i].clear();
	memset(low, 0, sizeof low);
	memset(dfn, -1, sizeof dfn);
	memset(in, 0, sizeof in);
	dfsn = 0;
	com.clear();
	
}

void dfs(int src){
	low[src] = dfn[src] = dfsn++;
	in[src] = 1;
	s.push(src);
	for (auto e : g[src]){

		if (dfn[e] == -1){
			dfs(e);
			low[src] = min(low[e], low[src]);
		}
		else if (in[e]){
			low[src] = min(low[src], dfn[e]);
		}
	}

	if (low[src] == dfn[src]){
		com.push_back(vector<int>());
		int x = -1;
		while (x != src){
			x = s.top();
			com.back().push_back(x);
			s.pop();
			in[x] = 0;
		}
	}
}

int main(){
	fast();
	
	while (cin >> n >> m&&n){
		init(n);

		for (int i = 0; i < m; i++){
			int x, y, w;
			cin >> x >> y >> w;
			x--, y--;
			g[x].push_back(y);
			if (w == 2)
				g[y].push_back(x);
		}
		for (int i = 0; i < n; i++)
			if(dfn[i]==-1)
				dfs(i);

		if (com.size() == 1 && com[0].size() == n){
			cout << 1 << endl;
			continue;
		}
		cout << 0 << endl;
	}

	return 0;
}
