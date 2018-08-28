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
int n, m;
int a[MAX], b[MAX];

bool fun(long long md){

	set< pair< long long, long long > > p;
	for (int i = 0; i < m; i++){
		p.insert({ b[i] - md, b[i] + md });
	}
	
	for (int i = 0; i < n; i++){
		while (p.size() >0 &&(*(p.begin())).second < a[i])
			p.erase(p.begin());
		if (p.size() == 0)
			return 0;
		if (a[i] < (*(p.begin())).first)
			return 0;
	}
	return 1;
}

int main() {
	fast();

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++){
		cin >> b[i];
	}

	long long lo = 0, hi = 2e9, ans = -1;
	while (lo <= hi){
		long long md = lo + hi >> 1;
		if (fun(md)){
			hi = md - 1;
			ans = md;
		}
		else lo = md + 1;
	}
	cout << ans << endl;
	return 0;
}
