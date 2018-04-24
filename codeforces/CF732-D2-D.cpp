#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e9+5;
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
int n, m;
int a[100 * 1000 + 1], d[100 * 1000 + 1];
int tmp[1000 * 100 + 1];
bool fun(int md){
	memset(tmp, 0, sizeof tmp);
	
	for (int i = 1; i <= md; i++)
		tmp[a[i]]++;
	int cnt = 0 , dif = 0;
	for (int i = 1; i <= md; i++){
		if (a[i] == 0)cnt++;
		else {
			if (tmp[a[i]] == 1){
				if (cnt >= d[a[i]]){
					cnt -= d[a[i]];
					dif++;
				}
				else return 0;
			}
			else cnt++;
			tmp[a[i]]--;
		}
	}
	return dif == m;
}
int main(){
	fast();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> d[i];

	int lo = 1, hi = n , ans = -1;
	while (lo <= hi){
		int md = (lo + hi) >> 1;
		if (fun(md)){
			ans = md;
			hi = md - 1;
		}
		else lo = md + 1;
	}
	cout << ans << endl;
	return 0;
}
