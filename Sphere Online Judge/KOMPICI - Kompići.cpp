/*


*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e17
#define EPS 1e-12
#define MLOG 20
#define MAX 10 * 100 * 100+5
const int mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
set<int>s;
int a[MAX];

int convert(string x){
	int ret = 0;
	for (int i = 0; i < x.size(); i++){
		int d = x[i] - '0';
		ret |= (1 << d);
	}
	return ret;
}
int main() {
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		string x; cin >> x;
		a[convert(x)]++;
	}
	ll ans = 0;
	for (int i = 0; i < 2000; i++){
		for (int j = i; j < 2000; j++){
			if (i == j){
				ans += (1ll * a[i] * (a[i] - 1) / 2);
			}
			else if (i & j){
				ans += (1ll * a[i] * a[j]);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
