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
const int MAX = 10 * 100 * 1000 + 5;
ll a, b;

ll pwr(int a, ll b){
	if (!b)return 1;
	if (b == 1)return a;

	ll t = pwr(a, b / 2);
	return (((t%mod) * (t%mod)) % mod *pwr(a, b % 2)) % mod;
}
int main(){
	fast();

	cin >> a >> b;
	ll inv = pwr(2, mod - 2);
	ll sumFromOneTo_B_minusOne = (((b %mod) * ((b - 1) % mod)) % mod)*inv%mod;
	ll sumFromOneToA = (((a %mod) * ((a + 1) % mod)) % mod)*inv%mod;

	cout << sumFromOneTo_B_minusOne *(((sumFromOneToA * b %mod) + a) % mod) % mod << endl;
	return 0;
}
