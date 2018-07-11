#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 200 * 1000  + 1;

int t, n, m;

long long mem[11][(1 << 10) + 1][101][2];
long long rec(int lst, int mask , int cnt ,bool ok){

	if (cnt < 0)
		return 0;
	if (mask == (1 << n) - 1 && cnt == 0)
		return 1;

	long long &ret = mem[lst][mask][cnt][ok];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int idx = 0; idx < n; idx++){
		if (!ok && idx > 0)
			ret += (rec(idx, mask | (1 << idx), cnt - 1, 1) % mod);
		else if (abs(lst - idx) == 1)
			ret += (rec(idx, mask | (1 << idx), cnt - 1 ,1 )%mod);
	}
	return ret%mod;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> n >> m;
		memset(mem, -1, sizeof mem);
		long long res = 0;
		for (int i = n; i <= m; i++){
				res += rec(10, 0, i , 0)%mod;
		}

		cout << res%mod << endl;
	}

	return 0;
}
