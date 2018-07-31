#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
const long long MAX = 2 * 1000 + 1;
int X[11] , Y[11];
int n;
long long mem[11][11];
long long rec(int i, int j){

	if (i == j){
		return 0;
	}
	if (i + 1 == j){
		return  X[i] * Y[i] * Y[j];
	}
	long long &ret = mem[i][j];
	if (ret != -1)
		return ret;

	ret = 1e9;
	for (int idx = i; idx < j; idx++){
		auto  w = rec(i, idx);
		auto ww = rec(idx + 1, j);
		ret = min(ret, w + ww + (X[i] * Y[idx] * Y[j]));
	}

	return ret;
}

void build(int i, int j){
	if (i == j){
		cout << "A" << i + 1;
		return;
	}
	if (i + 1 == j){
		cout << "(A" << j << " x " << "A" << j + 1 << ")";
		return;
	}
	for (int idx = i; idx < j; idx++){
		auto  w = rec(i, idx);
		auto ww = rec(idx + 1, j);
		if ((w + ww + (X[i] * Y[idx] * Y[j])) == mem[i][j]){
			cout << "(";
			build(i, idx);
			cout << " x ";
			build(idx + 1, j);
			cout << ")";
			return;
		}
	}
}
int main(){
	fast();
	int cnt = 1;
	while (cin >> n&&n){
		memset(mem, -1, sizeof mem);

		for (int i = 0; i < n; i++){
			cin>>X[i] >> Y[i];
		}
		rec(0, n - 1);
		cout << "Case " << cnt++ << ": ";
		build(0, n - 1);
		cout << endl;
	}
	return 0;
}
