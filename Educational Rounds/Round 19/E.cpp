#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e10;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const long long MAX =  100 * 1000 + 5;
int n, q;
int a[MAX], ans[MAX], vis[MAX];
vector< pair<int, int> >qu[MAX];
int ret[MAX];
int K, IDX;

int rec(int p){
	if (p > n)
		return 0;

	if (vis[p] == IDX)
		return ans[p];
	vis[p] = IDX;
	return ans[p] = 1 + rec(p + a[p] + K);
}
int main() {
	fast();

	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		int p, k;
		cin >> p >> k;
		qu[k].push_back({ p, i });
	}
	
	for (int i = 1; i <= n; i++){
		if (qu[i].size() == 0)
			continue;
		IDX++;
		K = i;
		while (qu[i].size()){
			ret[qu[i].back().second] = rec(qu[i].back().first);
			qu[i].pop_back();
		}
	}

	for (int i = 0; i < q; i++){
		cout << ret[i] << "\n";
	}
	return 0;
}
