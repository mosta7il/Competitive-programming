#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e9;
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

const long long MAX =  3 * 100 * 1000 + 5;
int m, d;
string a, b;
string s;
int dp[2002][2002][2][2];
int rec(int idx, int rem, bool flaga, bool flagb){
	if (idx == a.size()){
		return !rem;
	}

	int &ret = dp[idx][rem][flaga][flagb];
	if (~ret)return ret;
	ret = 0;
	for (int i = !idx; i < 10; i++){
		if (((idx % 2) && i != d) || ((idx % 2 == 0) && i == d))continue;
		if (flaga || (i >= a[idx] - '0')){
			if (flagb || (i <= b[idx] - '0')){
				ret += rec(idx + 1, (rem * 10 + i) % m, flaga | (i > a[idx] - '0'), flagb | (i < b[idx] - '0'));
				ret %= mod;
			}
		}
	}
	return ret%mod;
}
int main() {
	fast();

	cin >> m >> d;
	cin >> a >> b;
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0, 0, 0) << endl;
	return 0;
}
