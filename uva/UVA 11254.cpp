/*
    If we can put number N as a sum of K consecutive integers then:
    ->  X + (X+1) + (X+2) + .... + (X+K-1) = N
    ->  KX + (K * (K-1))/2 = N
     So we can iterate all possible K and choose the largest one that satisfy the equ. above
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
const int MAX = 10 * 100 * 1000 + 5;
int n;

int main(){
	fast();
	while (cin >> n && (n >= 0)){

		int beg = 0, howmany = 0;
		// Try to make i consecutive number
		
		for (int i = 1; i <= 1000 * 100; i++){

			ll rem = n - ((0ll + i) * (i - 1)) / 2;
			if (rem > 0 && rem % i == 0){
				howmany = i;
				beg = rem / i;
			}
		}

		cout << n << " = ";
		cout << beg << " + ... + " << beg + howmany - 1 << endl;
	}

	return 0;
}
