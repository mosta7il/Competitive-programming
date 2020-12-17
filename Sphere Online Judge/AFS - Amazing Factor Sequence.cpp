#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e13
#define EPS 1e-10
#define MLOG 20
#define MAX 2* 1000 * 100 +2
const int mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int sums[1000 * 1000 + 1];
ll pre[1000 * 1000 + 1];
int main() {
	fast();
	
	for (int i = 1; i <= 1000 * 1000; i++){
		for (int j = i * 2; j <= 1000 * 1000; j += i)
			sums[j] += i;
	}
	pre[0] = pre[1] = 0;
	for (int i = 2; i <= 1000 * 1000; i++)
		pre[i] = pre[i - 1] + sums[i];

	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		cout << pre[n] << endl;
	}

	return 0;
}
