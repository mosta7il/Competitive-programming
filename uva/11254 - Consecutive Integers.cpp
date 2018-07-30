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
const long long MAX = 20 *1000 * 1000 + 1;

long long n;

long long fun(long long i, long long j){
	long long sum = (j * (j + 1) / 2) - (i * (i-1) / 2);
	return sum;
}
int main(){
	fast();
	
	while (cin >> n && n >= 0){
		long long ans = -1, start = 0;
		for (long long w = 1; w <= 100000; w++){

			long long rem = n - (w  * (w - 1) / 2);
			if (rem >0&&rem % w == 0){
				ans = w;
				start = rem / w;
			}
		}
		
		cout << n << " = ";
		if(ans > 0)cout << start << " + ... + " << start + ans - 1 << endl;
		else cout << n << " + ... + " << n << endl;
	}
	return 0;
}
