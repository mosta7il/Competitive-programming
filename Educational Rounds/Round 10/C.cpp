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
const long long MAX = 10* 100 * 1000 + 5;
int n, m;
long long pwr(long long a, long long b){
	if (b == 0)return 1;
	if (b == 1)return a;

	long long t = pwr(a, b / 2);
	return t * t * pwr(a, b % 2);
}
vector<long long>v, t;
map<int, int>idx;
int main() {
	fast();
	cin >> n >> m;
	v.resize(n);
	t.resize(n + 1, -1);
	for (int i = 0; i < n; i++){
		cin >> v[i];
		idx[v[i]] = i;
	}
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		long long l = idx[x], r = idx[y];
		t[v[max(l, r)]] = max(t[v[max(l,r)]] , min(l, r));
	}
	long long l = 0;
	long long res = 0;
	for (int i = 1; i < n; i++){
		if (t[v[i]] == -1)continue;
		
		if (l <= t[v[i]]){
			//long long w = (t[v[i]] - l)
			res += (i-l) * (i-l +1)/2 - (i-t[v[i]])*( i - t[v[i]] - 1 )/2;
			l = t[v[i]]+1;
		}
	}
	res += (n - l)* (n-l+1)/2 ;
	cout << res << endl;

	return 0;
}
