#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int main(){
	vector<int > in;
	int n, m; bool f = 0;
	cin >> n >> m;
	pair<int, int> *a = new pair<int, int>[m];
	int st [101];
	memset(st, 0, sizeof st);
	for (int i = 0; i < m; i++){
		cin >> a[i].first >> a[i].second;
		st[a[i].first]++; st[a[i].second]++;
	}
	int cnt1 = 0, cnt2 = 2;
	while (cnt2 > 0){
		cnt2 = 0; f = 0;
		for (int i = 1; i <= n; i++){
			if (st[i] == 1){
				in.push_back(i);
				st[i] = 0;
				cnt2++;
				f = 1;
			}
		}
		if (f){
			cnt1++;
		}
		for (int q = 0; q < in.size();q++)
		for (int i = 0; i < m; i++){
			if (a[i].first == in[q] || a[i].second == in[q]){
				a[i].first = a[i].second = 0;
			}
		}
		in.clear();
		memset(st, 0, sizeof st);
		for (int i = 0; i < m; i++){
			st[a[i].first]++;
			st[a[i].second]++;
		}
	}

	cout << cnt1 << endl;
	return 0;
}
