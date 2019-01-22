/*
    Sum of all choclate Z 
     Z = x + (x / p) + (x / p^2) + .... + (x / p^n-1)
     Z =  x ( 1 + (1 / p) + (1 / p^2) + .... + (1 / p^n-1)
     - We can easily compute the sum of the geometric Series.
     - X should be minimum and divisable by all p , p^2 , ... ,and p^n-1
	then X = p^n-1.
 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define EPS 1e-12
#define MLOG 20
#define MAX  3 * 100  * 1000+5
const int mod = 1e9+7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

// calculate (a power b) in O ( Log ( b ) )
long long fast_power(long long a, long long b){
	if (!b)return 1;
	if (b == 1)return a%mod;

	long long ret = fast_power(a, b / 2) % mod;
	return (ret * ret %mod * fast_power(a, b % 2) % mod);
}

// return summation from Index 0 to N
long long sum_geoSeries(long long start, long long r, long long n){

	// ( 1 - ( r^(n+1) ) ) / ( 1 - r )

	// inv of ( 1-r )
	if (r == 1)
		return (n + 1) % mod * start%mod;
	long long inv = fast_power(1 - r, mod - 2);
	inv += mod; inv %= mod;
	long long ret = 1 - fast_power(r, n + 1);
	ret %= mod; ret += mod; ret %= mod;
	return (start * ret%mod * inv%mod);

}
int t;

ll n, p;

int main(){
	fast();

	cin >> t;
	while (t--){
		cin >> n >> p;

		ll R = fast_power(p, mod - 2);
		ll s = sum_geoSeries(1, R, n - 1);
		ll x = fast_power(p, n - 1);

		cout << s * x %mod << " " << x << endl;
	}
	return 0;
} 
