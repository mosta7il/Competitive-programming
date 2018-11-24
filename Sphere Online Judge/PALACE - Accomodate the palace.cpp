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
const int MAX = 10 * 100 * 1000 + 5;
const int mm = 98777;
int t, n;
ll pwr(int a, ll b){
	if (b == 0)return 1;
	if (b == 1)return a;
	ll t = pwr(a, b / 2);
	return ((t%mm) * (t%mm) * pwr(a, b % 2)) % mm;
}
int main(){
	fast();
	cin >> t;

	while (t--){
		cin >> n;
		cout << pwr(2, 1ll * (n - 1) * (n - 1)) << endl;
	}
	return 0;
}
