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
const long long MAX = 10000 + 1;

int dfs_num[MAX], dfs_low[MAX], parent[MAX], artPoints[MAX];
bool visited[MAX];

vector< vector<int> > graph;
int n, m, counter, root, rootChildren;


void init(int n)
{
	counter = 0;
	graph.clear();
	graph.resize(n);

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
			artPoints[u]++;

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
			artPoints[i] = 0;
	}
}

struct node{
	int size, num;

	node(int s, int i){
		size = s;
		num = i;
	}
	bool operator < (const node & e)const{
		if (size < e.size)
			return 1;
		if (size == e.size && num > e.num)
			return 1;
		return 0;
	}
};
int main(){
	fast();
	while (cin >> n >> m&&n){

		init(n);
		int u, v;
		while (cin >> u >> v && u!=-1){
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		findArtPointsAndBridges();

		priority_queue <node> q;
		
		if(artPoints[0])
			artPoints[0]--;
		for (int i = 0; i < n; i++){
			q.push(node(artPoints[i] + 1 , i));
		}
		while (m--){
			cout << q.top().num << " " << q.top().size << endl;
			q.pop();
		}
		cout << endl;
	}
	return 0;
}
