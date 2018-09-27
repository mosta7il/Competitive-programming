#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-11);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e9;
const long long mod = 1e9 + 7;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ld long double
void fast(){
#ifndef ONLINE_JUDGE
	freopen("E:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("E:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("point3.in", "r", stdin);
	//freopen("point3.out", "w", stdout);
}
const long long MAX = 10 * 1000 + 5;

int n;
map<string, int> mp, cnt;
int main() {
	fast();
	cin >> n;
	string s;
	int res = 0;
	for (int i = 0; i < n; i++){
		cin >> s;
		mp[s]++;
	}
	for (int i = 0; i < n; i++){
		cin >> s;
		cnt[s]++;
	}
	for (auto e : mp){
		res += (min(e.second, cnt[e.first]));
	}
	cout << res << endl;
	return  0;
}
