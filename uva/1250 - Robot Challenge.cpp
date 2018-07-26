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
const long long MAX = 200 * 1000 + 1;
int n;
int X[1002], Y[1002], p[1002];;
bool vis[1002][1002];
double mem[1002][1002];
double dist(int i, int j){
	return hypot(X[i] - X[j], Y[i] - Y[j]);
}
double rec(int idx , int lst){
	if (idx == n + 1){
		return dist(lst, n + 1)+1.0;
	}
	if (vis[idx][lst])
		return mem[idx][lst];
	vis[idx][lst] = 1;
	double &ret = mem[idx][lst];
	ret = 1e6;

	ret = min(ret, rec(idx + 1, idx) + dist(idx, lst)+1.0);
	ret = min(ret, rec(idx + 1, lst) + p[idx]);
	return ret;
}
int main(){
	fast();
	
	while (cin >>n && n){
		memset(vis, 0, sizeof vis);

		for (int i = 1; i <= n; i++){
			cin >> X[i] >> Y[i] >> p[i];
		}
		X[n + 1] = 100, Y[n + 1] = 100;

		cout <<fixed<<setprecision(3)<< rec(1, 0) << endl;
	}
	return 0;
}
