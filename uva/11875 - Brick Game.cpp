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

int t, n;
int a[12];

int main(){
	fast();
	cin >> t;
	int cnt = 1;
	while (t--){
		cout << "Case " << cnt++ << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n; i++){
			int ocnt = 0, ycnt = 0;
			for (int j = 0; j < n; j++){
				ocnt += (a[i] > a[j]);
				ycnt += (a[i] < a[j]);
			}
			if (ocnt == ycnt){
				cout << a[i] << endl;
				break;
			}
		}
	}
	return 0;
}
