#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

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
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 3 * 100 * 1000 + 5;

int n;
vector< int> odd, even;
int main() {
	fast();
	cin >> n;
	odd.resize(n, -1); even.resize(n, -1);
	int o = 1, e = 2;
	for (int i = 0; i < n; ++i){
		if (o >= n)break;
		odd[i] = o;
		odd[i + (n - o)] = o;
		o += 2;
	}
	for (int i = 0; i < n; i++){
		if (e >= n)break;
		even[i] = e;
		even[i + (n - e)] = e;
		e += 2;
	}

	for (int i = 0; i < n; i++){
		if (odd[i] == -1)cout << n << " ";
		else cout << odd[i] << " ";
	}
	for (int i = 0; i < n; i++){
		if (even[i] == -1)cout << n << " ";
		else cout << even[i] << " ";
	}
	cout << endl;
	return 0;
}
