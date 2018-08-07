#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const long long OO = 1e7;
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
const long long MAX = 100 * 1000 + 1;
int tree[4 * MAX];
int a[MAX];
int n, q;

void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = a[l];
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	build(left, l, md);
	build(right, md + 1, r);
	tree[cur] = min(tree[left], tree[right]);
}

int query(int cur, int l, int r, int x, int y){
	if (l >= x&& r <= y)
		return tree[cur];
	if (r < x || l > y)
		return INT_MAX;

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	return min(query(left, l, md ,x, y) , query(right, md + 1, r , x ,y));
}
int main(){
	fast();
	int t , cnt = 1;
	cin >> t;
	while (t--){
		cout << "Scenario #" << cnt++ << ":\n";
		cin >> n>> q;
		for (int i = 0; i < 4 * MAX; i++)
			tree[i] = INT_MAX;
		for (int i = 0; i < MAX; i++)
			a[i] = INT_MAX;

		for (int i = 1; i <= n; i++)
			cin >> a[i];
		build(1, 1, n);
		
		for (int i = 0; i < q; i++){
			int x, y;
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << endl;
		}
	}
	return 0;
}
