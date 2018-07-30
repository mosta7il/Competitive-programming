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

bool fun(long long n, long long d){
	int cnt = 0;
	n--;
	while (n >= 0 && n % d == 0&&cnt<d){
		cnt++;
		long long rem = n -  n / d;
		n = rem ;
		if (cnt < d)
			n--;
	}

	if (n>= 0 && n%d == 0 && cnt == d)
		return 1;
	return 0;
}
int main(){
	fast();
	
	while (cin >> n && n >= 0){
		cout << n << " coconuts, ";
		if (n < 3){
			cout << "no solution\n";
			continue;
		}
		if (n == 3){
			cout << "2 people and 1 monkey\n";
			continue;
		}
		long long mx = -1;
		for (long long i = 2; i*i <= (n-1); i++){
			if ((n - 1) % i == 0){
				if (fun(n, i))
					mx = max(mx, i);
				if (fun(n, (n - 1) / i))
					mx = max(mx, (n - 1) / i);
			}
		}
		if (mx == -1)
			cout << "no solution\n";
		else cout << mx << " people and 1 monkey\n";
	}
	return 0;
}
