/*
	P( Friend i buy something | exactly r friend buy something )

	P (A | B) = P(A AND B) / P(B).

	P(B) = sum of probabilities of all N-bit strings with r ones.

	P(Ai AND B) = sum of probabilities of all N-bit strings with r ones, AND 
				  the Ith bit is one ( Ith friend buy something ).
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define endl '\n'
#define ld long double
#define ll long long
#define PI acos(-1.0)
#define OO 1e9
#define EPS 1e-12
#define MLOG 20
#define MAX  2* 100  * 1000+5
const ll mod = 1e9 + 7;

ll dcmp(long double x, long double y){
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);
#endif

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n, r;
double g[22];
double a[22];
int main(){
	fast();
	int tc = 1;
	cout << fixed << setprecision(6);
	while (cin >> n >> r&&n){
		cout << "Case " << tc++<<":" << endl;
		memset(a, 0, sizeof a);

		for (int i = 0; i < n; i++)
			cin >> g[i];

		double B = 0;
		for (int mask = 0; mask < (1 << n);mask++){
			int cnt = 0;
			for (int i = 0; i < n; i++){
				if ((mask & (1 << i))){
					cnt++;
				}
			}
			if (cnt == r){
				double tt = 1.0;
				for (int i = 0; i < n; i++){
					if ((mask & (1 << i))){
						tt *= g[i];
					}
					else tt *= (1 - g[i]);
				}
				B += tt;
				for (int i = 0; i < n ; i++){
					if ((mask & (1 << i))){
						a[i] += tt;
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++){
			cout << a[i] / B << endl;
		}

	}

	return 0;
}
