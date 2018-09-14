#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


const long long OO = 1e8;
const long long mod = 1e9 + 7;
const long double EPS = (1e-12);
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

const long long MAX = 3 * 1000 * 1000 + 5;
int n, m;
long long cum[MAX];
int a[MAX / 3], cnt[MAX];

int main() {
	fast();
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}

	for (int i = 1; i < MAX; i++){
		if (!cnt[i])continue;
		for (int j = i; j < MAX; j += i){
			if (j / i != i) cum[j] += (1ll * cnt[i]) * cnt[j / i];
			else cum[j] += (1ll * cnt[i]) * (cnt[i] - 1);
		}
	}
	for (int i = 1; i < MAX; i++)
		cum[i] += cum[i - 1];

	cin >> m;
	for (int i = 0; i < m; i++){
		int x; cin >> x;
		cout << n * 1ll *(n-1)  - cum[x - 1] << "\n";
	}

	return 0;
}
