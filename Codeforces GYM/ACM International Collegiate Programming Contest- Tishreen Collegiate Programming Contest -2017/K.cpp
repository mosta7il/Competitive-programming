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

int t;
string s;
long long dp[51][51];

long long rec(int i, int j){
	if (i >= j)
		return 1;
	
	long long &ret = dp[i][j];
	if (~ret)return ret;
	ret = 1;
	int cnt = 0;
	for (int L = i; L < j; L++){
		cnt += (s[L] - '0');
		int cntt = 0;
		for (int R = j; R >L; R--){
			cntt += (s[R] - '0');
			if (cnt == cntt){
				ret += rec(L + 1, R - 1)%mod;
			}
		}
	}
	return ret%mod;
}
int main() {
	fast();
	cin >> t;
	while (t--){
		memset(dp, -1, sizeof dp);
		cin >> s;
		cout << rec(0, s.size() - 1) %mod << "\n";
	}


	return  0;
}
