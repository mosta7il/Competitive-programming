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
#define MAX 2* 1000 * 100 +2
const int mod = 1e8 + 7;
const int N = 5 * 100 * 100;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int t, n, k, cas;
int cost[14][14];
int dp[(1 << 14)];

int main() {
	fast();
	cin >> t;
	while (t--){
		cout << "Case " << ++cas << ": ";
		cin >> n;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++)
				cin >> cost[i][j];
		}
		fill(dp, dp + (1 << n), 1e9);
		dp[0] = 0;
		for (int mask = 0; mask < (1 << n); mask++){
			for (int idx = 0; idx < n; idx++){
				if ((1 << idx) & mask)continue;
				int plus = cost[idx][idx];
				for (int d = 0; d < n; d++){
					if ((1 << d) & mask){
						plus += cost[idx][d];
					}
				}
				dp[mask | (1 << idx)] = min(dp[mask | (1 << idx)], dp[mask] + plus);
			}
		}
		cout << dp[(1<<n) - 1] << endl;
	}
	return 0;
}
