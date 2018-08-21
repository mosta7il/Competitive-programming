#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef complex<double> Point;

const long long OO = 1e9;
const long long mod = 1e9 + 7;
const long double EPS = (1e-18);
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };


void fast(){
#ifndef ONLINE_JUDGE
	freopen("F:\\solving\\input.txt", "r", stdin);
	freopen("F:\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

}
const long double PI = 3.1415926535897932384626433832795028841971693993751;
const long long MAX = 3 * 100 * 1000 + 5;

int n;
int a[MAX];
vector< pair<int, int> > ans;
map<int, int>mp;

int main() {
	fast();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int start = 0;
	for (int i = 0; i < n; i++){
		mp[a[i]]++;
		if (mp[a[i]] > 1){
			ans.push_back({ start, i });
			mp.clear();
			start = i + 1;
		}
	}

	if (ans.size() == 0){
		return cout << -1 << endl, 0;
	}
	else{
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++){
			if (i == ans.size() - 1)
				cout << ans[i].first + 1 << " " << n << "\n";
			else cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
		}
	}
	return 0;
}
