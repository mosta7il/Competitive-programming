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
int n, k ,t;
long long mem[(1 << 20)][100];
long long rec(int mask , int ww){
	if (ww > k)
		return 0;
	if (mask == (1 << n+1) - 2){
		return (ww == k);
	}
	long long &ret = mem[mask][ww];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= n; i++){
		if (!(mask &(1 << i))){

			int w = 0;
			for (int j = i+1; j <= n; j++){
				w += ((mask & (1 << j))?1:0);
			}
			ret += rec(mask | (1 << i) ,ww+w);

		}
	}
	return ret;
}
int main(){
	fast();
	
	cin >> t;
	while (t--){
		memset(mem, -1, sizeof mem);
		cin >> n >> k;
		cout << rec(0, 0) << endl;
	}
	return 0;
}
