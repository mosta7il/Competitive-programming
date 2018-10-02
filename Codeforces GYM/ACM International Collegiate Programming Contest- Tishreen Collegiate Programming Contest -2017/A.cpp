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
long long n, x;
long long p[18];
int main() {
	fast();
	cin >> t;
	p[0] = 0; p[1] = 10;
	for (int i = 2; i < 18; i++){
		p[i] = 10 * p[i - 1];
	}
	while (t--){
		cin >> n >> x;
		long long cur = x;
		bool f = 1;
		while (n){
			int idx = upper_bound(p, p + 18, cur) - p;
			long long dif = p[idx] - cur;
			if (dif *idx <= n){
				n -= dif * idx;
				cur = p[idx];
			}
			else if (n%idx != 0){
				f = 0;
				break;
			}
			else if (n % idx == 0){
				cur += (n / idx) - 1;
				break;
			}
		}
		if(f)cout << cur - x + 1 << "\n";
		else cout << -1 << "\n";

	}


	return  0;
}
