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
int n, cnt;
int a[100 * 1000 + 1];
int main(){
	fast();
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		int lst = i - y; cnt = 0;
		for (int j = 1; j*j <= x; j++){
			if (x%j == 0){
				cnt += (a[j] < lst);
				a[j] = i;
				if (x / j != j){
					cnt += (a[x/j] < lst);
					a[x/j] = i;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
