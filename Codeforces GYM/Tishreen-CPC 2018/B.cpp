#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

const  long long  OO = 1e17;
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
const long long MAX = 1000 * 1000  + 5;

int t;
int n;
int lp[MAX] , p[MAX] , arr[MAX];
map<int, int>mp;
void sieve(){
	for (int i = 2; i < MAX; i++)lp[i] = i;
	for (long long i = 2;  i * i <= MAX; i++){
		if (!p[i]){
			for (long long j = i * i; j < MAX; j += i){
				if (lp[j] == j)
					lp[j] = i;
				p[j] = 1;
			}
		}
	}

}

map < int, bool > a[MAX];
int main() {
	fast();
	sieve();
	for (int i = 2; i < MAX; i++){
		int cur = i;
		while (lp[cur] != cur){
			a[i][lp[cur]] = 1;
			cur /= lp[cur];
		}
		a[i][lp[cur]] = 1;
	}
	cin >> t;
	while (t--)	{
		mp.clear();
		cin >> n;
		for (int i = 0; i < n; i++){
			 cin >>arr[i];
			 for (auto e : a[arr[i]]){
				 mp[e.first]++;
			 }
		}
		int ans = 0;
		for (auto e : mp){
			ans += (int)ceil(e.second / 3.0);
		}
		cout << ans << "\n";
	}
	
	return  0;
}
