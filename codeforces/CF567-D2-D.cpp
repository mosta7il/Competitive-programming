#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
using namespace std;

const long long OO = 1e9;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, k, a, m;
int b[2 * 1000 * 100 + 1];
bool fun(int md){
	int tmp[2 * 1000 * 100 + 1] = { 0 };
	for (int i = 0; i <= md; i++)
		tmp[b[i]] = 1;

	int cnt = 0, tt = 0;
	for (int i = 1; i <= n; i++){
		if (tmp[i] == 0){
			tt++;
		}
		else{
			tt = 0;
		}
		if (tt == a){
			cnt++;
			tt = -1;
		}
	}
	return (cnt >= k);
}
int main(){
	fast();

	cin >> n >> k >> a >> m;
	for (int i = 0; i < m; i++){
		cin >> b[i];
	}

	int lo = 0, hi = m - 1 , ans = -2;
	while (lo <= hi){
		int md = lo + (hi - lo) / 2;
		if (!fun(md)){
			hi = md - 1;
			ans = md;
		}
		else{
			lo = md + 1;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
