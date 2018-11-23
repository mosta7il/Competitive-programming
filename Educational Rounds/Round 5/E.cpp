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
const int MAX = 1 * 100 * 1000 + 5;
long long n, m;

long long fun(long long L, long long R){

	if ((L+R) % 2 == 0){
		return (((L + R) / 2) % mod * ((R - L + 1) % mod)) % mod;
	}
	else{
		return (((L + R) ) % mod * (((R - L + 1)/2) % mod)) % mod;
	}
}
int main(){
	fast();

	cin >> n >> m;
	long long ans = 0;
	if (m > n){
		ans += (m - n) % mod * (n%mod);
		ans %= mod;
		m = n;
	}
	ans += ((m%mod) * (n%mod)) % mod;
	ans %= mod;
	for (long long i = 1; i <= m; i++){
		long long x = n / (n / i);
		x = min(m, x);
		ans -= (fun(i, x) * ((n / i)%mod))%mod;
		ans %= mod;
		ans += mod; 
		ans %= mod;
		i = x;
	}
	cout << ans << endl;

	return 0;
}
