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
int digits[10];
int dp[10][10];

int rec(int idx, int last){
	if (idx >= k){
		return 1;
	}
	int &ret = dp[idx][last];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++){
		if (!idx || abs(digits[i] - last) <= 2){
			ret += rec(idx + 1, digits[i]);
		}
	}
	return ret;

}
int main() {
	fast();
	cin >> t;
	while (t--){
		cout << "Case " << ++cas << ": ";
		cin >> n >> k;
		for (int i = 0; i<n; i++)
			cin >> digits[i];
		int ret = 0;
		memset(dp, -1, sizeof dp);
		ret += rec(0, 0);
		cout << ret << endl;
	}
	return 0;
}
