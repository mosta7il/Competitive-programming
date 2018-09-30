#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e17;
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
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 100 * 1000 + 5;
int n;
int t;
int p[MAX];
long long fastPower(int a, int b){
	if (b == 1)return a;
	if (b == 0)return 1;

	long long ret = fastPower(a, b / 2) % mod;
	return ((ret  * ret) % mod * fastPower(a, b % 2)) % mod;
}
int a[MAX];
int main() {
	fast();
	cin >> t;
	for (int i = 0; i < MAX; i++){
		p[i] = fastPower(i, mod - 2);
	}
	while (t--){
		int n;
		cin >> n;
		long long mul = 1;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mul *= a[i];
			mul %= mod;
		}
		long long ans = 0;
		for (int i = 0; i < n; i++){
			ans += ((((mul % mod)* (p[a[i]])) % mod) * (a[i] - 1) %mod);
			ans %= mod;
		}
		cout << ans << "\n";
	}
	return  0;
}
