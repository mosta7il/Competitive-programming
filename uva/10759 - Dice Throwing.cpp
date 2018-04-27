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
int n, x;
long long mem[25][6 * 24 + 1];

long long rec(int idx, int sum){

	if (idx == n){
		return sum >= x;
	}
	long long &ret = mem[idx][sum];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= 6; i++)
		ret +=rec(idx + 1, sum + i);
	return ret;
}
long long pwr(long long a, long long b){
	if (b == 0)
		return 1;
	if (b == 1)
		return a;

	long long tt = pwr(a, b / 2);
	return tt * tt * pwr(a, b % 2);
}
long long gcd(long long a, long long b) {
	while (b){ long long r = a % b; a = b; b = r; }
	return a;
}
int main() {
	fast();
	
	while (cin >> n >> x&&(n)){
		memset(mem, -1, sizeof mem);
		if (n * 6 < x){
			cout << 0 << endl;
			continue;
		}
		long long a = rec(0, 0);
		long long b = pwr(6, n);
		long long g = gcd(a, b);

		if (a == b){
			cout << 1 << endl;
		}
		else if (a == 0){
			cout << 0 << endl;
		}
		else {
			cout << a / g << "/" << b / g << endl;
		}
	}
	return 0;
}
