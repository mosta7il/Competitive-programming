#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h> 
using namespace std;

const long long OO = 1000;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);
#endif
	/*std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);*/
}
const int MAX = 2e5+1;
string s;
int n;
int mem[MAX][26];
int rec(int idx, int lst){
	if (idx == n){
		return 0;
	}
	int &ret = mem[idx][lst];
	if (ret != -1)
		return ret;
	ret = 1e9;
	for (int i = 0; i <= 25; i++){
		if (lst == i)
			continue;
		ret = min(ret , rec(idx + 1, i) + (i != s[idx] - 'a'));
	}
	return ret;
}
void build(int idx, int lst){
	if (idx == n){
		return ;
	}
	
	
	for (int i = 0; i <= 25; i++){
		if (lst == i)
			continue;
		if (rec(idx + 1, i) + (i != s[idx] - 'a') == mem[idx][lst]){
			cout << char(i + 'a');
			build(idx + 1, i);
			return;
		}
	}
}
int main(){
	fast();
	memset(mem, -1, sizeof mem);

	cin >> s;
	n = s.size();
	int ret = 1e9, reti = -1;
	for (int i = 0; i <= 25; i++){
		int res = rec(0, i);
		if (res < ret){
			ret = res;
			reti = i;
		}
	}
	build(0, reti);
	return 0;
}
