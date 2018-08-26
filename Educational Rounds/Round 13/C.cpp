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
long long n, a, b, p, q;

long long gcd(long long a, long long b){
	while (b){ long long r = a % b; a = b; b = r; }
	return a;
}
long long lcm(long long a, long long b){
	return a * b / gcd(a, b);
}
int main() {
	fast();
	cin >> n >> a >> b >> p >> q;
	long long ta = n / a,
		tb = n / b;
	long long tab = n / lcm(a, b);
	ta -= tab;
	tb -= tab;

	cout << (ta * p) + (tb * q) + (tab * max(p, q)) << endl;
	return 0;
}
