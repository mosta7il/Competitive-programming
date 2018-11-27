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
int main(){
	fast();

	cin >> d >> k >> a >> b >> t;

	if (k >= d){
		cout << (d * a) << endl;
		
	}
	else if (t + k * a > b * k){
		cout << k * a + (d - k) * b << endl;
	}
	else{
		// drive last (d%k) KM
		ll dist = d;
		ll mn = a * dist + ((dist / k) - (dist %k == 0))*t;
		//Or walk
		dist -= (d%k);
		mn = min(mn, a * dist + ((dist / k) - (dist %k == 0))*t + (d%k) *b);
		cout << mn << endl;
	}
	return 0;
}
