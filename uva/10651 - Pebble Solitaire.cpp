#define _CRT_SECURE_NO_WARNINGS
// Do not work at uva or spoj..
#include<bits\stdc++.h> 
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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 150+1;
int n;
int mem[(1 << 20)];
int rec(int mask){
	
	int &ret = mem[mask];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 10; i++){
		if ((mask & (1 << i) )&& (mask & (1 << i + 1)) && !(mask&(1 << i + 2)) ){
			int tmp = mask;
			tmp &= ~(1 << i);
			tmp &= ~(1 << i + 1);
			tmp |= (1 << i + 2);
			ret = max(ret, rec(tmp) + 1);
		}
		else if (!(mask & (1 << i)) && (mask & (1 << i + 1)) && (mask&(1 << i +2))){
			int tmp = mask;
			tmp |= (1 << i);
			tmp &= ~(1 << i + 1);
			tmp &= ~(1 << i + 2);
			ret = max(ret, rec(tmp) + 1);
		}
	}
	return ret;
}
int main(){
	fast();
	cin >> n;
	string s;
	while (n--){
		memset(mem, -1, sizeof mem);
		int m = 0, cnt = 0;
		cin >> s;
		for (int i = 0; i < s.size();i++){
			if (s[i] == 'o'){
				m = m | (1 << i); cnt++;
			}
		}
		cout << cnt - rec(m) << endl;
		
	}
	return 0;
}
