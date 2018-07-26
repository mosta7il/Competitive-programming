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

long long n;
int sumOfDig(int x){
	int sum = 0;
	while (x){ sum += x % 10; x /= 10; }
	return sum;
}

int pf(int x){
	int xx = x;
	int sum = 0;
	for (long long i = 2; i*i <= x; i++){
		while (x%i == 0){
			sum += sumOfDig(i);
			x /= i;
		}
	}
	if (xx == x){
		return 0;
	}
	if (x > 1)sum += sumOfDig(x);
	return sum;
}
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		n++;

		while (pf(n) != sumOfDig(n))n++;
		cout << n << endl;
		
	}
	
	return 0;
}
