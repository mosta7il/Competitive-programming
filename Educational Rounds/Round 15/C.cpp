/*


*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define EPS 1e-12
#define MLOG 20
#define MAX 1 * 100 * 1000+5
const int mod = 998244353;

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
int n, m;
int a[MAX], b[MAX];

bool valid(ll md){

	int idx = 0, i = 0;
	while(idx<m && i <n){
		if (a[i] >= b[idx] - md && a[i] <= b[idx] + md)
			i++;
		else if (a[i] >= b[idx] - md)
			idx++;
		else	return 0;
	}
	return (i == n);

}

int main(){
	fast();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	ll lo = 0, hi = 2e9, ans = 1e18;
	while (lo <= hi){
		ll md = lo + (hi - lo) / 2;

		if (valid(md)){
			ans = md;
			hi = md - 1;
		}
		else lo = md + 1;
	}
	cout << ans << endl;
	return 0;
}
