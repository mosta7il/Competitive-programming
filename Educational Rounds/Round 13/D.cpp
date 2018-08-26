#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


const long long OO = 1e9;
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
const long long MAX =  1000 + 5;
long long A, B, n, x;

long long pwr(long long a, long long b){
	if (b == 0)return 1;
	if (b == 1)return a;

	long long ret = pwr(a, b / 2);
	return (ret%mod * ret%mod * pwr(a, b % 2)%mod)%mod;
}
int main() {
	fast();
	cin >> A >> B >> n >> x;
	if (A == 1){
		cout << (x%mod + ((B%mod) * (n%mod))) % mod;
	}
	else{
		long long ans = pwr(A, n);
		cout << ((ans%mod * x) % mod + (((B%mod * (1 - ans) % mod) % mod) * (pwr(1 - A, mod - 2) % mod) % mod)) % mod;
	}
	return 0;
}
