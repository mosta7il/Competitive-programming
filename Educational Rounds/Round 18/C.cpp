#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


const long long OO = 1e8;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 100 * 1000 + 5;
string s;
int z;
int dp[MAX][3][2];

int rec(int idx, int rem , bool ok){
	if (idx == s.size()){
		return rem % 3 == 0&&ok?0:-OO;
	}

	int &ret = dp[idx][rem][ok];
	if (ret != -1)return ret;
	ret = -OO;
	if ((!ok&&s[idx] != '0') || (ok))
		ret = max(ret, rec(idx + 1, (rem + s[idx] - '0') % 3, 1) + 1);
	ret = max(ret, rec(idx + 1, rem, ok));
	return ret;
}
void build(int idx, int rem, bool ok){
	if (idx == s.size()){
		return ;
	}

	
	if ((!ok&&s[idx] != '0') || (ok)){
		if (rec(idx + 1, (rem + s[idx] - '0') % 3, 1) + 1 == dp[idx][rem][ok]){
			cout << s[idx];
			build(idx + 1, (rem + s[idx] - '0') % 3, 1);
			return;
		}
	}
	if (rec(idx + 1, rem, ok) == dp[idx][rem][ok]){
		build(idx + 1, rem, ok);
		return;
	}
	
}
int main() {
	fast();
	memset(dp, -1, sizeof dp);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		z += (s[i] == '0');
	}

	int ret = rec(0, 0, 0);
	if (ret <= 0){
		if (z)cout << 0 << "\n";
		else cout << -1 << "\n";
		return 0;
	}
	build(0, 0, 0);

	return 0;
}
