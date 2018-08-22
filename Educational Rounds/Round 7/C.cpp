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
const long long MAX = 2 * 100 * 1000 + 5;

int n, m;
int a[MAX];
pair<int, int>tree[4 * MAX];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = { l , l };
		return;
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	build(left, l, md);
	build(right, md + 1, r);
	tree[cur].first = (a[tree[left].first] <= a[tree[right].first]) ? tree[left].first : tree[right].first;
	tree[cur].second = (a[tree[left].second] >= a[tree[right].second]) ? tree[left].second : tree[right].second;
}

pair<int, int> query(int cur, int l, int r, int x, int y){
	if (x <= l&&y >= r)
		return tree[cur];
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	if (y <= md){
		return query(left, l, md, x, y);
	}else if(md < x){
		return query(right, md + 1, r, x, y);
	}
	else{
		pair<int, int>one = query(left, l, md, x, y);
		pair<int, int> two = query(right, md + 1, r, x, y);
		return make_pair((a[one.first] <= a[two.first])?one.first:two.first, (a[one.second]>= a[two.second]) ?one.second:two.second);
	}
	
}
int main() {
	fast();
	cin >> n >> m;
	for (int i = 1; i < MAX; i++)
		a[i] = 1e6 + 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	build(1, 1, n);

	for (int i = 0; i < m; i++){
		int l, r, x;
		cin >> l >> r >> x;
		pair<int, int> ans = query(1, 1, n, l, r);
		if (a[ans.first] != x)
			cout << ans.first << endl;
		else if (a[ans.second] != x)
			cout << ans.second << endl;
		else cout << -1<< endl;
	}
	return 0;
}
