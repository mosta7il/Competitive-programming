/*

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;
int m, d;
string a, b;
ll dp[2001][2001][2][2];


ll rec(int idx, int rem, bool oka, bool okb){
	if (idx == a.size()){
		return rem == 0;
	}

	ll &ret = dp[idx][rem][oka][okb];
	if (~ret)
		return ret;
	ret = 0;

	for (int i = 0; i < 10; i++){
		if (idx == 0 && i == 0)continue;
		if (idx % 2 && i != d)continue;
		if (idx % 2 == 0 && i == d)continue;
		if (!oka && i < (a[idx] - '0'))continue;
		if (!okb && i >(b[idx] - '0'))continue;

		ret += rec(idx + 1, (rem*10 + i) % m, 
			oka | (i>(a[idx] - '0')), okb | (i < (b[idx] - '0'))) % mod;
		ret %= mod;
	}
	return ret;
}
int main(){
	fast();
	memset(dp, -1, sizeof dp);
	cin >> m >> d;
	cin >> a >> b;

	cout << rec(0, 0, 0, 0) << endl;
	return 0;
}
