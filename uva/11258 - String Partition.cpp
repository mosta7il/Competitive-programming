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
string s;
long long sum(int i, int j){
	long long res = 0, pwr = 1;
	for (int idx = j ; idx >= i; idx--){
		res += (s[idx] - '0')*pwr;
		pwr *= 10;
		if (res > MAX)
			return -MAX;
	}
	return res;
}
long long mem[201];
long long rec(int idx){

	if (idx == s.size()){
		return 0;
	}
	long long &ret = mem[idx];
	if (ret != -1)
		return ret;
	ret = -MAX;
	if (s[idx] == '0')
		return ret = rec(idx + 1);
	for (int end = idx; end < s.size(); end++){
		ret = max(ret , rec(end + 1) + sum(idx, end));
	}
	return ret;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> s;
		memset(mem, -1, sizeof mem);
		cout << rec(0) << endl;
	}
	return 0;
}
