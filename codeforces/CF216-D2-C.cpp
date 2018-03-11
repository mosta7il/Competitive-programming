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
int n, m, k;
int key[1000 * 1000 + 1], worker[1000 * 1000 + 1];
vector<int> ans;

void add(int day){
	int cnt = 0;
	bool f = 0;
	ans.push_back(day);
	for (int i = day; i <= 10000;i++ ){
		if (!f){
			worker[i]++;
			cnt++;
			if (cnt + 1 <= n){
				key[i] = 1;
			}
		}
		else{
			i += m-1;
			f = 0;
		}
		if (cnt == n){
			cnt = 0;
			f = 1;
		}
	}
}
int main(){
	fast();
	cin >> n >> m >> k;


	for (int i = 1; i <= 10000; i++){

		while (worker[i] < k){
			add(i);
		}
		if (!key[i])
			add(i);
	}

	cout << ans.size() << endl;
	for (auto e : ans){
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
