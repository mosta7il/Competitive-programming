/*
	- split the RAM Clusters into pieces of power 2.
	- sort programs increasingly
	- iterate over programs and try to assign it to as small as possible cluster

*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define ll long long
#define endl "\n"

const double PI = acos(-1.0);
const long double EPS = (1e-9);
const ll   OO = 1e18;
const ll   mod = 1e9 + 7;
int dcmp(long double x, long double y)
{
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	//std::ios_base::sync_with_stdio(0);
	//cin.tie(NULL); cout.tie(NULL);
}
const int MLOG = 30;
const int MAX = 10 * 100 * 1000 + 5;

int n, m;
vector< int> b, a;
int frq[32];

int  fun(int md){
	int cnt = 0;
	memset(frq, 0, sizeof frq);
	for (int i = 0; i < n; i++){
		
		for (int idx = 0; idx < 32; idx++){
			if ((1 << idx) & a[i]){
				frq[idx]++;
			}
		}
	}

	for (int i = 0; i< md; i++){
		bool ok = 0;
		for (int j = b[i]; j < 32; j++){
			if (frq[j]){
				frq[j]--;
				int rem = ((1 << j) - (1<<b[i]));
				for (int idx = 0; idx < 32; idx++){
					if ((1 << idx) & rem){
						frq[idx]++;
					}
				}
				ok = 1;
				break;
			}
		}
		if (ok)
			cnt++;
	}
	return cnt;
}
int main(){
	fast();
	scanf("%d%d", &n, &m);
	b.resize(m);
	a.resize(n);
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	for (int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	sort(b.begin(), b.end());	

	printf("%d\n", fun(m));

	return 0;
}
