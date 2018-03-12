#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("E:\\Programming\\Problem Solving\\inout files\\input.txt", "r", stdin);
	freopen("E:\\Programming\\Problem Solving\\inout files\\output.txt", "w", stdout);
#endif
}
int n;

int a[100 * 1000 + 2], b[100 * 1000 + 2];

int main(){
	fast();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int lo = 0, hi = n - 1, cnt = 0;
	while (lo <= hi){
		if (lo == hi){
			if (a[lo] > cnt)
			b[a[lo] - cnt]++;;
		}
		else{
			if (a[lo] > cnt)
				b[a[lo] - cnt]++;
			if (a[hi] > cnt)
				b[a[hi] - cnt]++;
			cnt++;
		}
		lo++; hi--;
	}
	int mn = INT_MAX;
	for (int i = 1; i <= 100 * 1000; i++){
		mn = min(mn, n - b[i]);
	}
	cout << mn << endl;
	return 0;
}
