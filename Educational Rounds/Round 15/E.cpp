#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>


using namespace std;

typedef complex<double> Point;


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
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 1 * 100 * 1000 + 5;

int n; long long k;
int a[MAX];
long long w[MAX];

int g[MAX][34];
long long sum[MAX][34];
long long mn[MAX][34];
int main() {
	fast();

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int u; cin>> u; 
		a[i] = u;
		g[i][0] = u;
	}
	for (int i = 0; i < n; i++){
		cin >> w[i];
		sum[i][0] = w[i];
		mn[i][0] = w[i];
	}

	for (int s = 1; (1ll << s) <= k; s++){

		for (int i = 0; i < n; i++){
			
			sum[i][s] = sum[i][s - 1] + sum[g[i][s - 1]][s - 1];
			mn[i][s] = min(mn[i][s - 1], mn[g[i][s - 1]][s - 1]);
			g[i][s] = g[g[i][s - 1]][s - 1];
		}
	}

	vector<int>v;
	int idx = 0;
	while (idx < 64){
		if (k & (1ll << idx))
			v.push_back(idx);
		idx++;
	}
	
	for (int i = 0; i < n; i++){
		long long ss, mm;
		ss = 0, mm = 1e9;
		int cur = i;
		for (auto e : v){
			ss += sum[cur][e];
			mm = min(mm, mn[cur][e]);
			cur = g[cur][e];
		}
		cout << ss << " " << mm << "\n";
	}

	return 0;
}
