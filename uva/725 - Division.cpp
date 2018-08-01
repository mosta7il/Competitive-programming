#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
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
const long long MAX = 2 * 1000 + 1;
int n;

int main(){
	fast();
	int cnt = 0;
	while (cin >> n&&n){
		if (cnt)
			cout << endl;
		cnt++;
		bool f = 0;
		for (int i = 1000; i <= 99999 / n; i++){
			int b = i * n;
			int mask = (i < 10000);
			int tmp = i; while (tmp){ mask |= (1<<(tmp % 10)); tmp /= 10; }
			tmp = b; while (tmp){ mask |= (1 << (tmp % 10)); tmp /= 10; }
			if (mask == (1 << 10) - 1){
				f = 1;
				cout << b << " / " << ((i < 10000) ? "0" : "") << i <<" = "<<n<< endl;
			}
		}

		if (!f){
			cout << "There are no solutions for " << n << ".\n";
		}
	}
	return 0;
};
