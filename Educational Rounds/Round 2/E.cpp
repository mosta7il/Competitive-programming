/*
  
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 1 * 100 * 1000 + 5;
int col[MAX];
ll ans[MAX];
int n;
vector< int > g[MAX];

void lazy(map<int, ll>&all,  int key){
	if (all[key] > all[MAX]){
		all[MAX] = all[key];
		all[MAX + 1] = key;
	}
	else if (all[key] == all[MAX]){
		all[MAX + 1] += key;
	}
}
void DFS(int src, int par, map< int, ll >&all){

	for (auto &e : g[src]){

		if (par != e){
			map<int, ll>mp;
			DFS(e, src, mp);
			if (all.size() < mp.size())
				swap(all, mp);
			for (auto &w : mp){
				if(w.first < MAX){
					all[w.first] += w.second;
					lazy(all, w.first);
				}
			}
		}
	}
	all[col[src]]++;
	lazy(all, col[src]);
	ans[src] = all[MAX + 1];
}
int main(){
	fast();

	cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		col[i] = x;
	}

	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	map<int, ll>mp;
	DFS(1, -1, mp);

	for (int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
