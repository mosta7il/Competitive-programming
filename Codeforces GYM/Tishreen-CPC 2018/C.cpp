#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

 long long  OO = 1e17;
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
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 1000 * 1000  + 5;
int t;
int a[101][101];
int n, m , k;
int main() {
	fast();

	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> a[i][j];
				a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]);
			}
		}

		int best = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int h = n - i + 1; h >= 1; h--){
					for (int w = m - j + 1; w >= 1; w--){
						if (best >= h *w)
							break;
						int res = a[i + h - 1][j + w - 1] - a[i - 1][j + w - 1]
							- a[i + h - 1][j - 1] + a[i - 1][j - 1];
						if (res <= k){
							best = h * w;
						}
					}
				}
			}
		}
		cout << best << "\n";
	}
	return  0;
}
