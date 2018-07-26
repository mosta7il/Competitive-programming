#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
const long long MAX = 200 * 1000 + 1;
int t;

int a[101];
int gcd(int a, int b) {
	while (b){ int r = a % b; a = b; b = r; }
	return a;
}

int main(){
	fast();
	cin >> t;
	cin.ignore();
	while (t--){

		string s; 
		getline(cin, s);
		stringstream ss(s);
		int idx = 0;
		int mx = 0;
		while (ss >> a[idx])idx++;
		for (int i = 0; i < idx; i++){
			for (int j = i + 1; j < idx; j++){
				mx = max(mx, gcd(a[i], a[j]));
			}
		}

		cout << mx << endl;
	}

	return 0;
}
