#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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
string s;
int k;
int cntChange[501][501];
int fun(int l, int r){
	int cnt = 0;
	while (l <= r){
		if (s[l] != s[r]){
			cnt++;
		}
		l++; r--;
	}
	return cnt;
}
void change(int l, int r){

	while (l <= r){
		if (s[l] != s[r]){
			s[l] = s[r];
		}
		l++; r--;
	}
}
int tt;
int mem[501][501];
int rec(int last, int cnt){
	if (cnt > k)
		return OO;
	if (last == s.size()){
		return 0;
	}
	int &ret = mem[last][cnt];
	if (ret != -1)
		return ret;
	ret = OO;
	for (int idx = last; idx<s.size(); idx++){
		ret = min(ret, rec(idx+1, cnt + 1) + cntChange[last][idx]);
	}
	return  ret;
}
string ans;
void build(int last, int cnt){
	if (cnt > k)
		return ;
	if (last == s.size()){
		return;
	}
	for (int idx = last ; idx<s.size(); idx++){
		if (rec(idx + 1, cnt + 1) + cntChange[last][idx] == mem[last][cnt]){
			change(last , idx);
			ans += s.substr(last, (idx - last + 1)) + "+";
			build(idx+1, cnt + 1);
			return;
		}
	}
}
int main(){
	fast();
	memset(mem, -1, sizeof mem);

	cin >> s;
	cin >> k;

	for (int i = 0; i < s.size(); i++){
		for (int j = i; j < s.size(); j++){
			cntChange[i][j] = fun(i, j);
		}
	}
	cout << rec(0, 0) << endl;
	build(0, 0);
	ans.pop_back();
	cout << ans << endl;
	return 0;
}
