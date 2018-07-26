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
const long long MAX = 20 *1000 * 1000 + 1;
bool prime[MAX];
vector< int > v;
void sieve(){
	prime[0] = prime[1] = 1;
	for (long long i = 2; i*i <= MAX; i++){
		if(!prime[i])
		for (long long j = i*i; j < MAX; j += i)
			prime[j] = 1;
	}
}
int main(){
	fast();
	sieve();
	for (int i = 2; i < MAX - 2; i++){
		if (!prime[i] && !prime[i + 2])
			v.push_back(i);
	}

	int n;
	while (cin >> n){
		cout << "(" << v[n - 1] << ", " << v[n - 1] + 2 << ")\n";
	}
	return 0;
}
