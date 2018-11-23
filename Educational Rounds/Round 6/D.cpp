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
const int MAX = 1 * 100 * 1000 + 5;

int n, m;
int a[2001], b[2001];
int k; ll mn;
vector<int>v;
ll suma = 0, sumb = 0;
map<  ll, pair<int, int> > sa, sb;

void lazy(map<  ll, pair<int, int> >::iterator &it,
	int i , int j){

	if (it != sb.end()){
		if (abs(suma - sumb + 2ll * ((it->first) - (0ll+a[i] + a[j]))) < mn){
			k = 2;
			mn = abs(suma - sumb + 2ll * ((it->first) - (0ll + a[i] + a[j])));
			v.clear();
			v.push_back(i); v.push_back(it->second.first);
			v.push_back(j); v.push_back(it->second.second);
		}
	}
}
int main(){
	fast();

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		suma += a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> b[i];
		sumb += b[i];
	}
	k = 0;
	mn = abs(suma - sumb);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ll dif = abs(suma - sumb + 2ll * (b[j] - a[i]));
			if (dif < mn){
				k = 1;
				mn = dif;
				v.clear();
				v.push_back(i); v.push_back(j);
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m; j++){
			ll two = 0ll + b[i] + b[j];
			sb[two] = { i, j };
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			ll dif = suma - sumb - 2 *(0ll + a[i] + a[j]);
			auto it = sb.lower_bound(dif / 2);
			lazy(it,i , j);
			if (it != sb.begin()){
				it--;
				lazy(it, i , j);
			}
			dif *= -1;
			it = sb.lower_bound(dif / 2);
			lazy(it, i , j);
			if (it != sb.begin()){
				it--;
				lazy(it, i , j);
			}
		}
	}

	
	cout << mn << endl;
	cout << k << endl;
	for (int i = 0; i < v.size(); i += 2)
		cout << v[i]+1 << " " << v[i + 1]+1 << endl;
	return 0;
}
