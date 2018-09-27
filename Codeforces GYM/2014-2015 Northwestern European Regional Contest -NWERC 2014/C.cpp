#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-11);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e9;
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
const long long MAX = 2  * 1000 + 5;

long long mem[MAX][21];
int n, d;
long long a[MAX];
long long round_number(long long s){

	int m = s % 10;
	s -= m;
	if (m >= 5)
		s += 10;
	return s;
}

long long rec(int idx, int k){
	if (idx == n+1){
		return 0;
	}
	long long &ret = mem[idx][k];
	if (~ret){
		return ret;
	}
	if (k == 1){
		return ret = round_number(a[n] - a[idx-1]);
	}
	ret = OO;
	for (int i = idx; i <= n; i++){
		ret = min(ret , rec(i + 1, k - 1) + round_number(a[i] - a[idx-1]));
	}
	return ret;
}
int main() {
	fast();
	memset(mem, -1, sizeof mem);
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	cout << rec(1, d+1) << "\n";

	return 0;
}
