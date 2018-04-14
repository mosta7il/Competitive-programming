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
const int MAX = 150+1;
int t, n , k;
long long a[165];
long long mem[65][102][65+65];
long long rec(int idx, int rem, int dif){
	if (idx == n + 1){
		return (rem == 0 && dif == 65);
	}
	long long &ret = mem[idx][rem][dif];
	if (ret != -1)
		return ret;
	ret = 0;
	if (idx == n)
		ret += rec(idx + 1, (k > 0) ? (rem + a[idx - 1]) % k : 0, dif + 1);
	else {
		ret += rec(idx + 1,(k > 0)? (rem + a[idx-1]) % k:0, dif + 1);
		ret += rec(idx + 1, rem, dif - 1);
	}
	return ret;
}
int main(){
	fast();
	scanf("%d", &t);
	int id = 0;
	while (t--){
		printf("Case %d: ", ++id);

		memset(mem, -1, sizeof mem);
		scanf("%d%d", &n, &k);
		if (k > 0){
			a[0] = 1 % k;
			for (int i = 1; i <= 64; i++){
				a[i] = (a[i - 1] * 2) % k;
				a[i] %= k;
			}
			printf("%lld\n", rec(1, 0, 65));
		}
		else {
			printf("0\n");
		}
		

	}
	return 0;
}
