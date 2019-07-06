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
int t, n, k;
ll a[501];

bool valid(ll md){

	for (int i = 0; i < n;i++)
	if (a[i] > md)return 0;
	int cnt = 1;
	ll tot = 0;
	for (int i = n - 1; i >= 0; i--){
		if (tot + a[i] <= md)
			tot += a[i];
		else{
			cnt++;
			tot = a[i];
			if (cnt > k)
				return 0;
		}
	}
	return 1;
}

void build(ll md){
	int cnt = 1;
	ll tot = 0;
	vector<vector<int> > v(k, vector<int>());
	
	for (int i = n - 1; i >= 0; i--){
		if (tot + a[i] <= md)
			tot += a[i];
		else{
			cnt++;
			tot = a[i];
		}
		v[cnt - 1].push_back(a[i]);
		if (k - cnt == i){
			cnt++;
			tot = 0;
		}
	}
	for (int i = k - 1; i >= 0; i--){
		if (i != k - 1)
			cout << " / ";
		for (int j = int(v[i].size()) - 1; j >= 0; j--){
			if (j!= int(v[i].size() )-1)
				cout << " ";
			cout << v[i][j];
		}
	}
	cout << endl;
}
int main(){
	fast();
	cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		ll lo = 1, hi = 500e7, ans = -1;
		while (lo <= hi){
			ll md = lo + (hi - lo) / 2;
			if (valid(md)){
				ans = md;
				hi = md - 1;
			}
			else lo = md + 1;
		}
		//cout << ans << endl;
		build(ans);
	}
	return 0;
}
