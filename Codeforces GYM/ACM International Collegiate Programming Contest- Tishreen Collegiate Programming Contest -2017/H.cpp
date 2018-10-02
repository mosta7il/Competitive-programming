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

const long long MAX =  1000 + 5;

int t, n, k;
vector < vector< int > > v;
long long dp[MAX][2 * MAX];
long long rec(int idx, int rem){
	if (rem < 0)
		return OO;
	if (idx == n){
		if (rem == 0)return 0;
		return OO;
	}
	long long &ret = dp[idx][rem];
	if (~ret)
		return ret;
	ret = rec(idx+1 , rem);
	int sum = 0;
	for (int i = 0; i < 2; i++){
		sum += v[idx][i];
		ret = min(ret, sum + rec(idx + 1, rem - i - 1));
	}
	return ret;
}

int main() {
	fast();
	cin >> t;
	while (t--){
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 3; j++){
				int x; cin >> x;
				v[i].push_back(x);
			}
			sort(v[i].begin(), v[i].end());
		}
		cout << rec(0, k) << "\n";

	}


	return  0;
}
