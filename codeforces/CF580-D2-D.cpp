#define _CRT_SECURE_NO_WARNINGS
// Do not work at uva or spoj..
#include<bits\stdc++.h> 
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
const int MAX = 150+1;
int n, m, k;
int a[20], cost[20][20];
long long mem[(1 << 20)][20];
int get(int mask){
	int cnt = 0;
	for (int i = 0; i <=n; i++){
		if (mask & (1 << i)){
			cnt++;
		}
	}
	return cnt;
}
long long rec(int mask, int lst){

	if (get(mask) == m){
		return 0;
	}
	long long &ret = mem[mask][lst];
	if (ret != -1)
		return ret;

	for (int i = 1; i <= n; i++){
		if (!(mask&(1 << i))){
			ret = max(ret, rec(mask|(1 << i), i) + a[i] + cost[lst][i]);
		}
	}
	return ret;
}
int main(){
	fast();
	memset(mem, -1, sizeof mem);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < k; i++){
		int u, v, w;
		cin >> u >> v >> w;
		cost[u][v] = w;
	}

	cout << rec(0, 0) << endl;
	return 0;
}
