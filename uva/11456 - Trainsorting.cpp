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
const long long MAX = 2147483647ll;
int t;
int n;
int a[2002];
int memup[2002], memdown[2002];
int up(int lst){
	if (lst == n){
		return 0;
	}
	int &ret = memup[lst];
	if(ret!=-1)
		return ret;
	ret = 0;
	for (int idx = lst + 1; idx<n; idx++){
		if (a[idx] > a[lst]){
			ret = max(ret , up(idx) + 1);
		}
	}
	return ret;
}
int down(int lst){
	if (lst == n){
		return 0;
	}
	int &ret = memdown[lst];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int idx = lst + 1; idx<n; idx++){
		if (a[idx] < a[lst]){
			ret = max(ret, down(idx) + 1);
		}
	}
	return ret;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> n;
		memset(memup, -1, sizeof memup);
		memset(memdown, -1, sizeof memdown);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int best = 0;
		for (int i = 0; i < n; i++){
			best = max(best, up(i) + down(i) + 1);
		}
		cout << best << endl;
	}
	return 0;
}
