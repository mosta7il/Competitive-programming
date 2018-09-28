#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e17;
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
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 1000 * 1000  + 5;

int t, n;
long long mem[101][101][128];

long long rec(int idx, int rem, int xr){
	if (rem == 0)
		return (xr > 0);

	long long &ret = mem[idx][rem][xr];
	if (~ret)return ret;
	ret = 0;
	for (int i = 1; i <= rem; i++){
		ret += rec(idx + 1, rem - i, xr ^ i);
		ret %= mod;
	}
	return ret;
}
int main() {
	fast();
	cin >> t;
	memset(mem, -1, sizeof mem);
	while(t--){
		cin >> n;
		cout << rec(0, n, 0) << endl;
	}


	return  0;
}
