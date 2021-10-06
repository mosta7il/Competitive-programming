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
int coins[50], ncoins[50];
long long dp[1001];

int main() {
	fast();

	cin >> t;
	while (t--){
		cout << "Case " << ++cas << ": ";
		cin >> n >> k;

		for (int i = 0; i < n; i++)
			cin >> coins[i];
		for (int i = 0; i < n; i++)
			cin >> ncoins[i];
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int idx = 0; idx < n; idx++){
			for (int rem = coins[idx]; rem < min(k+1,(1+ncoins[idx]) * coins[idx]); rem++){
				dp[rem] += dp[rem - coins[idx]]%mod;
				dp[rem] %= mod;
			}
		}
		cout << dp[k]%mod << endl;

	}
	return 0;
}
