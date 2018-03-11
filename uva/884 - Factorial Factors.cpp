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
long long ans[1000 * 1000 + 1];
int fun(long long x){
	vector<int> v;
	for (long long i = 2; i*i <= x; i++){
		while (x % i == 0){
			v.push_back(i);
			x /= i;
		}
	}
	if (x > 1)
		return (int)v.size() + 1;
	return (int)v.size();
}
int n;
int main(){
	fast();
	ans[0] = ans[1] = 0;
	for (int i = 2; i <= 1000 * 1000; i++){
		ans[i] = fun(i) + ans[i - 1];
	}

	while (cin >> n){
		cout << ans[n] << endl;
	}
	return 0;
}
