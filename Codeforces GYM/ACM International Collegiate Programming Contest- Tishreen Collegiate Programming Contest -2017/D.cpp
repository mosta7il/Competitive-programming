#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e10;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const long long MAX =  1000 + 5;

int t;
int n, p;
int a[21];
int main() {
	fast();
	cin >> t;

	while (t--){
		cin >> p >> n;
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			a[u] |= (1 << v);
		}
		int mx = 0;
		for (int i = 0; i < (1 << p); i++){
			int cnt = 0;
			for (int j = 0; j < 30;j++)
			if (i & (1 << j))
				cnt++;
			for (int j = 0; j < p; j++){
				if ((i & a[j]) == i){
					cnt++;
				}
			}
			mx = max(mx, cnt);
		}
		cout << mx << "\n";
	}


	return  0;
}
