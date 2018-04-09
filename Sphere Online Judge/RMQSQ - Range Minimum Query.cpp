#define _CRT_SECURE_NO_WARNINGS
// Do not work at uva or spoj..
#include<bits\stdc++.h> 
using namespace std;

const long long OO = 1000;
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
const int MAX = 1e5 + 1;
int n, m;

int tree[MAX * 16];
int a[MAX];

void build(int cur, int l, int r){
	if (l == r){
		tree[cur] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	int left = cur * 2;
	int right = left + 1;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = min(tree[left], tree[right]);
}

int  query(int cur, int l, int r, int x, int y){
	if (r<x || l>y)
		return 1e9;
	if (x <= l&& y >= r)
		return tree[cur];
	int mid = (l + r) / 2;
	int left = cur * 2;
	int right = left + 1;
	return min(query(left, l, mid, x, y),
		query(right, mid + 1, r, x, y));
}
int main(){
	fast();
	cin >> n; 
	memset(a, 1e9, sizeof a);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++){
		int l, r; cin >> l >> r;
		l++, r++;
		cout << query(1, 1, n, l, r) << endl;
	}
	
	return 0;
}
