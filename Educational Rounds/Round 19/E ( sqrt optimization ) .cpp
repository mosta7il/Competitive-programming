/*
	We can preprocess soultion for K <= sqrt(N) .
	That would take O ( N * sqrt( N ) ) Time and memory.
	For K > sqrt(N) , we can just simulate it . Each query would take less than sqrt(N) steps.
	
	Total Complexity O ( N * sqrt( N )  + N * sqrt( N ) ) = O ( N * sqrt( N ) )
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-15);
const ll   OO = 1e6;
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
int n, q;
int a[MAX];

int pre[MAX][320];

int main(){
	fast();
	cin >> n;

	int root = sqrt(n) + 1;

	for (int i = 0; i < n; i++)
		cin >> a[i];


	// O ( N * sqrt(N) )
	for (int k = 1; k <= root; k++){
		for (int i = n - 1; i >= 0;i--){
			int to = i + k + a[i];
			if (to >= n)
				pre[i][k] = 1;
			else{
				pre[i][k] = pre[to][k] + 1;
			}
		}
	}

	cin >> q;
	while (q--){
		int p , k;
		cin >> p>>k;
		p--;
		if (k <= root){
			cout << pre[p][k] << endl;
		}
		else{
			int cnt = 0;
			while (p < n){
				p = p + k + a[p];
				cnt++;
			}
			cout << cnt << endl;
		}
	}

	return 0;
}
