#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int MLOG = 35;
const int MAX = 2 * 100 * 1000 + 5;
int n, q , root  , numberOfBuckets;

int a[MAX];

vector<int> bu[401];

int main(){
	fast();
	cin >> n >> q;
	root = sqrt(n);
	numberOfBuckets = (n + root - 1) / root;

	for (int i = 0; i < n; i++){
		cin >> a[i];
		bu[i / root].push_back(a[i]);
	}

	for (int i = 0; i < numberOfBuckets; i++){
		sort(bu[i].begin(), bu[i].end());
	}
	char c;
	int l, r, x, ans;
	while (q--){
		cin >> c;
		if (c == 'C'){
			cin >> l >> r >> x;
			--l, --r;
			ans = 0;
			for (int i = l; i <= r; i++){
				if (i %root == 0 && i + root - 1 <= r){
					ans += (upper_bound(bu[i / root].begin(), bu[i / root].end() , x) - bu[i / root].begin());
					i += root - 1;
				}
				else {
					ans += (a[i] <= x);
				}
			}
			cout << ans << "\n";
		}
		else{
			cin >> l >> x;
			--l;
			int idx = l / root;
			bu[idx].clear();
			a[l] = x;
			for (int i = idx * root; i < ((idx + 1)*root) && i < n; i++){
				bu[idx].push_back(a[i]);
			}
			sort(bu[idx].begin(), bu[idx].end());
		}
	}
	return 0;
}
