#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e6;
const long long mod = 1e9 + 7;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int n;
set< pair<int , int> > a[3];

int main() {
	fast();
	cin >> n;

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[x % 3].insert({ x, i + 1 });
	}
	int cur = 0;
	vector<int>ans;
	while (ans.size() < n){
		if (a[cur % 3].size() == 0){
			cout << "Impossible\n";
			return 0;
		}
		auto it = a[cur % 3].lower_bound({ cur, 0 });
		if (it == a[cur % 3].end()){
			it--;
		}
		while (it!=a[cur%3].begin()&&(*it).first > cur){
			it--;
		}
		if ((*it).first > cur){
			cout << "Impossible\n";
			return 0;
		}
		auto t = *it;
		a[cur % 3].erase(it);
		cur = t.first + 1;
		ans.push_back(t.second);
	}

	cout << "Possible\n";
	for (auto e : ans)
		cout << e << " ";
	cout << endl;
	return 0;
}
