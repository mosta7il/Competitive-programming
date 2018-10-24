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
const long long MAX = 50000 + 1;
int n, m;
int a[MAX];
struct node{
	int best, bestL, bestR;
	int sum;
}tree[4 * MAX];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur].best = tree[cur].bestL = tree[cur].bestR = tree[cur].sum = a[l];
		return;
	}

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	build(left, l, md);
	build(right, md + 1, r);
	node one = tree[left], two = tree[right];
	tree[cur].best = max(one.best, max(two.best, one.bestR + two.bestL));
	tree[cur].sum = one.sum + two.sum;
	tree[cur].bestL = max(one.bestL, one.sum + two.bestL);
	tree[cur].bestR = max(two.bestR, two.sum + one.bestR);
}

node query(int cur, int l, int r, int x, int y){
	if (x <= l && y >= r)
		return tree[cur];

	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;

	if (md >= y){
		return query(left, l, md, x, y);
	}
	else if (md < x){
		return query(right, md + 1, r, x, y);
	}
	else{
		node one = query(left, l, md, x, y);
		node two = query(right, md + 1, r, x, y);
		node three;
		three.best = max(one.best, max(two.best, one.bestR + two.bestL));
		three.sum = one.sum + two.sum;
		three.bestL = max(one.bestL, one.sum + two.bestL);
		three.bestR = max(two.bestR, two.sum + one.bestR);
		return three;
	}
}
int main(){
	fast();
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}

	build(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++){
		int l, r; cin >> l >> r;
		node ret = query(1, 1, n, l, r);
		cout << ret.best << endl;
	}
	return 0;
}
