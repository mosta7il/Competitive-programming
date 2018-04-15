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
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 2000+1;
int n, m, k;

long long pwr(int a, int b){
	if (b == 0)return 1;
	if (b == 1)return a;

	long long ret = pwr(a, b / 2);
	return (ret%mod * ret%mod * pwr(a, b % 2)%mod)%mod;
}
int main(){
	fast();
	cin >> n >> m >> k;
	if (k == 1){
		cout << pwr(m, n) << endl;
	}
	else if (n == k){
		cout << pwr(m, (k + 1) / 2) << endl;
	}else if (n > k){
		if (k % 2){
			cout << m*m << endl;
		}
		else{
			cout << m << endl;
		}
	}
	else{
		cout << pwr(m, n) << endl;
	}
	return 0;
}
