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
	//freopen("hunter.in", "r", stdin);
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 1000 * 100 + 1;

int t, n, m, k;
long long mem[31][31][51];

long long rec(int r, int c, int rem){

	if (rem == 0)
		return 0;
	if (rem == r * c)
		return 0;
	if (rem > r * c)
		return OO ;

	long long &ret = mem[r][c][rem];
	if (ret != -1)
		return ret;
	ret = OO ;
	for (int row = 1; row < r; row++){
		for (int idx = 0; idx <= rem; idx++){
			ret = min(ret, rec(row, c, idx) + rec(r - row, c, rem - idx) + (c * c));
		}
	}

	for (int col = 1; col < c; col++){
		for (int idx = 0; idx <= rem; idx++){
			ret = min(ret, rec(r, col, idx) + rec(r, c - col , rem - idx) + (r * r));
		}
	}
	return ret;
}
int main() {
	fast();
	memset(mem, -1, sizeof mem);
	cin >> t;
	while (t--){

		cin >> n >> m >> k;
		cout << rec(n, m, k) << endl;
	}

	return 0;
}
