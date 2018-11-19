/*
	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-9);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;

int dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
        cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;
int n, k;
vector < pair< int, int > > a;
vector< int > ans ;
int main(){
	fast();

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int l, r; cin >> l >> r;
		a.push_back({ l,-1});
		a.push_back({ r,1 });
	}

	int cnt = 0;

	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++){
		if (cnt - a[i].second == k && a[i].second == -1){
			if (ans.size() >= 1 && ans.back() == a[i].first)
				ans.pop_back();
			else ans.push_back(a[i].first);
		}
		else if (cnt == k && a[i].second == 1){
			ans.push_back(a[i].first);
		}
		cnt -= a[i].second;
	}
	cout << ans.size()/2 << endl;
	for (int i = 0; i < ans.size(); i += 2){
		cout << ans[i] << " " << ans[i + 1] << endl;
	}
	return 0;
}
