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
const long long MAX = 20 * 1000 + 1;
int n;
int a[MAX][2];
long long mem[MAX][2];
long long rec(int idx, int lst){
	if (idx == n - 1){
		if (a[idx - 1][lst] <= a[idx][0]){
			return  (a[idx][1] - a[idx - 1][lst])+(n - a[idx][1]);
		}
		else if (a[idx - 1][lst] >= a[idx][1]){
			return (a[idx - 1][lst] - a[idx][0]) + (n - a[idx][0]);
		}
		else{
			return min(2 * (a[idx][1] - a[idx - 1][lst]) + (a[idx - 1][lst] - a[idx][0]) + (n - a[idx][0]),
			2 * (a[idx - 1][lst] - a[idx][0]) + (a[idx][1] - a[idx - 1][lst])+ (n - a[idx][1]) );
		}
	}

	long long &ret = mem[idx][lst];
	if (ret != -1)
		return ret;

	ret = 1e9;
	if (idx == 0){
		ret = rec(idx + 1, 1) + a[0][1];
	}
	else{
		if (a[idx - 1][lst] <= a[idx][0]){
			ret = min(ret, rec(idx + 1, 1) + (a[idx][1] - a[idx - 1][lst] + 1));
		}
		else if (a[idx - 1][lst] >= a[idx][1]){
			ret = min(ret, rec(idx + 1, 0) + (a[idx - 1][lst] - a[idx][0] + 1));
		}
		else{
			ret = min(ret, rec(idx + 1, 0) + 2 * (a[idx][1] - a[idx - 1][lst]) + (a[idx - 1][lst] - a[idx][0]) + 1);
			ret = min(ret, rec(idx + 1, 1) + 2 * (a[idx - 1][lst] - a[idx][0]) + (a[idx][1] - a[idx - 1][lst]) + 1);
		}
	}
		return ret;
}
int main(){
	fast();
	while (cin >> n&&n){
		for (int i = 0; i < n; i++)
			cin >> a[i][0] >> a[i][1];
		memset(mem, -1, sizeof mem);
		if (1 == n){
			cout << n - 1 << endl;
			continue;
		}
		cout << rec(0, 0) << endl;
	}
	return 0;
}
