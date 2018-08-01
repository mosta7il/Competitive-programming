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
bool row[15], ld[31], rd[31];
char g[16][16];
int ans;

void back(int c){
	if (c == n){
		ans++;
		return;
	}

	for (int r = 0; r < n; r++){
		if (g[r][c] != '*' && !row[r] && !rd[r + c] && !ld[r - c + n - 1]){
			row[r] = ld[r - c + n - 1] = rd[r + c] = 1;
			back(c + 1);
			row[r] = ld[r - c + n - 1] = rd[r + c] = 0;
		}
	}
}
int main(){
	fast();
	int cnt = 1;
	while (cin >> n&&n){
		cout << "Case " << cnt++ << ": ";

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cin >> g[i][j];
		}
		back(0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
