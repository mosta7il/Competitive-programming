#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

const long long OO = 1e9;
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
	//freopen("hunter.in", "r", stdin);
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 1000 * 100 + 1;
int n;
vector< vector< int> > g;
vector<long long> color, ans;


void DFS(int src, int par , map<int , long long > &mp){

	for (auto e : g[src]){
		if (e != par){
			map<int, long long > tmp;
			DFS(e, src , tmp);

			if (tmp.size() > mp.size())tmp.swap(mp);

			for (auto w : tmp){
				if (w.first > n)continue;
				mp[w.first] += w.second;

				if (mp[w.first] > mp[n + 1]){
					mp[n + 1] = mp[w.first];
					mp[n + 2] = w.first;
				}
				else if (mp[w.first] == mp[n + 1]){
					mp[n + 2] += w.first;
				}
			}
		}
	}
	mp[color[src]]++;
	if (mp[color[src]] > mp[n + 1]){
		mp[n + 1] = mp[color[src]];
		mp[n + 2] = color[src];
	}
	else if (mp[color[src]] == mp[n + 1]){
		mp[n + 2] += color[src] ;
	}
	ans[src] = mp[n + 2];
}
int main() {
	fast();
	cin >> n; g.resize(n);
	color.resize(n); ans.resize(n); 
	for (int i = 0; i < n; i++){
		cin >> color[i];
	}
	for (int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	map<int, long long> MP;
	DFS(0, -1, MP);
	for (auto e : ans)
		cout << e << " ";
	cout << endl;
	return 0;
}
