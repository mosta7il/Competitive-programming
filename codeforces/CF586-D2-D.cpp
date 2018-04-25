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
int t, n;

char g[3][101];

int starti, startj;
vector< pair<int, int> > a[3];
bool vis[301][3][101];
bool valid(int i, int j, int k){
	for (int it = 0; it < a[i].size(); it++){
		int l = a[i][it].first, r = a[i][it].second;
		if (l - (2 * k) <= j&& r - (2 * k) >= j)
			return 0;
	}
	return 1;
}
bool bfs(){
	queue< pair<int, pair<int, int> > >q;
	q.push({ 0, { starti, startj } });

	while (q.size()){
		pair<int, pair<int, int> > cur = q.front();
		q.pop();
		if (cur.second.second >=n)
			return 1;
		if (vis[cur.first][cur.second.first][cur.second.second])
			continue;
		vis[cur.first][cur.second.first][cur.second.second] = 1;

		
		pair<int, pair<int, int> > tmp = cur;
	
		if (valid(tmp.second.first, tmp.second.second+1, tmp.first + 1)
			&& valid(tmp.second.first, tmp.second.second + 1, tmp.first)){

			q.push({ tmp.first + 1, { tmp.second.first, tmp.second.second + 1 } });
		}

		if (tmp.second.first - 1 >= 0 
			&& valid(tmp.second.first , tmp.second.second + 1, tmp.first)
			&& valid(tmp.second.first -1 , tmp.second.second + 1, tmp.first)
			&& valid(tmp.second.first - 1, tmp.second.second+1, tmp.first + 1)){

			q.push({ tmp.first + 1, { tmp.second.first -1 , tmp.second.second + 1 } });
		}

		if (tmp.second.first + 1 < 3
			&&valid(tmp.second.first, tmp.second.second+1, tmp.first)
			&& valid(tmp.second.first+1, tmp.second.second + 1, tmp.first)
			&&valid(tmp.second.first + 1, tmp.second.second+1, tmp.first + 1)){
			q.push({ tmp.first + 1, { tmp.second.first +1, tmp.second.second + 1 } });
		}
		
	}
	return 0;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		int k;
		memset(vis, 0, sizeof vis);
		cin >> n>>k;
		a[0].clear(); a[1].clear(); a[2].clear();
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < n; j++){
				cin >> g[i][j];
				if (g[i][j] == 's')
					starti = i, startj = j;
			}
		}

		for (int i = 0; i < 3; i++){
			int cnt = 0;
			for (int j = 1; j < n; j++){
				if (g[i][j] != 's' && g[i][j] != '.'&&g[i][j] == g[i][j-1]){
					cnt++;
				}
				else{
					if (cnt){
						a[i].push_back({ j - cnt - 1, j - 1 });
					}
					cnt = 0;
				}
			}
			if (cnt){
				a[i].push_back({ n - cnt - 1, n-1 });
			}
		}

		if (bfs()){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
