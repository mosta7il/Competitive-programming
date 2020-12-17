#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e13
#define EPS 1e-10
#define MLOG 20
#define MAX 4* 1000 * 100 +2
const int mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int t, n, cur, all;
int a[100], dp[100][1000 * 100 + 1];

bool rec(int idx, int rem){
	if (idx == n)
		return (rem == 0);

	int &ret = dp[idx][rem];
	if (~ret)
		return ret;
	ret = 0;
	if (a[idx] > rem)
		return ret = rec(idx + 1, rem);

	ret = rec(idx + 1, rem - a[idx]) 
		||rec(idx + 1, rem);

	return ret;
}
int main() {
	fast();

	cin >> t;
	cur = 1;
	while (t--){
		memset(dp, -1, sizeof dp);
		all = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i],all += a[i];

		ll ans = 0;

		for (int i = 1; i <= all; i++){
			ans += (rec(0, i) ? i:0);
		}
		cout << ans << endl;
	}

	return 0;
}
