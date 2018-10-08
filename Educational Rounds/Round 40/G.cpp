#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
const long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 5 * 100 * 1000 + 5;
int n, r;long long k;
long long a[MAX], cum[MAX];

bool fun(long long md){
	for (int i = 1; i <= n; i++)
		cum[i] = a[i];
	long  long cnt = 0;
	for (int i = 1; i <= n; i++){
		cum[i] += cum[i - 1];
		if (cum[i] < md){
			int L = i, R = min(n, i + r + r);
			long long dif = md - cum[i];
			if (dif > k){
				return 0;
			}
			if (cnt + dif > k){
				return 0;
			}
			cum[i] += dif;
			cum[R + 1] -= dif;
			cnt += dif;
		}	
	}
	return (cnt <= k);
}
int main() {
	fast(); 

	cin >> n >> r >> k;
	for (int i = 1; i <= n; ++i){
		int x; cin >> x;
		int L = max(1, i - r), R = min(n, i + r);
		a[L] += x; a[R + 1] -= x;
	}

	long long lo = 1, hi =  2 *1e18, ans = 0;
	while (lo <= hi){
		long long md = lo + hi >> 1;
		if (fun(md)){
			ans = md;
			lo = md + 1;
		}
		else hi = md - 1;
	}
	cout << ans << endl;
	return 0;
}
