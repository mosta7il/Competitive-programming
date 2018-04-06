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
	/*std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);*/
}

int n, m;

int out[1000 * 1000 + 1];
vector<int>g[1000 * 1000 + 1];
int main()
{
	fast();
	while (scanf("%d%d", &n, &m)&& n && m){
		for (int i = 1; i <= n; i++)
			g[i].clear();
		memset(out, 0, sizeof out);
		vector<int>ans;

		for (int i = 0; i < m; i++){
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v);
			out[v]++;
		}
		queue<int>q;
		for (int i = 1; i <= n;i++)
		if (out[i] == 0)
			q.push(i);
		while (q.size()){
			int cur = q.front();
			ans.push_back(cur);
			q.pop();

			for (auto e : g[cur]){
				out[e]--;
				if (out[e] == 0)
					q.push(e);
			}
		}

		if (ans.size() != n){
			printf("IMPOSSIBLE\n");
		}
		else{
			for (auto e : ans){
				printf("%d\n", e);
			}
		}
	}
	
	return 0;
}
