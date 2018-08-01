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
int w[15];
int main(){
	fast();
	int cnt = 0;
	while (cin >> n&&n){
		if (cnt)
			cout << endl;
		cnt++;
		for (int i = 0; i < n; i++){
			cin >> w[i];
		}

		for (int a = 0; a < n - 5;a++)
		for (int b = a + 1; b < n - 4;b++)
		for (int c = b + 1; c < n - 3;c++)
		for (int d = c + 1; d < n - 2;d++)
		for (int e = d + 1; e< n - 1;e++)
		for (int f = e + 1; f < n; f++)
			cout << w[a] << " " << w[b] << " "
			<< w[c] << " " << w[d] << " "
			<< w[e] << " " << w[f] << endl;
	}
	return 0;
}
