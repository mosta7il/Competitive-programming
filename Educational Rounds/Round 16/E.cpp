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
const long long MAX = 1000 * 1000 * 10 + 5;
int n;
long long x, y;

long long mem[MAX];


int main() {
	fast();
	
	cin >> n >> x >> y;
	mem[1] = x;
	for (int i = 2; i <= 1000 * 1000 * 10; i++){
		mem[i] = mem[i - 1] + x;
		if (i % 2)
			mem[i] =  min(mem[i], mem[i / 2] + x + y);
		else mem[i] = min(mem[i], mem[i / 2] + y);
		mem[i - 1] = min(mem[i - 1], mem[i] + x);
	}

	cout << mem[n] << "\n";

	return 0;
}
