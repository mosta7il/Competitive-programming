#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;

int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX = 5 * 100 * 1000 + 5;
int n;
char g[4][101][101];
char all[201][201];
int per[] = { 0, 1, 2, 3 };


int main() {
	fast();
	cin >> n;
	for (int k = 0; k < 4; k++){
		for (int i = 0; i < n;i++)
			for (int j = 0; j < n; j++)
				cin >> g[k][i][j];
	}
	int mn = OO;
	do{
		
		for (int i = 0 , r = 0; i < n; i++ , r++){
			for (int j = 0 , c = 0 ; j < n; j++,c++){
				all[r][c] = g[per[0]][i][j];
			}
		}
		for (int i = 0, r = 0; i < n; i++, r++){
			for (int j = 0, c = n; j < n; j++, c++){
				all[r][c] = g[per[1]][i][j];
			}
		}
		for (int i = 0, r = n; i < n; i++, r++){
			for (int j = 0, c = 0; j < n; j++, c++){
				all[r][c] = g[per[2]][i][j];
			}
		}
		for (int i = 0, r = n; i < n; i++, r++){
			for (int j = 0, c = n; j < n; j++, c++){
				all[r][c] = g[per[3]][i][j];
			}
		}
		char cur = all[0][0], curr = '1' - all[0][0] + '0';
		int cnt = 0, cntt = 0;
		for (int i = 0; i < 2 * n; i++){
			for (int j = 0; j < 2 * n; j++){
				if (all[i][j] != cur)
					cnt++;
				if (all[i][j] != curr)
					cntt++;
				cur = '1' - cur + '0';
				curr = '1' - curr + '0';
			}
			cur = '1' - cur + '0';
			curr = '1' - curr + '0';
		}
		mn = min(mn, min(cnt, cntt));
		
	} while (next_permutation(per, per + 4));

	cout << mn << endl;
	return 0;
}
