#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
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
long long dp[1005][1005], dp1[1005][1005], dp2[1005][1005], dp3[1005][1005];
int n, m;

int main() {
	fast();
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> dp[i][j];
			dp1[i][j] = dp2[i][j] = dp3[i][j] = dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] += max(dp[i][j - 1], dp[i - 1][j]);
		}
		for (int j = m; j >= 1; j--){
			dp2[i][j] += max(dp2[i][j + 1], dp2[i - 1][j]);
		}
	}
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= m; j++){
			dp1[i][j] += max(dp1[i][j - 1], dp1[i +1][j]);
		}
		for (int j = m; j >= 1; j--){
			dp3[i][j] += max(dp3[i][j + 1], dp3[i + 1][j]);
		}
	}
	long long res = -OO;
	for (int i = 2; i <n; i++){
		for (int j = 2; j < m; j++){
			res = max(res,  dp[i - 1][j] + dp3[i + 1][j] + 
							dp1[i][j - 1] + dp2[i][j + 1]);
			res = max(res,  dp[i][j - 1] + dp3[i][j + 1] +
					    	dp1[i + 1][j] + dp2[i - 1][j]);
		}
	}
	cout << res << endl;
	return 0;
}
