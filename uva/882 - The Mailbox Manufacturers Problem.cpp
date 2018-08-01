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
int t , n, m;
int mem[11][101][101];

int rec(int cnt, int l, int r){

	if (cnt == 1){
		return (r * (r + 1) / 2) - (l * (l - 1) / 2);
	}
	if (l > r)
		return 0;
	if (l == r){
		return l;
	}
	int &ret = mem[cnt][l][r];
	if (ret != -1)
		return ret;
	ret = OO;
	for (int idx = l; idx <= r; idx++){
		ret = min(ret, idx + max(rec(cnt - 1, l, idx -1), rec(cnt, idx + 1, r)));
	}
	return ret;
}
int main(){
	fast();
	memset(mem, -1, sizeof mem);
	cin >> t;
	while(t--){
		cin >> n >> m;
		cout << rec(n, 1, m) << endl;
	}
	return 0;
};
