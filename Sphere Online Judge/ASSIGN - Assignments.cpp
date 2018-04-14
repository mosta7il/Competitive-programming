#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h> 
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
	/*std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);*/
}
const int MAX = 150+1;
int n, t;
int ass[21][21];
long long mem[21][(1 << 21)];
long long rec(int idx ,int mask){
	if (idx == n + 1){
		return 1;
	}

	long long &ret = mem[idx][mask];
	if (ret != -1)
		return ret;
	ret = 0;
	bool f = 0;
	for (int i = 1; i <= n; i++){
		if (ass[idx][i] && !(mask & (1 << i))){
			f = 1;
			ret += rec(idx + 1, mask | (1 << i));
		}
	}
	if (!f)
		return 0;
	return ret;
}
int main(){
	fast();
	scanf("%d", &t);
	while (t--){
		memset(mem, -1, sizeof mem);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%d", &ass[i][j]);
			}
		}
		cout << rec(1, 0) << endl;

	}
	
	return 0;
}
