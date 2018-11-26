/*

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e6;
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
const int MAX = 2 * 100 * 1000 + 5;
int n;
pair< int,int> a[MAX];

int fun(ll md){

	ll sum = 0;

	for (int i = 0; i < n; i++){
		if (a[i].second == 1){
			if (sum + md < 1900)
				return 1;
		}
		else{
			if (sum + md >= 1900)
				return 2;
		}
		sum += a[i].first;
	}
	return 0;
}
int main(){
	fast();
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}



	ll lo = -1e9, hi = 1e9, ans = -1e12;
	while (lo <= hi){
		ll md = (lo + hi) >> 1;
		int ret = fun(md);
		if (ret == 0){
			ans = md;
			lo = md + 1;
		}
		else if(ret == 2){
			hi = md - 1;
		}
		else{
			lo = md + 1;
		}
	}

	if (ans == -1e12){
		cout << "Impossible\n";
	}
	else if (ans == 1e9){
		cout << "Infinity\n";
	}
	else cout << sum + ans << endl;
	return 0;
}
