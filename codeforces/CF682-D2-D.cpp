#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
using namespace std;

const long long OO = 1e6;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m, k;
string s, t;
long long mem[1001][1001][11][2];
long long rec(int i, int j, int cnt, int lst){
	if (cnt < 0)
		return-OO;
	if (i ==n|| j == m){
		if (cnt == 0){
			return 0;
		}
		return -OO;
	}
	long long &ret = mem[i][j][cnt][lst];
	if (ret != -1)
		return ret;

	ret = max(ret, rec(i + 1, j, cnt, 0));
	ret = max(ret, rec(i, j + 1, cnt, 0));
	if (s[i] == t[j]){
		ret = max(ret, rec(i + 1, j + 1, cnt - 1, 1) + 1);
		if(lst)ret = max(ret, rec(i + 1, j + 1, cnt , 1) + 1);
	}
	return ret;
}
int main(){
	fast();
	memset(mem, -1, sizeof mem);
	cin >> n >> m >> k;
	cin >> s >> t;
	long long res = rec(0, 0,k, 0);
	cout << max(res, 0ll) << endl;
	return 0;
}
