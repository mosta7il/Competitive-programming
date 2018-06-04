#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e17;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int MAX =1000 *1000+ 5;
int n, k;
int frq[MAX];
int a[MAX / 2];
int main(){
	fast();
	cin >> n >> k;

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int j = 0, cnt = 0;
	int mx = 0;
	int l = -1, r = -1;
	for (int i = 0; i < n; i++){

		while (j < n&&cnt <=k){
			if (frq[a[j]] == 0){
				if (cnt == k)
					break;
				cnt++;
			}
			frq[a[j]]++;
			j++;
		}
		if (mx < (j - i)){
			mx = j - i;
			l = i, r = j;
		}
		frq[a[i]]--;
		if (frq[a[i]] == 0)
			cnt--;

	}
	l++;
	cout << l << " " << r << endl;
	return 0;
}
