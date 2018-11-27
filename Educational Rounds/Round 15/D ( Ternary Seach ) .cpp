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
const ll   OO = 1e6;
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
const int MAX = 2 * 100 * 1000 + 5;
ll d, k, a, b, t;

ll fun(ll repair){
	ll dist = (repair * k)+k;
	dist = min(dist, d);
	return (dist * a + repair * t + (d - dist) * b);
}
int main(){
	fast();

	cin >> d >> k >> a >> b >> t;

	ll l = 0, r = d, m1, m2, r1, r2, res = 2e18;
	while (l <= r) {
		m1 = (l + l + r) / 3;
		m2 = (l + r + r) / 3;
		r1 = fun(m1);
		r2 = fun(m2);
		res = min(res, min(r1, r2));
		if (r1 < r2) r = m2 - 1;
		else l = m1 + 1;
	}
	cout << res << endl;
	return 0;
}
