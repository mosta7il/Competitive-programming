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
const long long MAX = 100  + 1;

int dfs_num[MAX], dfs_low[MAX], parent[MAX], artPoints[MAX];
bool visited[MAX];

vector< vector<int> > graph;
int n , m, counter, root, rootChildren;
map<string, int> ind;
string arr[MAX];
void init(int n)
{
	counter = 0;
	graph.clear();
	graph.resize(n);
	ind.clear();
	int i;
	for (i = 0; i<n; i++)
	{
		visited[i] = 0;
		artPoints[i] = 0;
		dfs_num[i] = dfs_low[i] = 0; parent[i] = i;
	}
}

void dfs(int u)
{
	dfs_num[u] = dfs_low[u] = ++counter;
	for (int v : graph[u])
	if (dfs_num[v] == 0)
	{
		parent[v] = u;
		if (u == root)
			++rootChildren;
		dfs(v);
		if (dfs_low[v] >= dfs_num[u])
			artPoints[u] = true;
		
		if (dfs_low[v] > dfs_num[u]){
			//cout << "Bridge between " << u << " " << v << endl;
		}
		dfs_low[u] = min(dfs_low[v], dfs_low[u]);
	}
	else
	if (parent[u] != v)
		dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

void findArtPointsAndBridges()
{
	for (int i = 0; i < n; ++i)
	if (dfs_num[i] == 0)
	{
		root = i;
		rootChildren = 0;
		dfs(i);
		if (rootChildren <= 1)
			artPoints[i] = false;
	}
}
int main(){
	fast();
	int t = 1;
	while(cin >> n&&n){
		if (t > 1)
			cout << endl;
		init(n);
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			ind[s] = i;
			arr[i] = s;
		}
		cin >> m; 
		for (int i = 0; i < m; i++){
			string u, v; cin >> u >> v;
			graph[ind[u]].push_back(ind[v]);
			graph[ind[v]].push_back(ind[u]);

		}
		set<string>ans;
		findArtPointsAndBridges();
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (artPoints[i]){
				ans.insert(arr[i]);
				cnt++;
			}
		}
		cout << "City map #" << t++ << ": " << cnt << " camera(s) found\n";
		for (auto x : ans)cout << x << endl;

	}
	return 0;
}
