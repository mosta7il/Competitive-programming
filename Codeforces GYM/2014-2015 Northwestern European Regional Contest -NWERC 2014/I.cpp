#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const long double EPS = (1e-9);
const long double PI = acos(-1);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

long long  OO = 1e17;
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
const long long MAX = 100 * 1000 + 5;
int n;
long long L;
long long dist[15][15];

int main() {
	fast();
	cin >> n >> L;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> dist[i][j];
		}
	}
	int h = (n - 2) / 2;
	for (int i = 1; i < n; i++){

		for (int j = 0; j < (1 << n); j += 2){
			if (j &(1 << i))continue;
			if (__builtin_popcount(j) != h)continue;
			vector<int>v, vv;
			set< long long > mp;

			v.push_back(0); vv.push_back(0);
			for (int r = 1; r < n; r++){
				if (r == i)
					continue;
				if (j & (1 << r))
					v.push_back(r);
				else vv.push_back(r);
			}
			v.push_back(i); vv.push_back(i);
			do{
				long long sum = 0;
				for (int x = 0; x < ((int)v.size()) - 1; x++){
					sum += dist[v[x]][v[x + 1]];
				}
				if (sum > L)continue;
				mp.insert(sum);
			} while (next_permutation(v.begin() + 1, v.end() - 1));


			do{
				long long sum = 0;
				for (int x = 0; x < ((int)vv.size()) - 1; x++){
					sum += dist[vv[x]][vv[x + 1]];
				}
				if (sum > L)continue;
				if (mp.find(L - sum) != mp.end()){
					cout << "possible\n";
					return 0;
				}

			} while (next_permutation(vv.begin() + 1, vv.end() - 1));
		}
	}
	cout << "impossible\n";
	return  0;
}
